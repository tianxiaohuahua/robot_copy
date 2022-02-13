#include "stdio.h"
#include <curl/curl.h>


int main(void)
{
	printf("\naaa\n");
	CURL *curl = curl_easy_init();
}

//gcc -g -I../thirdparty/include -I.. -std=gnu99 main.c -L../thirdparty/lib -lcurl -o main
//gcc -g -I.. -std=gnu99 main.c -L../thirdparty/lib -lcurl -o main
//gcc -g -I.. -std=gnu99 main.c -lcurl -o main
//gcc -std=gnu99 main.c -lcurl -o main
//gcc -std=gnu99 -lcurl -o main main.c 不行

//gcc main.c -lcurl -o main
