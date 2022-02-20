#include "languageInteractionWidget.h"

C_languageInterationWidget::C_languageInterationWidget()
{

}

C_languageInterationWidget::~C_languageInterationWidget()
{

}

void C_languageInterationWidget::sayWarning()
{
	printf("叮~~~~");
}


void C_languageInterationWidget::sayMassage(char * pStr)
{
	printf("%s", pStr);
}


void C_languageInterationWidget::sayInterval()
{
	printf("\n");
}

using namespace std;
//从文件中读取JSON
unsigned int C_languageInterationWidget::readFileJson(const char *p_filename, const char *p_key, char *p_keyValue)
{
	Json::Reader reader;
	Json::Value root;
	printf("%s从文件中读取json百度配置\n",DEBUG_NORMAL);

	//从文件中读取，保证当前文件有test.json文件
	ifstream in(p_filename, ios::binary);
	
	if( !in.is_open() )  
	{ 
		printf("%s文件打开失败\n",DEBUG_ERROR);
		return REV_FAIL; 
	}
	
	if(reader.parse(in,root))
	{
        //读取根节点信息
        string name = root[p_key].asString();
		strcpy(p_keyValue,name.c_str());
	}
	else
	{
		printf("%sjson中没有对应的键值\n",DEBUG_ERROR);
	    return REV_FAIL;
	}
 
	in.close();
	return REV_TRUE;
}

//从文件中读取JSON
unsigned int C_languageInterationWidget::readFileJson(const char *p_filename, const char *p_key, int &p_keyValue)
{
	Json::Reader reader;
	Json::Value root;
	printf("从文件中读取json百度配置\n");

	//从文件中读取，保证当前文件有test.json文件
	ifstream in(p_filename, ios::binary);
	
	if( !in.is_open() )  
	{ 
		printf("%s文件打开失败\n",DEBUG_ERROR);
		return REV_FAIL; 
	}
	
	if(reader.parse(in,root))
	{
        //读取根节点信息
        int age = root[p_key].asInt();
		p_keyValue = age;
	}
	else
	{
	    printf("%sjson中没有对应的键值\n",DEBUG_ERROR);
	    return REV_FAIL;
	}
 
	in.close();
	return REV_TRUE;
}


//从文件中读取JSON
unsigned int C_languageInterationWidget::readCurlJson(const char *p_json, const char *p_key, char *p_keyValue)
{
	Json::Reader reader;
	Json::Value root;
	printf("从字符串中读取json百度配置\n");

  //从字符串中读取数据
    if(reader.parse(p_json,root))
	{
		string name = root[p_key].asString();
		strcpy(p_keyValue,name.c_str());
	}
	else
	{
	    printf("%sjson中没有对应的键值\n",DEBUG_ERROR);
	    return REV_FAIL;
	}
	return REV_TRUE;
}



unsigned int C_languageInterationWidget::readFeedbackProfile(INTERACTION_CONFIG *p_ApiKey) //读取配置文件
{

//打开文件
//处理文件内容
//通过结构体的方式返回配置文件的信息
	
    //测试自训练平台需要打开以下信息， 自训练平台模型上线后，您会看见 第二步：“”获取专属模型参数pid:8001，modelid:1234”，按照这个信息获取 dev_pid=8001，lm_id=1234
    /* dev_pid = 8001 ;   
       int lm_id = 1234 ;
    */

    /* 极速版 打开注释的话请填写自己申请的appkey appSecret ，并在网页中开通极速版（开通后可能会收费）
    url = "http://vop.baidu.com/pro_api"; // 可改为https
    dev_pid = 80001;
    scope = "brain_enhanced_asr"; // 有此scope表示有极速版能力，没有请在网页里开通极速版
    */

    /* 忽略scope检查，非常旧的应用可能没有
    scope = "";
    */
	char api_key[200] 	 = "ZUmYyI8ViFGDL5cpDEbC1hlA";
	char secret_key[300] = "KcgQsVbBQFSTbq1Umj4EK9kw4Y2P8MvH";
	char url[200] 		 = "http://vop.baidu.com/server_api";  // 可改为https
    int  dev_pid 		 = 1537; //  1537 表示识别普通话，使用输入法模型。其它语种参见文档;
    char scope[200] 	 = "audio_voice_assistant_get"; // # 有此scope表示有asr能力，没有请在网页里勾选，非常旧的应用可能没有
	char cuid[200]       = "1234567C";	//必填	用户唯一标识，用来计算UV值。建议填写能区分用户的机器 MAC 地址或 IMEI 码，长度为60字符以内
	char format[200]     = "wav";// 文件后缀仅支持 pcm/wav/amr 格式，极速版额外支持m4a 格式
	int  rate            = 16000;  // 采样率固定值

	char url_pattern[] = "%s?grant_type=client_credentials&client_id=%s&client_secret=%s";
	char API_TOKEN_URL[] = "https://aip.baidubce.com/oauth/2.0/token";
	
	Sys_memcpy(p_ApiKey->BaiduApiConfig.api_key,    api_key,     sizeof(api_key));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.secret_key, secret_key, 	sizeof(secret_key));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.url, 	   url, 		sizeof(url));
	Sys_memcpy(&p_ApiKey->BaiduApiConfig.dev_pid,  &dev_pid,     sizeof(dev_pid));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.scope, 	   scope,       sizeof(scope));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.cuid, 	   cuid,        sizeof(cuid));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.format, 	   format,      sizeof(format));
	Sys_memcpy(&p_ApiKey->BaiduApiConfig.rate,     &rate,        sizeof(rate));

	Sys_memcpy(p_ApiKey->Url_Config.Url_api, 	   API_TOKEN_URL,      sizeof(API_TOKEN_URL));
	Sys_memcpy(p_ApiKey->Url_Config.Url_pattern,   url_pattern,        sizeof(url_pattern));
	return REV_TRUE;
}


