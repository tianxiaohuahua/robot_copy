#ifndef LANDUAGE_INTERATION_BASE_Baidu_H
#define LANDUAGE_INTERATION_BASE_Baidu_H

#include "languageInteractionBase.h"
#include "languageInteractionWidget.h"

class C_languageInterationBaseBaidu : public C_languageInterationBase
{
private:
	
public:
	C_languageInterationBaseBaidu();
	~C_languageInterationBaseBaidu();
	
	unsigned int languageBaseInit();
	unsigned int getInteractionAudio(FILE *p_audio);
		
	char* getInteractionQuestion(); 
	void setInterationAnswer();
	void setInteractionRepetition(); //重复
};


#endif
