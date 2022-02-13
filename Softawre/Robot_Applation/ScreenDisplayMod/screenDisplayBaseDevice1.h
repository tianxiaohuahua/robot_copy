#ifndef Screen_DISPLAY_BASE_DEVICE1_H
#define Screen_DISPLAY_BASE_DEVICE1_h

#include "screenDisplayBase.h"

class C_screenDisplayBaseDevice1 : public C_ScreenDisplayBase
{
private:
    /* data */
public:
    C_screenDisplayBaseDevice1(/* args */);
    ~C_screenDisplayBaseDevice1();

    void setScreenInform(void); //屏幕显示通知框
    void setScreenText(void);   //屏幕显示文本框
};




#endif
