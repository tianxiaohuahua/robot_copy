#include "languageInteractionApi.h"

C_languageInteraApi::C_languageInteraApi()
{

}

C_languageInteraApi::~C_languageInteraApi()
{

}

void C_languageInteraApi::init()
{
	Sys_init();
	
	GetLanguageInteraBaseObj()->languageBaseInit();
	
	//GetLanguageInteraBaseObj()->setInterationAnswer();	

	
}


AUDIO_DATA *getAudio(char * p_filename)
{
	AUDIO_DATA *p_Audio_Data;
	p_Audio_Data = (AUDIO_DATA*) malloc(sizeof(p_Audio_Data));

	//获取录音
	FILE *p_file = fopen("16k.wav", "r");
    fseek(p_file, 0, SEEK_END); //获取文件头地址
    int len = ftell(p_file);
    fseek(p_file, 0, SEEK_SET);//获取文件尾地址

    p_Audio_Data->dataLen = len;
    p_Audio_Data->data = (char *) malloc(len);
    if (p_Audio_Data->data == NULL) 
    {
        //fprintf(stderr, "malloc size %d failed", len);
        printf("%scurl_easy_setopt\n",DEBUG_NORMAL);
        exit(11);
    }
    fread(p_Audio_Data->data, 1, len, p_file);

	return p_Audio_Data;
}

void C_languageInteraApi::startThread()
{
	//新建一个线程

	char *p_BaiduUrl = (char*)Sys_malloc(sizeof(char)*200);	
	char *p_BaiduTocken = (char*)Sys_malloc(sizeof(char)*1024);	
	INTERACTION_CONFIG *Baidu_Api_Key = (INTERACTION_CONFIG*)Sys_malloc(sizeof(INTERACTION_CONFIG));
	
	char filename[] = "16k.wav"; 

//被唤醒
//录音
	
//读取录音文件
	AUDIO_DATA *Audio_Data = GetLanguageInteraBaseObj()->getInteractionAudio(filename);	//从文件中获取音频
	if(NULL == Audio_Data)
	{
		printf("!!!!!!!!");
	}

	


/*录音文件上传*/
	/*获取url*/
	
	
	GetLanguageInteraBaseObj()->getInteractionConfig(Baidu_Api_Key); //url配置
	
	GetLanguageInteraBaseObj()->getInteractionSpeedUrl(Baidu_Api_Key, p_BaiduUrl); //获取URL
	printf("获取URL的值: %s\n", p_BaiduUrl);
	/*上传url解析*/
	GetLanguageInteraBaseObj()->getInteractionBaiduRecv(Baidu_Api_Key, p_BaiduUrl, p_BaiduTocken); //上传url解析 并将获取到的json解析得到access_token值
//语音解析
	GetLanguageInteraBaseObj()->getInteractionBaiduAsr(Baidu_Api_Key, Audio_Data->data, Audio_Data->dataLen, p_BaiduTocken); //调用百度的语音识别接口对语音进行解析。返回识别结果

	free(Audio_Data);
	free(Baidu_Api_Key);

//内容反馈
	//主线程休眠负责为其他线程提供心跳包程序和检测
	while(1)
	{
		sleep(1);  //延迟1秒
		printf("\033[0m1");
	}
}
