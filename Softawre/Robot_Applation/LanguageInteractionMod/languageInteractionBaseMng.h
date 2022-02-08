#ifndef LANDUAGE_INTERATION_BASE_MNG_H
#define LANDUAGE_INTERATION_BASE_MNG_H

#include "languageInteractionBase.h"
#include "languageInteractionBaseDevice1.h"

class C_languageInteractionBaseMng
{
private:
	C_languageInterationBase *mp_LanguageInteraBase = NULL;
	
public:
	C_languageInteractionBaseMng();
	~C_languageInteractionBaseMng();

	char* getInteractionQuestion(); 
	
	void setInterationAnswer();
	
	void setInteractionRepetition(); //重复
};

C_languageInteractionBaseMng* GetLanguageInteraBaseObj();


#endif
