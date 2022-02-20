#ifndef LANDUAGE_INTERATION_BASE_DEVICE1_H
#define LANDUAGE_INTERATION_BASE_DEVICE1_h

#include "languageInteractionBase.h"
#include "languageInteractionWidget.h"

class C_languageInterationBaseDecice1 : public C_languageInterationBase
{
private:
	
public:
	C_languageInterationBaseDecice1();
	~C_languageInterationBaseDecice1();

	void getInteractionQuestion(); 
	void setInterationAnswer();
	void setInteractionRepetition(); //重复
};


#endif