unsigned int C_languageInterationWidget::readFeedbackProfile(INTERACTION_CONFIG *p_ApiKey, const char*p_fileName) //读取配置文件
{
	char api_key[200];//	 = "ZUmYyI8ViFGDL5cpDEbC1hlA";
	char secret_key[200];// = "KcgQsVbBQFSTbq1Umj4EK9kw4Y2P8MvH";
	char url[200];// 		 = "http://vop.baidu.com/server_api";  // 可改为https
    int  dev_pid;// 		 = 1537; //  1537 表示识别普通话，使用输入法模型。其它语种参见文档;
    char scope[200];// 	 = "audio_voice_assistant_get"; // # 有此scope表示有asr能力，没有请在网页里勾选，非常旧的应用可能没有
	char cuid[200] ;//      = "1234567C";	//必填	用户唯一标识，用来计算UV值。建议填写能区分用户的机器 MAC 地址或 IMEI 码，长度为60字符以内
	char format[200] ;//    = "wav";// 文件后缀仅支持 pcm/wav/amr 格式，极速版额外支持m4a 格式
	int  rate ;//           = 16000;  // 采样率固定值

	char url_pattern[200];// = "%s?grant_type=client_credentials&client_id=%s&client_secret=%s";
	char API_TOKEN_URL[200];// = "https://aip.baidubce.com/oauth/2.0/token";

	char *key_api_key       = "api_key";
	char *key_secret_key    = "secret_key";
	char *key_url           = "url";
	char *key_dev_pid       = "dev_pid";
	char *key_scope         = "scope";
	char *key_cuid          = "cuid";
	char *key_format        = "format";
	char *key_rate          = "rate";
	char *key_url_pattern   = "url_pattern";
	char *key_API_TOKEN_URL = "API_TOKEN_URL";

	C_languageInterationWidget::readFileJson(p_fileName, key_api_key,       api_key);
	C_languageInterationWidget::readFileJson(p_fileName, key_secret_key,    secret_key);
	C_languageInterationWidget::readFileJson(p_fileName, key_url,           url);
	C_languageInterationWidget::readFileJson(p_fileName, key_dev_pid,       dev_pid);
	C_languageInterationWidget::readFileJson(p_fileName, key_scope,         scope);
	C_languageInterationWidget::readFileJson(p_fileName, key_cuid,          cuid);
	C_languageInterationWidget::readFileJson(p_fileName, key_format,        format);
	C_languageInterationWidget::readFileJson(p_fileName, key_rate,          rate);
	C_languageInterationWidget::readFileJson(p_fileName, key_url_pattern,   url_pattern);
	C_languageInterationWidget::readFileJson(p_fileName, key_API_TOKEN_URL, API_TOKEN_URL);

	Sys_memcpy(p_ApiKey->BaiduApiConfig.api_key,    api_key,     sizeof(api_key));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.secret_key, secret_key, 	sizeof(secret_key));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.url, 	   url, 		sizeof(url));
	Sys_memcpy(&p_ApiKey->BaiduApiConfig.dev_pid,  &dev_pid,     sizeof(dev_pid));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.scope, 	   scope,       sizeof(scope));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.cuid, 	   cuid,        sizeof(cuid));
	Sys_memcpy(p_ApiKey->BaiduApiConfig.format, 	   format,      sizeof(format));
	Sys_memcpy(&p_ApiKey->BaiduApiConfig.rate,     &rate,        sizeof(rate));

	Sys_memcpy(p_ApiKey->Url_Config.Url_api, 	   API_TOKEN_URL,      sizeof(API_TOKEN_URL));
	Sys_memcpy(p_ApiKey->Url_Config.Url_pattern,   url_pattern,        sizeof(url_pattern));



	return REV_TRUE;
}


/*
**时间：22.2.12 22：56
**作者：田小花
**功能：获取语音文件
**输入：
     文件指针 录音文件指针
**返回：
     状态值
*/
unsigned int C_languageInterationWidget::getRecordAudio(FILE *p_audio) //获取音频 录音
{
	char *p_fileName = "16k.wav";

	Sys_read_file(p_fileName,p_audio);
	if(NULL == p_audio)
	{
		return REV_FILE_NULL;
	}
	return REV_TRUE;
}

//为外部文件调用此类提供指针接口
static C_languageInterationWidget *gp_C_languageInterationWidget = NULL;

C_languageInterationWidget *GetLanguageInterationWidgetObj()
{
    if(NULL == gp_C_languageInterationWidget)
    {
        gp_C_languageInterationWidget = new C_languageInterationWidget();
        if(NULL == gp_C_languageInterationWidget)
        {
            return NULL;
        }
    }
    return gp_C_languageInterationWidget;
}

