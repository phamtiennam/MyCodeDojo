#!/bin/sh
read input
if [ $input -eq $input 2>/dev/null  ]
then
  echo "$input is an integer"
else
  echo "$input is not an integer"
fi
