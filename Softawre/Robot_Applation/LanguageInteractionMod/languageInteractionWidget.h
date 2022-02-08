#ifndef LANDUAGE_INTERATION_WIDGET_H
#define LANDUAGE_INTERATION_WIDGET_H

#include "stdio.h"
class C_languageInterationWidget
{
private:

public:
	C_languageInterationWidget();
	~C_languageInterationWidget();

	static void sayMassage(char *pStr);
	static void sayWarning(); //提示音
	static void sayInterval();//间隔
};

//为上层类的调用提供唯一接口
C_languageInterationWidget *GetLanguageInterationWidgetObj();

#endif
