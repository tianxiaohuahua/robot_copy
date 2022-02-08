#include "MainScreenDisplay.h"
#include "stdio.h"
#include "screenDisplaApplay.h"
#include "screenDisplayApi.h"
int main(void)
{
    printf("begin\r\n");

    //初始化
    
    //启动线程
    C_ScreenDisplayApi::Begin();
    C_ScreenDisplayApi::Application();
}