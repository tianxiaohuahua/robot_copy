#!/bin/sh
echo "检查/home/OsdModule进程是否存在："

value=`ps -ef|grep /home/OsdModule|grep -v grep|wc -l`
#echo $value #使用一个定义过的变量，只要在变量名前面加美元符号即可

if [ $value -eq 1 ];then
	echo "服务存在"
else
	echo "服务不存在"
fi

