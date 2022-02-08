#include "languageInteractionBaseMng.h"

C_languageInteractionBaseMng::C_languageInteractionBaseMng()
{
	//根据不同的设备初始化不同的设备驱动
    mp_LanguageInteraBase = NULL;

    //if(1 == DEVICE_TYPE)
    {
        mp_LanguageInteraBase = new C_languageInterationBaseDecice1();
        if(NULL == mp_LanguageInteraBase)
        {
            //打印初始化的对象失败
        }
    }
}

C_languageInteractionBaseMng::~C_languageInteractionBaseMng()
{

}


char *C_languageInteractionBaseMng::getInteractionQuestion()
{
	return mp_LanguageInteraBase->getInteractionQuestion();
}

void C_languageInteractionBaseMng::setInteractionRepetition()
{
	mp_LanguageInteraBase->setInteractionRepetition();
}

void C_languageInteractionBaseMng::setInterationAnswer()
{
	mp_LanguageInteraBase->setInterationAnswer();
}



static C_languageInteractionBaseMng *g_pLanguageInteraBaseMng = NULL;

C_languageInteractionBaseMng* GetLanguageInteraBaseObj()
{
    if(NULL == g_pLanguageInteraBaseMng)
    {
        g_pLanguageInteraBaseMng = new C_languageInteractionBaseMng();
        if(NULL == g_pLanguageInteraBaseMng)
        {
            //打印初始化的对象失败
        }
    }
    return g_pLanguageInteraBaseMng;
}

