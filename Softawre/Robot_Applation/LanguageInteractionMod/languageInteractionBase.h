#ifndef LANDUAGE_INTERATION_BASE_H
#define LANDUAGE_INTERATION_BASE_H

#include "languageInclude.h"
#include "languageInteractionWidget.h"

class C_languageInterationBase
{
private:

public:
	C_languageInterationBase();
	
	~C_languageInterationBase();

	virtual unsigned int languageBaseInit();//API初始化
	virtual INTERACTION_CONFIG *getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config); //获取语音识别的配置设置
	virtual unsigned int getInteractionAudio(FILE *p_audio); //获取语音数据
	virtual unsigned int getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url); //生成百度语音请求url
	virtual unsigned int getInteractionASR(FILE *p_audio); //通过API进行语音识别
	virtual unsigned int getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken);//获取百度返回数据
	virtual unsigned int getInteractionBaiduAsr(INTERACTION_CONFIG *config, char *p_audioData, int &content_len, const char *token); //调用识别接口对语音进行识别

	virtual char* getInteractionQuestion(); 
	virtual void setInterationAnswer();
	virtual void setInteractionRepetition(); //重复

	
};
#endif
