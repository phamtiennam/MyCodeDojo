#!/bin/bash

####################################################################
#Description:Write a bash script that generate the dhcpd.conf configuration file
#Author: NamPham
#Email: nampt282@gmail.com
#Date: 2016_12_07
####################################################################
####################################################################

check_valid_mac(){
  local mac="$1"
  [[ "$mac" =~ ^([a-fA-F0-9]{2}:){5}[a-fA-F0-9]{2}$  ]] && echo "valid" || echo "invalid"
}

get_arp_mac(){
  local tmpfile=$1
  arp -a | awk '{print $4}' > $tmpfile
}

list_valid_mac(){
  get_arp_mac listmac.txt
  while read i
  do
    local a=$(check_valid_mac $i)
    [ "$a" == "invalid" ]&& sed -i "/${i}/d" listmac.txt
  done < listmac.txt
}

ping_range_of_ip(){

  local gateway_ip="$(ip route|awk '/default/{print $3}')"
  local subnet="24"

  [ "$gateway_ip" != "" ]&& nmap -sP ${gateway_ip}/${subnet}
}

create_dhcpd.conf(){

local router_gw="$(ip route|awk '/default/{print $3}')"
local j=120
local subnet="255.255.254.0"
local domain_name="cse.edu"
local domain_name_servers="139.182.2.1, 139.182.154.13"
local time_offset=-28800
local default_lease_time=21600
local max_lease_time=43200

cat <<EOF > dhcpd.conf
#
# DHCP Server Configuration file.
#  see /usr/share/doc/dhcp*/dhcpd.conf.sample
#
ddns-update-style interim;
ignore client-updates;

subnet $router_gw netmask $subnet {
  option routers                  $router_gw;
  option subnet-mask              $subnet;

  option domain-name              "$domain_name";
  option domain-name-servers      $domain_name_servers;

  option time-offset              $time_offset;

  default-lease-time              $default_lease_time;
  max-lease-time                  $max_lease_time;
}

EOF

[ ! -f listmac.txt ]&& exit 0

while read mac
do

  local ip="$(echo $router_gw|awk -F "." '{OFS=".";print $1,$2,$3}').$j"

  cat <<EOF >>dhcpd.conf
host coyote-$j {
  hardware ethernet $mac;
  fixed-address ${ip};
}

EOF

  j=$((j+1))

done < listmac.txt

}

#######################Main##################################

_main_(){
  ping_range_of_ip
  list_valid_mac
  create_dhcpd.conf
}

_main_
