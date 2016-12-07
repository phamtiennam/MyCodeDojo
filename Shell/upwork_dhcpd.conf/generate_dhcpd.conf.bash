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

list_valid_mac
