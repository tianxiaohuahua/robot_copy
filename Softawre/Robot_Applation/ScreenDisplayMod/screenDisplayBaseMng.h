#ifndef Screen_DISPLAY_BASE_MNG_H
#define Screen_DISPLAY_BASE_MNG_H

#include "screenDisplayBase.h"

//#define DEVICE_TYPE 1 //规范设备类型 //宏定义全部使用大写
const int DEVICE_TYPE = 1; 

class C_ScreenDispayBaseMng
{
private:
    /* data */
    C_ScreenDisplayBase *mp_ScreenDisplayBase;

public:
    C_ScreenDispayBaseMng(/* args */);
    ~C_ScreenDispayBaseMng();

    void setScreenInform(); //屏幕显示通知框
    void setScreenText();   //屏幕显示文本框
};

C_ScreenDispayBaseMng* GetScreenDispayBaseObj();


#endif
