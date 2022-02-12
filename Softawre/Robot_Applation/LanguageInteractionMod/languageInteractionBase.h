#ifndef LANDUAGE_INTERATION_BASE_H
#define LANDUAGE_INTERATION_BASE_H

#include "languageInclude.h"

class C_languageInterationBase
{
private:

public:
	C_languageInterationBase();
	
	~C_languageInterationBase();

	virtual unsigned int languageBaseInit();//API初始化
	virtual unsigned int getInteractionAudio(FILE *p_audio); //获取语音数据
	
	virtual unsigned int getInteractionASR(FILE *p_audio); //通过API进行语音识别

	
	virtual char* getInteractionQuestion(); 
	virtual void setInterationAnswer();
	virtual void setInteractionRepetition(); //重复

	
};
#endif
