#!/bin/bash

get_data_webpage(){
  local url="$1"
  local output="$2"
  curl -s $url -o $output
}

get_winner_numbers(){

  local url="$1"

  get_data_webpage $url nam.html

  for i in {1..6}
  do
    awk /win${i}/'{split($0,tmp1,">");split(tmp1[2],tmp2,"<");print tmp2[1]}' nam.html 
  done

}

get_winner_numbers $@
