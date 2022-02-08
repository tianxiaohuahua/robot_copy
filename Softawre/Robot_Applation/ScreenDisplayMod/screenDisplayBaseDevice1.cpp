#include "screenDisplayBaseDevice1.h"
#include "screenDisplayWidget.h"

screenDisplayBaseDevice1::screenDisplayBaseDevice1(/* args */)
{
    GetScreenDisplayWidgetObj();
}

screenDisplayBaseDevice1::~screenDisplayBaseDevice1()
{
}

void screenDisplayBaseDevice1::setScreenInform(void)
{
    char *string = {"通知信息"};

    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::DrawCr();
    C_ScreenDisplayWidget::DrawMessage(string);
    C_ScreenDisplayWidget::DrawCr();
    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::DrawCr();
}

void screenDisplayBaseDevice1::setScreenText(void)
{
    char *string = {"文本框"};
    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::DrawCr();
    C_ScreenDisplayWidget::DrawMessage(string);
    C_ScreenDisplayWidget::DrawCr();
    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::Drawline();
    C_ScreenDisplayWidget::DrawCr();
}