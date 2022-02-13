#ifndef LANDUAGE_INTERATION_API_H
#define LANDUAGE_INTERATION_API_H

#include "languageInteractionBaseMng.h"
#include "languageInclude.h"
class C_languageInteraApi
{
private:
	
public:
	C_languageInteraApi();
	~C_languageInteraApi();

	static void init();

	static void startThread(); //启动线程
};


#endif