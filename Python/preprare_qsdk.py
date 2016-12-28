#!/usr/bin/python

import subprocess
import os

work_dir = "/home/tnpham/Xwork/keke"
rdsrcserver = "192.168.8.67"

class create_work_station:
  def __init__(self,path):
    self.path = path
  
  def makedir(self):
    subprocess.call(["mkdir", "-p", self.path])

class init_qsdk:
  def __init__(self):
    #subprocess.call(["repo", "init", "-u git@rdsrcserver.compex.com.sg:cpxqsdk-cpx/compexwrt -b master -m CPX_QSDK_ILQ_DEV_2.2.0.xml"])
    subprocess.call(["/home/tnpham/.local/bin/repo", "init", "-u git@",rdsrcserver,":cpxqsdk-cpx/compexwrt -b master -m CPX_QSDK_ILQ_DEV_2.2.0.xml"])

    
main = create_work_station(work_dir)
main.makedir()
os.chdir(work_dir)
print("====================================")
init_qsdk()
print("====================================")
print(os.getcwd())
