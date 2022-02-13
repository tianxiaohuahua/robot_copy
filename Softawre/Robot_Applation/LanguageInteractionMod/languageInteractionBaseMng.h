#ifndef LANDUAGE_INTERATION_BASE_MNG_H
#define LANDUAGE_INTERATION_BASE_MNG_H

#include "languageInteractionBase.h"
#include "languageInteractionBaseDevice1.h"
#include "languageInteractionBaseBaidu.h"
#include "languageInteractionWidget.h"
class C_languageInteractionBaseMng
{
private:
	C_languageInterationBase *mp_LanguageInteraBase = NULL;
	
public:
	C_languageInteractionBaseMng();
	~C_languageInteractionBaseMng();

	unsigned int languageBaseInit(); //对语音识别的配置初始化
	INTERACTION_CONFIG *getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config);//获取语音识别设置配置
	unsigned int getInteractionAudio(FILE *p_audio);  //获取语音文件指针
	unsigned int getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url);//生成百度语音请求url
	unsigned int getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken);//获取百度返回数据
	unsigned int getInteractionASR(FILE *p_audio);

	
	char* getInteractionQuestion(); 
	void setInterationAnswer();
	void setInteractionRepetition(); //重复
};

C_languageInteractionBaseMng* GetLanguageInteraBaseObj();


#endif
