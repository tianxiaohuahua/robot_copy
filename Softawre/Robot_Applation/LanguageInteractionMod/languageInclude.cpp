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

using namespace std;

char DEBUG_NORMAL[10] = {"\033[0m"}; //正常调试信息打印 白底黑字
char DEBUG_ERROR[10] = {"\033[31;1m"}; //错误警告打印 白底红字
char DEBUG_ADOPT[10] = {"\033[34;1m"}; //通过打印 白底绿字


UINT32 Sys_init(void)
{
	setbuf(stdout, NULL);//禁用缓冲
	
	printf("\033[31;1m程序开始\r\n"); //正常 \033[0m

	//初始化设置libcurl需要的程序环境
	//curl_global_init(CURL_GLOBAL_ALL); //设置libcurl需要的程序环境
	
	return 0;
}

/*
	复制内存数据
*/
unsigned int Sys_memcpy(void *dest, void *src, unsigned int count)
{
	memcpy(dest,src,count);
}

/*
	申请一块内存空间
*/
void *Sys_malloc(int size)
{
	 return (void *)malloc(size);
}

/*
	读取文件
*/
FILE * Sys_read_file(const char * path)
{
	return fopen(path, "r");
}

//从文件中读取JSON
void readFileJson(const char *p_filename, const char *p_key, char *p_keyValue)
{
	Json::Reader reader;
	Json::Value root;
	printf("从文件中读取，保证当前文件有test.json文件\n");

	//从文件中读取，保证当前文件有test.json文件
	ifstream in(p_filename, ios::binary);
	
	if( !in.is_open() )  
	{ 
		//cout << "Error opening file\n"; 
		return; 
	}
	
	if(reader.parse(in,root))
	{
        //读取根节点信息
        string name = root[p_key].asString();
		strcpy(p_keyValue,name.c_str());
	}
	else
	{
	    //cout << "parse error\n" << endl;	
	}
 
	in.close();
}

//从文件中读取JSON
void readFileJson(const char *p_filename, const char *p_key, int &p_keyValue)
{
	Json::Reader reader;
	Json::Value root;
	printf("从文件中读取，保证当前文件有test.json文件\n");

	//从文件中读取，保证当前文件有test.json文件
	ifstream in(p_filename, ios::binary);
	
	if( !in.is_open() )  
	{ 
		//cout << "Error opening file\n"; 
		return; 
	}
	
	if(reader.parse(in,root))
	{
        //读取根节点信息

        int age = root[p_key].asInt();

		p_keyValue = age;

        //cout << "I'm " << age << " years old" << endl;
	}
	else
	{
	    //cout << "parse error\n" << endl;	
	}
 
	in.close();
}