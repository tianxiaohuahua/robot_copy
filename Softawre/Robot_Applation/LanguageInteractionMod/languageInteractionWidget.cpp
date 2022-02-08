#include "languageInteractionWidget.h"

C_languageInterationWidget::C_languageInterationWidget()
{

}

C_languageInterationWidget::~C_languageInterationWidget()
{

}

void C_languageInterationWidget::sayWarning()
{
	printf("叮~~~~");
}


void C_languageInterationWidget::sayMassage(char * pStr)
{
	printf("%s", pStr);
}


void C_languageInterationWidget::sayInterval()
{
	printf("\n");
}

//为外部文件调用此类提供指针接口
static C_languageInterationWidget *gp_C_languageInterationWidget = NULL;

C_languageInterationWidget *GetLanguageInterationWidgetObj()
{
    if(NULL == gp_C_languageInterationWidget)
    {
        gp_C_languageInterationWidget = new C_languageInterationWidget();
        if(NULL == gp_C_languageInterationWidget)
        {
            return NULL;
        }
    }
    return gp_C_languageInterationWidget;
}

