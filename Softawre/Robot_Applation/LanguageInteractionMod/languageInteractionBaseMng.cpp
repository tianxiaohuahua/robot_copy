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
**时间：22.2.12 22：48
**作者：田小花
**功能：获取语音识别设置配置
**输入：
     语音识别配置信息结构体
**返回：
     初始化状态值
*/
INTERACTION_CONFIG *C_languageInteractionBaseMng::getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config)
{

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


/*
**时间：22.2.12 22：56
**作者：田小花
**功能：生成百度语音请求url
**输入：
     url配置
**返回：
     状态值
*/
unsigned int C_languageInteractionBaseMng::getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url)
{
	return mp_LanguageInteraBase->getInteractionSpeedUrl(p_Interaction_Config, p_url);
}

/*
**时间：22.2.12 22：56
**作者：田小花
**功能：获取百度返回数据
**输入：
     url配置
**返回：
     状态值
*/
unsigned int C_languageInteractionBaseMng::getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken)//获取百度返回数据
{
	return mp_LanguageInteraBase->getInteractionBaiduRecv(p_Interaction_Config, p_url, p_BaiduTocken);
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

