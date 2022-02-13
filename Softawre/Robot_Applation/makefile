#CC = arm-xilinx-linux-gnueabi-g++
CC = g++

# 自定义依赖关系，源文件（后缀为.c)经过编译汇编生成目标文件（后缀为.o)
# 目标文件执行生成可执行文件（类似与mytool）
App : main.o funA.o
	# 写gcc命令时候，前面要tab按键一下
	# 不写-o参数，生成默认的可执行文件名为a.out，这里我们修改为mytool
	$(CC) main.o funA.o -o App

main.o : main.cpp
	#-Wall 可以看到所有的警告
	#-g 可以调试
	#-c 只允许执行到汇编步骤，不允许链接。
	$(CC) main.cpp -c -Wall -g -o main.o 
	
funA.o : funA.cpp
	#-Wall 可以看到所有的警告
	#-g 可以调试
	#-c 只允许执行到汇编步骤，不允许链接。
	$(CC) funA.cpp -c -Wall -g -o funA.o
	
clean:
	rm App main.o funA.o