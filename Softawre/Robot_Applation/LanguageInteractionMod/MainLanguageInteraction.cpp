#include "MainLanguageInteraction.h"
#include "stdio.h"
#include <unistd.h>

int main(void)
{
    printf("begin\r\n");
	C_languageInteraApi::init();
	
	C_languageInteraApi::startThread();
	while(1)
	{
		printf("1");
		
		sleep(1);  //延迟1秒
	}
	
}