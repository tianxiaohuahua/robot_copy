#include "languageInteractionBaseMng.h"

C_languageInteractionBaseMng::C_languageInteractionBaseMng()
{
	//根据不同的设备初始化不同的设备驱动
    mp_LanguageInteraBase = NULL;

    //if(1 == DEVICE_TYPE)
    {
        mp_LanguageInteraBase = new C_languageInterationBaseBaidu();
        if(NULL == mp_LanguageInteraBase)
        {
            //打印初始化的对象失败
        }
    }
}

C_languageInteractionBaseMng::~C_languageInteractionBaseMng()
{

}

/*
**时间：22.2.12 22：48
**作者：田小花
**功能：对语音识别的基础设置进行初始化
**输入：
     无
**返回：
     初始化状态值
*/
unsigned int C_languageInteractionBaseMng::languageBaseInit()
{
	return mp_LanguageInteraBase->languageBaseInit();
}

/*
**时间：22.2.12 22：56
**作者：田小花
**功能：获取语音文件
**输入：
     录音文件指针
**返回：
     状态值
*/
unsigned int C_languageInteractionBaseMng::getInteractionAudio(FILE *p_audio)
{
	return mp_LanguageInteraBase->getInteractionAudio(p_audio);
}


/*
**时间：22.2.12 22：56
**作者：田小花
**功能：通过语音识别API识别语音
**输入：
     录音文件指针
**返回：
     状态值
*/
unsigned int C_languageInteractionBaseMng::getInteractionASR(FILE *p_audio)
{
	return mp_LanguageInteraBase->getInteractionASR(p_audio);
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

