#ifndef LANDUAGE_INTERATION_WIDGET_H
#define LANDUAGE_INTERATION_WIDGET_H

#include "languageInclude.h"

typedef struct
{
	//char api_key[] = "ZUmYyI8ViFGDL5cpDEbC1hlA"; //田小花的账号
    // 填写网页上申请的APP SECRET 如 $secretKey="94dc99566550d87f8fa8ece112xxxxx"
    //char secret_key[] = "O9o1O213UgG5LFn0bDGNtoRN3VWl2du6"; //测试历程
    //char secret_key[] = "KcgQsVbBQFSTbq1Umj4EK9kw4Y2P8MvH";  //田小花的账号
    char api_key[200];
	char secret_key[300];
	char url[200]; // 可改为https
	int  dev_pid; //  1537 表示识别普通话，使用输入法模型。其它语种参见文档;
	char scope[200]; // # 有此scope表示有asr能力，没有请在网页里勾选，非常旧的应用可能没有
	char cuid[200]; //必填	用户唯一标识，用来计算UV值。建议填写能区分用户的机器 MAC 地址或 IMEI 码，长度为60字符以内
	char format[200]; // 文件后缀仅支持 pcm/wav/amr 格式，极速版额外支持m4a 格式
	int  rate;            // 采样率固定值
	//int lm_id;//测试自训练平台需要打开此注释
}Baidu_API_KEY;

//Baidu_API_KEY baiduApiKey;

class C_languageInterationWidget
{
private:

public:
	C_languageInterationWidget();
	~C_languageInterationWidget();

	
	
	static void sayMassage(char *pStr);
	static void sayWarning(); //提示音
	static void sayInterval();//间隔

	static unsigned int readFeedbackProfile(Baidu_API_KEY &baiduApiKey); //读取配置文件
	static unsigned int getRecordAudio(FILE *p_audio); //获取音频 录音
};

//为上层类的调用提供唯一接口
C_languageInterationWidget *GetLanguageInterationWidgetObj();

#endif
