#!/bin/bash

secret="abcd1234client"
ip_client="192.168.1.113/24"

usage_(){
[ -z $@ ]&&{
	echo "Usage: sudo $0 "
	exit 0
}
}

install_freeradius(){
	sudo apt-get install freeradius make
}

turnoff_proxy(){
	sudo sed -i "s/proxy_requests  = yes/proxy_requests = no/g" /etc/freeradius/radiusd.conf
}


client_conf(){
	sudo mv /etc/freeradius/clients.conf /etc/freeradius/clients.conf_org

sudo cat <<EOF > /tmp/clients.conf
client ${ip_client} {
        secret = $secret
        require_message_authenticator = yes
}
EOF
sudo mv /tmp/clients.conf /etc/freeradius/clients.conf
}

eap_config(){
[ -f /etc/freeradius/eap.conf_org ]||{
	sudo mv /etc/freeradius/eap.conf /etc/freeradius/eap.conf_org
}
[ -d /tmp/radiusd ]|| mkdir /tmp/radiusd
cat << EOF > /tmp/eap.conf
eap {
default_eap_type = tls
timer_expire = 60
ignore_unknown_eap_types = no
cisco_accounting_username_bug = no
max_sessions = 4096
tls {
	certdir = \${confdir}/certs
	cadir = \${confdir}/certs
	private_key_password = $secret
	private_key_file = \${certdir}/server.key
	certificate_file = \${certdir}/server.pem
	CA_path = \${cadir}
	CA_file = \${cadir}/ca.pem
	dh_file = \${certdir}/dh
	random_file = /dev/urandom
	cipher_list = "HIGH"
	make_cert_command = "\${certdir}/bootstrap"
	ecdh_curve = "prime256v1"
cache {
	enable = no # Optionally enable
	lifetime = 24 # hours
	max_entries = 255
}
verify {
	tmpdir = /tmp/radiusd
	client = "/usr/bin/openssl verify -CAfile \${..CA_file} %{TLS-Client-Cert-Filename}"
}
ocsp {
	enable = no # optionally enable
	override_cert_url = yes
	url = "http://127.0.0.1/ocsp/"
}
}
ttls {
	default_eap_type = md5
	copy_request_to_tunnel = no
	use_tunneled_reply = no
	virtual_server = "inner-tunnel"
}
}
EOF
sudo mv /tmp/eap.conf /etc/freeradius/eap.conf
}

disable_default_servers(){
	sudo rm -rf /etc/freeradius/sites-enabled/*

cat <<EOF > /tmp/mynetwork
######################################################################
authorize {
	preprocess
	eap {
		ok = return
	}
	expiration
	logintime
}

authenticate {
	eap
}

preacct {
	preprocess
	acct_unique	
	suffix
	files
}

accounting {
	detail
	unix
	radutmp
	exec
	attr_filter.accounting_response
}

session {
	radutmp
}

post-auth {
	exec
	Post-Auth-Type REJECT {
		attr_filter.access_reject
	}
}

pre-proxy {

}

post-proxy {
	eap
}
EOF
	sudo mv /tmp/mynetwork /etc/freeradius/sites-available/mynetwork
	sudo ln -s /etc/freeradius/sites-available/mynetwork /etc/freeradius/sites-enabled/mynetwork
}

testing_freeradius(){
	sudo service freeradius stop
	sudo freeradius -X
}

prepare_make_certs(){
	cd /etc/freeradius/certs/
	rm *.pem
	rm *.key
	[ -d /var/certs ]||{
		mkdir /var/certs
		mkdir /var/certs/freeradius
		chgrp ssl-cert /var/certs/freeradius
		chmod 710 /var/certs/freeradius
		cp /usr/share/doc/freeradius/examples/certs/* /var/certs/freeradius/
	}
	cd /var/certs/freeradius/
	rm bootstrap
	chmod 600 *
	make destroycerts
	make index.txt
	make serial
	make dh
}


build_certs(){
	local ca_pass="abcd1234client"
	local server_pass="abcd1234client"
	local client_pass="abcd1234client"
	local default_md="sha1"

sed_(){
	local pass=$1
	local file=$2
	local dfmd=$3
	sed -i "s/input_password.*/input_password          = ${pass}/g" $file
	sed -i "s/output_password.*/output_password         = ${pass}/g" $file
	sed -i "s/default_md.*/default_md              = ${dfmd}/g" $file
}
	cd /var/certs/freeradius/
	sed_ $ca_pass ca.cnf $default_md
	sed_ $server_pass server.cnf $default_md
	sed_ $client_pass client.cnf $default_md

	for i in ca server client
	do
		make ${i}.pem
	done
}

ln_certs(){

	cd /var/certs/freeradius/
	chmod 600 *
	chmod 640 ca.pem
	chmod 640 server.pem
	chmod 640 server.key
	chgrp ssl-cert ca.pem
	chgrp ssl-cert server.pem
	chgrp ssl-cert server.key
	cd /etc/freeradius/certs/
	ln -s /var/certs/freeradius/ca.pem /etc/freeradius/certs/ca.pem
	ln -s /var/certs/freeradius/server.pem /etc/freeradius/certs/server.pem
	ln -s /var/certs/freeradius/server.key /etc/freeradius/certs/server.key
	ln -s /var/certs/freeradius/dh /etc/freeradius/certs/dh
}

#-------------------------------Main---------------------------------------
usage_ $@
#eap_config
#disable_default_servers
#prepare_make_certs
#build_certs
ln_certs

