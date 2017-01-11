#!/usr/bin/python

####################################################################
#Description:a script to build QSDK for SPF 4.0
#Author: NamPham
#Email: nampt282@gmail.com
#Date: 2017_01_11
####################################################################
####################################################################

import os
import tempfile

class untarpackage:

  extract_dir = "qca.git"

  #def __init__(self,name,path):
  def __init__(self,name):
    self.name = name
    #self.path = path

  def untar(self):
    temp_dir = "temp_dir"
    os.mkdir(temp_dir, 0777)
    from pyunpack import Archive
    #print(Archive(self.name).extractall(self.path))
    Archive(self.name).extractall(temp_dir)
    print(os.listdir(temp_dir))



action = untarpackage("b161005-r00004.1-qca-networking-2016-spf-4-0_qca_oem-83ab7450f.zip")
action.untar()

#os.rename(os.listdir(temp_dir),"namtest234")
