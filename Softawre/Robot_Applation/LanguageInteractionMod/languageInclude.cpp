#include "languageInclude.h"
/*
相关函数：signal, alarm
 
头文件：#include <unistd.h>
 
定义函数：unsigned int sleep(unsigned int seconds);
 
函数说明：sleep()会令目前的进程暂停, 直到达到参数seconds 所指定的时间, 或是被信号所中断.
 
返回值：若进程/线程挂起到参数所指定的时间则返回0，若有信号中断则返回剩余秒数。
*/

/*
https://blog.csdn.net/u011857683/article/details/80678219
printf 和 sleep 输出问题
printf默认是输出到标准输出，而标准输出默认使用的是行缓冲。

在sleep之前fflush(stdout)强制刷缓冲，或者在程序开始使用setbuf(stdout, NULL)禁用缓冲。

#include <stdio.h>
#include <unistd.h>
void foobar(int i)
{
        printf("it from lib.so i(%d)", i);
        fflush(stdout);
        sleep(100);
}
*/



UINT32 Sys_init(void)
{
	setbuf(stdout, NULL);//禁用缓冲
	
	printf("\033[31;1m程序开始\r\n"); //正常 \033[0m

	//初始化设置libcurl需要的程序环境
	//curl_global_init(CURL_GLOBAL_ALL); //设置libcurl需要的程序环境
	
	return 0;
}

unsigned int Sys_memcpy(void *dest, void *src, unsigned int count)
{
	memcpy(dest,src,count);
}

void *Sys_malloc(int size)
{
	 return (void *)malloc(size);
}

FILE * Sys_read_file(const char * path)
{
	return fopen(path, "r");
}