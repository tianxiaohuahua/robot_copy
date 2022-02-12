#ifndef LANDUAGE_INTERATION_BASE_MNG_H
#define LANDUAGE_INTERATION_BASE_MNG_H

#include "languageInteractionBase.h"
#include "languageInteractionBaseDevice1.h"
#include "languageInteractionBaseBaidu.h"
class C_languageInteractionBaseMng
{
private:
	C_languageInterationBase *mp_LanguageInteraBase = NULL;
	
public:
	C_languageInteractionBaseMng();
	~C_languageInteractionBaseMng();

	unsigned int languageBaseInit(); //对语音识别的配置初始化
	unsigned int getInteractionAudio(FILE *p_audio);  //获取语音文件指针
	unsigned int getInteractionASR(FILE *p_audio);

	
	char* getInteractionQuestion(); 
	void setInterationAnswer();
	void setInteractionRepetition(); //重复
};

C_languageInteractionBaseMng* GetLanguageInteraBaseObj();


#endif
