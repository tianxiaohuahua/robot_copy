#include "languageInteractionBase.h"

C_languageInterationBase::C_languageInterationBase()
{

}

C_languageInterationBase::~C_languageInterationBase()
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
unsigned int C_languageInterationBase::languageBaseInit()
{
     return 0;
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
INTERACTION_CONFIG * C_languageInterationBase::getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config)
{
     return 0;
}

/*
**时间：22.2.12 22：56
**作者：田小花
**功能：获取语音文件
**输入：
     文件指针 录音文件指针
**返回：
     状态值
*/
AUDIO_DATA * C_languageInterationBase::getInteractionAudio(const char *p_Filename)
{
     return 0;
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
unsigned int C_languageInterationBase::getInteractionASR(FILE *p_audio)
{
     return 0;
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
unsigned int C_languageInterationBase::getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url)
{
     return 0;
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
unsigned int C_languageInterationBase::getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken)//获取百度返回数据
{
     return 0;
}

/*
**时间：22.2.20 10：00
**作者：田小花
**功能：调用识别接口对语音识别
**输入：
     url配置
**返回：
     状态值
*/
unsigned int C_languageInterationBase::getInteractionBaiduAsr(INTERACTION_CONFIG *config, char *p_audioData, int &content_len, const char *token) 
{
     return 0;
}

void C_languageInterationBase::getInteractionQuestion()
{

}

void C_languageInterationBase::setInteractionRepetition()
{

}

void C_languageInterationBase::setInterationAnswer()
{

}



