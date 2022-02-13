#include <iostream>

#include "funA.h"

using namespace std;

int main(void)
{
	long int j = 0;
	
	testClass *TT = new testClass();
	//testClass T;

	while(1)
	{		
		TT->fun(j);
		
		TT->delay();
		
		j++;			
	}	
}
