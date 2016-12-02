#!/bin/bash
#See task.txt for requirements
#Author :nampham(nampt282@gmail.com)
#Date: 2016 Dec 02

check_integer(){
  local input=$1

  if [[ -n ${input//[0-9]/} ]] || [ "${input:0:1}" == "0" -a "${input:1:1}" != "" ];then
    echo "${input} is not an integer"
    exit 1
  fi
}

hbar(){
  local width=$1
  local color=$2

  for i in "$width" "$color"
  do
    check_integer "$i"
  done

  echo "width:${width} color:${color}"
}

hbar $@

