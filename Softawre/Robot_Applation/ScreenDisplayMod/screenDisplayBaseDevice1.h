#ifndef Screen_DISPLAY_BASE_DEVICE1_H
#define Screen_DISPLAY_BASE_DEVICE1_h

#include "screenDisplayBase.h"

class screenDisplayBaseDevice1 : public C_ScreenDisplayBase
{
private:
    /* data */
public:
    screenDisplayBaseDevice1(/* args */);
    ~screenDisplayBaseDevice1();

    void setScreenInform(void); //屏幕显示通知框
    void setScreenText(void);   //屏幕显示文本框
};




#endif
