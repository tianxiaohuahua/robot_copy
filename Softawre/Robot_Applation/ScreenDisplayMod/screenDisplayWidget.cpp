#include "screenDisplayWidget.h"

C_ScreenDisplayWidget::C_ScreenDisplayWidget(/* args */)
{
}

C_ScreenDisplayWidget::~C_ScreenDisplayWidget()
{
}

void C_ScreenDisplayWidget::Drawline(void)
{
    printf("________");
}

void C_ScreenDisplayWidget::DrawCr(void)
{
    printf("\n");
}

void C_ScreenDisplayWidget::DrawMessage(char *pStr)
{
    printf("%s",pStr);
}

//为外部文件调用此类提供指针接口
static C_ScreenDisplayWidget *gp_screenDisplayWidge = NULL;

C_ScreenDisplayWidget *GetScreenDisplayWidgetObj()
{
    if(NULL == gp_screenDisplayWidge)
    {
        gp_screenDisplayWidge = new C_ScreenDisplayWidget();
        if(NULL == gp_screenDisplayWidge)
        {
            return NULL;
        }
    }
    return gp_screenDisplayWidge;
}
