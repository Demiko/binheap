#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 14 13:29:07 2016

@author: demiko
"""
from random import randint
import os
import filecmp

cur_dir=os.getcwd()
in_file=cur_dir + "/input"
out_file=cur_dir + "/output"
nom_file=cur_dir + "/nominal"
count = 0
test_len = 50

test = [randint(1, 100) for i in range(test_len)]
nom = sorted(test)
f = open(in_file,mode='w')
f.write(str(test_len)+'\n'+'\n'.join(str(x) for x in test))
f.close()
f = open(nom_file,mode='w')
f.write('\n'.join(str(x) for x in nom)+'\n')
f.close()
f = open(nom_file)
nom = f.read()
f.close()
dirs = [x for x in os.listdir(cur_dir) if os.path.isdir(x) and x[0] != '.']
for path in dirs:
    count+=1
    if os.path.exists(path + "/Makefile"):
        ret = os.system("make -C " + path + " -s 1>/dev/null 2>/dev/null")
        if ret:
            print("not ok",count,"-",path,"can't make")
            continue
    if os.path.exists(path + "/binheap"):
        os.chmod(path + "/binheap", 0o744)
    else:
        print("not ok",count,"-","no executable",path)
        continue
    os.system("cat " + in_file + " | " + path + "/binheap > " + out_file)
    f = open(out_file)
    out = f.read()
    f.close()
    if not filecmp.cmp(out_file,nom_file): #out != nom:
        print("not ok ",count,"-",path,"did wrong")
        continue
    print("ok",count,"-",path)
os.remove(in_file)
os.remove(out_file)
os.remove(nom_file)
print('1..'+str(count))