#ifndef LANDUAGE_INTERATION_BASE_H
#define LANDUAGE_INTERATION_BASE_H


class C_languageInterationBase
{
private:

public:
	C_languageInterationBase();
	
	~C_languageInterationBase();

	virtual char* getInteractionQuestion(); 
	
	virtual void setInterationAnswer();
	
	virtual void setInteractionRepetition(); //重复

	
};
#endif
