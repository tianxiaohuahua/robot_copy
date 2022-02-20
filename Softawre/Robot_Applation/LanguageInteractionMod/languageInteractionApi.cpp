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
	FILE *file_audio;
	char *p_BaiduUrl;
	p_BaiduUrl = (char*)Sys_malloc(sizeof(char)*200);	
	char *p_BaiduTocken;
	p_BaiduTocken = (char*)Sys_malloc(sizeof(char)*1024);	


//被唤醒
//录音
	
//读取录音文件
	unsigned int rev = GetLanguageInteraBaseObj()->getInteractionAudio(audio);	//获取音频
	if(REV_FILE_NULL == rev)
	{
		printf("!!!!!!!!");
	}

	//获取录音
	FILE *p_file = fopen("16k.wav", "r");
    fseek(p_file, 0, SEEK_END); //获取文件头地址
    int len = ftell(p_file);
    fseek(p_file, 0, SEEK_SET);//获取文件尾地址
    int content_len = len;
    char *p_audioData = (char *) malloc(len);
    if (p_audioData == NULL) 
    {
        //fprintf(stderr, "malloc size %d failed", len);
        printf("%scurl_easy_setopt\n",DEBUG_NORMAL);
        exit(11);
    }
    fread(p_audioData, 1, len, p_file);


/*录音文件上传*/
	/*获取url*/
	INTERACTION_CONFIG *Baidu_Api_Key;
	Baidu_Api_Key = (INTERACTION_CONFIG*)Sys_malloc(sizeof(INTERACTION_CONFIG));	

	GetLanguageInteraBaseObj()->getInteractionConfig(Baidu_Api_Key); //url配置
	
	GetLanguageInteraBaseObj()->getInteractionSpeedUrl(Baidu_Api_Key, p_BaiduUrl); //获取URL
	printf("获取URL的值: %s\n", p_BaiduUrl);
	/*上传url解析*/
	GetLanguageInteraBaseObj()->getInteractionBaiduRecv(Baidu_Api_Key, p_BaiduUrl, p_BaiduTocken); //上传url解析 并将获取到的json解析得到access_token值
//语音解析
	GetLanguageInteraBaseObj()->getInteractionBaiduAsr(Baidu_Api_Key, p_audioData, content_len, p_BaiduTocken); //调用百度的语音识别接口对语音进行解析。返回识别结果

	free(p_audioData);

//内容反馈
	//主线程休眠负责为其他线程提供心跳包程序和检测
	while(1)
	{
		sleep(1);  //延迟1秒
		printf("\033[0m1");
	}
}
