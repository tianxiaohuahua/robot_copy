#ifndef Screen_DISPLAY_WIDGET_H
#define Screen_DISPLAY_WIDGET_H

#include "stdio.h"

class C_ScreenDisplayWidget
{
private:
    /* data */
public:
    C_ScreenDisplayWidget(/* args */);
    ~C_ScreenDisplayWidget();

    //非静态成员引用必须与特定对象相对
    static void Drawline(void);
    static void DrawCr(void);
    static void DrawMessage(char *pStr);
};

C_ScreenDisplayWidget *GetScreenDisplayWidgetObj();

#endif
