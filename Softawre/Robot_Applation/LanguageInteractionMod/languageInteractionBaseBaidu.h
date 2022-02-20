#ifndef LANDUAGE_INTERATION_BASE_Baidu_H
#define LANDUAGE_INTERATION_BASE_Baidu_H

#include "languageInteractionBase.h"
#include "languageInteractionWidget.h"

class C_languageInterationBaseBaidu : public C_languageInterationBase
{
private:
	INTERACTION_CONFIG Interaction_Config;
	
public:

	C_languageInterationBaseBaidu();
	~C_languageInterationBaseBaidu();
	
	unsigned int languageBaseInit(void);
	INTERACTION_CONFIG *getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config); //获取语音识别的配置设置
	unsigned int getInteractionAudio(FILE *p_audio);
	unsigned int getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url); //获取请求url
	unsigned int getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken);//获取百度返回数据
	unsigned int getInteractionBaiduAsr(INTERACTION_CONFIG *config, char *p_audioData, int &content_len, const char *token) ; // 调用识别接口

	char* getInteractionQuestion(); 
	void setInterationAnswer();
	void setInteractionRepetition(); //重复
};


#endif
