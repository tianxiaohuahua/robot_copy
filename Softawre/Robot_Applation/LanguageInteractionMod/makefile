#编译工具链
cc := g++ 

#所有.o文件
object = MainLanguageInteraction.o languageInteractionApi.o languageInteractionBase.o languageInteractionBaseDevice1.o languageInteractionBaseBaidu.o languageInteractionBaseMng.o languageInteractionWidget.o languageInclude.o

ModLanguageInteraction:$(object)
	#-Wall 可以看到所有的警告
	#-g 可以调试
	#-c 只允许执行到汇编步骤，不允许链接。
	#gcc main.c -lcurl -o main
	$(cc) $(object) -g -std=gnu99 -lcurl -ljsoncpp -o ModLanguageInteraction 

%o : %cpp
	$(cc) -cpp $<

clean:
	rm *o
	rm ModLanguageInteraction
