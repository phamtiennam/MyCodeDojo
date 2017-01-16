#!/usr/bin/python

####################################################################
#Description:a script to build QSDK for SPF 4.0
#Author: NamPham
#Email: nampt282@gmail.com
#Date: 2017_01_11
####################################################################
####################################################################

import os
import sys
import tempfile

class untarpackage:

  extract_dir = "qca.git"

  def __init__(self,name,path,dir_name):
    self.name = name
    self.path = path
    self.dir_name = dir_name

  def untar(self):
    print(self.path)
    os.mkdir(self.path, 0777)
    from pyunpack import Archive
    Archive(self.name).extractall(self.path)

  def rename_(self):
    for dir in  os.listdir(self.path):
      old_name = os.path.join(self.path, dir)

    new_name = os.path.join(self.path, self.dir_name)

    os.rename(old_name,new_name)

def main(argv):
  #usage: python.script <source_qsdk> <path_untar>
  action = untarpackage(sys.argv[1],sys.argv[2],"qca.git")
  action.untar()
  action.rename_()

if __name__ == "__main__":
  main(sys.argv)

