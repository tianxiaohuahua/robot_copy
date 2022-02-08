#include <iostream>
#include "funA.h"
#include "stdio.h"

using namespace std;

testClass::testClass(void)
{
	printf("init!\n");	
}

testClass::~testClass(void)
{
	printf("done!\n");	
}

void testClass::fun(int j)
{
	printf("\033[0m你好麽，\033[1m我很好。。");
	printf("\033[30;4m你好麽，\033[31;1m我很好。。");
	printf("\033[32;1m你好麽，\033[1m我很好。。");
	printf("\033[33;1m你好麽，\033[34;1m我很好。。");
	printf("\033[35;1m你好麽，\033[36;1m我很好。。");
	printf("\033[37;1m你好麽，\033[38;5m我很好。。");
	cout<<"!!!!!!!!"<<j<<endl;
}

void testClass::delay(void)
{
	long int i=0;
	while(i--){}
	i=9999999;
	while(i--){}
	i=9999999;
}