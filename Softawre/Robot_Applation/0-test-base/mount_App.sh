#!/bin/sh

echo "挂载程序"

cd 

umount /mnt

mount 192.168.1.6:/home/tianxiaohua/code/robot/Softawre/Robot_Applation /mnt  #挂载

cd /mnt

./APP