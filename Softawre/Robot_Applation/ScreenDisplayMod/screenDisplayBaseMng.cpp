#include "screenDisplayBaseMng.h"
#include "screenDisplayBaseDevice1.h"

static C_ScreenDispayBaseMng *g_pScreenDispayBaseMng = NULL;

C_ScreenDispayBaseMng* GetScreenDispayBaseObj()
{
    if(NULL == g_pScreenDispayBaseMng)
    {
        g_pScreenDispayBaseMng = new C_ScreenDispayBaseMng();
        if(NULL == g_pScreenDispayBaseMng)
        {
            //打印初始化的对象失败
        }
    }
    return g_pScreenDispayBaseMng;
}

C_ScreenDispayBaseMng::C_ScreenDispayBaseMng(/* args */)
{
    //根据不同的设备初始化不同的设备驱动
    mp_ScreenDisplayBase = NULL;

    if(1 == DEVICE_TYPE)
    {
        mp_ScreenDisplayBase = new C_screenDisplayBaseDevice1();
        if(NULL == mp_ScreenDisplayBase)
        {
            //打印初始化的对象失败
        }
    }
}

C_ScreenDispayBaseMng::~C_ScreenDispayBaseMng()
{
}

void C_ScreenDispayBaseMng::setScreenInform(void)//屏幕显示通知框
{
    mp_ScreenDisplayBase->setScreenInform();
}

void C_ScreenDispayBaseMng::setScreenText(void)//屏幕显示文本框
{
    mp_ScreenDisplayBase->setScreenText();
}
