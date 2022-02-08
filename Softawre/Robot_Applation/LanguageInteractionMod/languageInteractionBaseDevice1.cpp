#include "languageInteractionBaseDevice1.h"

C_languageInterationBaseDecice1::C_languageInterationBaseDecice1()
{
	GetLanguageInterationWidgetObj();
}

C_languageInterationBaseDecice1::~C_languageInterationBaseDecice1()
{

}

char *C_languageInterationBaseDecice1::getInteractionQuestion()
{
	char* str = {"你吃了嘛？"};
	C_languageInterationWidget::sayWarning();
	C_languageInterationWidget::sayInterval();
	return str;
}


void C_languageInterationBaseDecice1::setInterationAnswer()
{
	char* str = "回答";
	C_languageInterationWidget::sayWarning();
	C_languageInterationWidget::sayInterval();
	C_languageInterationWidget::sayMassage(str);
	C_languageInterationWidget::sayInterval();
}

void C_languageInterationBaseDecice1::setInteractionRepetition()
{
	char* str = "重复说的话";
	C_languageInterationWidget::sayWarning();
	C_languageInterationWidget::sayInterval();
	C_languageInterationWidget::sayMassage(str);
	C_languageInterationWidget::sayInterval();
	
}

