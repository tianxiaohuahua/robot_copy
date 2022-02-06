//Compiler=arm-cortexa9-linux-gnueabihf-g++ //在H3平台上编译使用
Compiler=g++ //在PC平台上编译使用
APP : main.o
	# 不写-o参数，生成默认的可执行文件名为a.out，
	$(Compiler) main.o -o APP

main.o : main.cpp
	#-Wall 可以看到所有的警告
	#-g 可以调试
	#-c 只允许执行到汇编步骤，不允许链接。
	$(Compiler) main.cpp -c -Wall -g -o main.o

clean:
	rm APP main.o
