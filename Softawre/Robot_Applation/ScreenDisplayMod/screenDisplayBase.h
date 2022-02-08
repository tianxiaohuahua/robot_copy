#ifndef Screen_DISPLAY_BASE_H
#define Screen_DISPLAY_BASE_H

#include "stdio.h"
class C_ScreenDisplayBase
{
private:
    /* data */
public:
    C_ScreenDisplayBase(/* args */);
    ~C_ScreenDisplayBase();

    virtual void setScreenInform();
    virtual void setScreenText();
};


#endif
