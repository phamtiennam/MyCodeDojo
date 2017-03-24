#!/usr/bin/python

import subprocess
import os

work_dir = "/home/tnpham/Xwork/haha"
rdsrcserver = "rdsrcserver.compex.com.sg"
link_git = "repo init -u git@%s" % rdsrcserver + ":cpxqsdk-cpx/compexwrt -b master -m CPX_QSDK_ILQ_DEV_2.2.0.xml"

class create_work_station:
  def __init__(self,path):
    self.path = path
  
  def makedir(self):
    subprocess.call(["mkdir", "-p", self.path])

class init_qsdk:
  def __init__(self):
    os.system(link_git)

    
main = create_work_station(work_dir)
main.makedir()
os.chdir(work_dir)
print(os.getcwd())
print("====================================")
init_qsdk()
print("====================================")

