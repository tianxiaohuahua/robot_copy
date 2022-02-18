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

void C_languageInteraApi::startThread()
{
	//新建一个线程
	FILE *audio;
	
	char *p_BaiduUrl;
	p_BaiduUrl = (char*)Sys_malloc(sizeof(char)*200);	
	char *p_BaiduTocken;



//被唤醒
//录音
	
//读取录音文件
	unsigned int rev = GetLanguageInteraBaseObj()->getInteractionAudio(audio);	//获取音频
	if(REV_FILE_NULL == rev)
	{
		printf("!!!!!!!!");
	}
/*录音文件上传*/
	/*获取url*/
	INTERACTION_CONFIG *Baidu_Api_Key;
	
	GetLanguageInteraBaseObj()->getInteractionConfig(Baidu_Api_Key); //url配置
	
	GetLanguageInteraBaseObj()->getInteractionSpeedUrl(Baidu_Api_Key, p_BaiduUrl); //获取URL
	printf("获取URL的值: %s\n", p_BaiduUrl);
	/*上传url解析*/
	GetLanguageInteraBaseObj()->getInteractionBaiduRecv(Baidu_Api_Key, p_BaiduUrl, p_BaiduTocken); 
//语音解析

//内容反馈
	//主线程休眠负责为其他线程提供心跳包程序和检测
	while(1)
	{
		sleep(1);  //延迟1秒
		printf("\033[0m1");
	}
}
