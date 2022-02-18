#ifndef LANGUAGE_INCLUDE_H
#define LANGUAGE_INCLUDE_H
#include <memory.h>
#include <unistd.h>
#include <curl/curl.h>
#include <stdlib.h>

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <memory.h>

#include <curl/curl.h>

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <memory.h>


//线程相关
#include <pthread.h>

//mem操作
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <curl/curl.h> // 依赖libcurl


#include <jsoncpp/json/json.h> //编译链接库g++ -o app main.cpp -ljsoncpp
#include <string>
#include <iostream>
#include <fstream>

extern char DEBUG_NORMAL[10]; //正常调试信息打印 白底黑字
extern char DEBUG_ERROR[10] ; //错误警告打印 白底红字
extern char DEBUG_ADOPT[10] ; //通过打印 白底绿字




/*
相关函数：signal, alarm
 
头文件：#include <unistd.h>
 
定义函数：unsigned int sleep(unsigned int seconds);
 
函数说明：sleep()会令目前的进程暂停, 直到达到参数seconds 所指定的时间, 或是被信号所中断.
 
返回值：若进程/线程挂起到参数所指定的时间则返回0，若有信号中断则返回剩余秒数。
*/

typedef  unsigned int UINT32;

/**
 * @brief 函数返回值定义
 */
typedef enum RETURN_CODE {
    REV_TRUE      = 0,    // 返回正常
    REV_FAIL      = 1,    // 返回错误
    REV_FILE_NULL = 2,    // TOKEN CURL 调用错误
    REV_URL_NONE  = 3,    // url返回的为空
} RETURN_CODE;


//从文件中读取JSON
void readFileJson(const char *p_filename, const char *p_key, char *p_keyValue);
void readFileJson(const char *p_filename,  const char *p_key, int &p_keyValue);

unsigned int Sys_init(void);

unsigned int Sys_memcpy(void *dest, void *src, unsigned int count);

FILE * Sys_read_file(const char * path);

void *Sys_malloc(int size);

#endif