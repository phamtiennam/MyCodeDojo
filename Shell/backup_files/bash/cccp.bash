#!/bin/bash
#The backup files script 
#By Nam Pham<nampt282@gmail.com>
#Date: 10 Nov 2016

#***************************************************************************
#List of funtions:

#check_instance()
#lock_script: To make sure only one instance of the script is running

#check_arguments() :if the user omits either of the two arguments
#check_dirs(): check the existence of the source and archive directory

#sort_dirs()
#rename_files_in_dirs()
#rename_files()
#****************************************************************************

lock_script(){
  case "$1" in
    lock)
      mkdir  /tmp/locktmp
      ;;
    unlock)
      rm -rf /tmp/locktmp
      ;;
    *)
    ;;
  esac
}

exit0(){
  lock_script unlock
  exit 
}

check_instance(){
  if [ -d /tmp/locktmp ]; then
    echo "Error:another instance of this script is running"
    exit 
  else
    lock_script lock
  fi
}

check_arguments(){
  [ $# != 2 ]&&{
    echo "Usage : cccp source_path archive_path"
    exit0
  }
}

check_dirs(){
  case "$1" in
    source_dir)
      [ -d $2 ]||{
          echo "Error $2 does not exist"
          exit0
      }
      ;;
    archive_dir)
      if [ -d $2 ]; then
        [ "$(ls -A $2)" ]&& {
          echo "Error $2 is not empty"
          exit0
        }
      else
        mkdir $2
      fi
      ;;
    *)
      ;;
  esac
}

rename_files(){

  local ext1="$1"
  local ext2="$2"
  local path_dir="$3"
  local name_dir="$(echo $path_dir |xargs --no-run-if-empty -n 1 basename)"
  local c=0

  for old_name in $(find $path_dir -maxdepth 1 -type f -name "*.$ext1" -o -name "*.$ext2"|xargs --no-run-if-empty -n 1 basename) 
  do
    c=$((c+1))
    new_name="${name_dir}${c}.${old_name#*.}" 
    [ "$new_name" == "$old_name" ]||mv -f ${path_dir}/${old_name} ${path_dir}/${new_name}
  done 
}

rename_files_in_dirs(){
  local path_dir="$1"
  [ -z "$path_dir" ]||{
    rename_files jpg JPG $path_dir
    rename_files doc docx $path_dir
  }
}

sort_dirs(){
  local archive_dir="$1"
  for dir in  $(find $archive_dir -type d)
  do
     rename_files_in_dirs $dir
  done
}


#******************************Main************************************
_main_(){
  local source_path="$1"
  local archive_path="$2"
  #check conditions
  check_instance
  check_arguments $@
  check_dirs source_dir $source_path
  check_dirs archive_dir $archive_path
  echo "Finish Checking"


  #wrte some code here
  cp -r $source_path/* $archive_path
  if [ $? -eq 0  ]; then
        echo "Start sorting files......"
        sort_dirs $archive_path
        echo "+++++++++++DONE+++++++++++++"
  else
        echo "Copy File Failed"
  fi

  lock_script unlock
}

_main_ $@
