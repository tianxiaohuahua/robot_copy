#编译工具链
cc := g++ 

#所有.o文件
object = MainScreenDisplay.o screenDisplayApi.o screenDisplayBase.o screenDisplayBaseDevice1.o screenDisplayBaseMng.o screenDisplayWidget.o 

ModScreenDisplay:$(object)
	$(cc) -o ModScreenDisplay $(object)

%o : %c
	g++ -cpp $<

#将生成的.o文件放到O_PATH目录下
$(O_PATH)/%.o: $(SUBDIR)/%.cpp
	$(cc) -c $(PI_LIB_PATH) $< -o $@

clean:
	rm *o
	rm ModScreenDisplay


#目标文件名
#targetFile = ModLcdDisplay

#编译工具链
#cc := g++ 

#链接库的文件路径、头文件路径与要链接的库
#PI_LIB_PATH := -I /home/lgb/piLib/piInclude/WiringPi/wiringPi -L /home/lgb/piLib -lwiringPi

#.o文件存放路径
#O_PATH = ./obj

#源文件路径
#SUBDIR := $(shell pwd)

#获取源文件路径下的所有.o文件名
#SOURCE_PATH = $(foreach dir,$(SUBDIR),$(wildcard $(dir)/*.c))
#OBJ_PATH = $(patsubst %.c,$(O_PATH)/%.o, $(notdir $(SOURCE_PATH)))

#生成目标文件
#$(targetFile) : $(OBJ_PATH)
#	$(cc) $(OBJ_PATH) $(PI_LIB_PATH) -o $(targetFile)
#	$(cc) -o ModLcdDisplay $(object)

#将生成的.o文件放到O_PATH目录下
#$(O_PATH)/%.o: $(SUBDIR)/%.cpp
#	$(cc) -c $(PI_LIB_PATH) $< -o $@

#伪目标
#.PHONY : clean

#clean :
#	rm $(OBJ_PATH)
#	rm $(targetFile)

