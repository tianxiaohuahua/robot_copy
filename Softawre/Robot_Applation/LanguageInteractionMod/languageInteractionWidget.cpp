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

unsigned int C_languageInterationWidget::readFeedbackProfile(Baidu_API_KEY &baiduApiKey) //读取配置文件
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
	
	Sys_memcpy(baiduApiKey.api_key,    api_key,     sizeof(api_key));
	Sys_memcpy(baiduApiKey.secret_key, secret_key, 	sizeof(secret_key));
	Sys_memcpy(baiduApiKey.url, 	   url, 		sizeof(url));
	Sys_memcpy(&baiduApiKey.dev_pid,  &dev_pid,     sizeof(dev_pid));
	Sys_memcpy(baiduApiKey.scope, 	   scope,       sizeof(scope));
	Sys_memcpy(baiduApiKey.cuid, 	   cuid,        sizeof(cuid));
	Sys_memcpy(baiduApiKey.format, 	   format,      sizeof(format));
	Sys_memcpy(&baiduApiKey.rate,     &rate,        sizeof(dev_pid));
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

	p_audio = Sys_read_file(p_fileName);
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

