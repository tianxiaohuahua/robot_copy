#include "languageInteractionBaseBaidu.h"

C_languageInterationBaseBaidu::C_languageInterationBaseBaidu()
{
	GetLanguageInterationWidgetObj();
}

C_languageInterationBaseBaidu::~C_languageInterationBaseBaidu()
{

}

/*
**时间：22.2.12 22：48
**作者：田小花
**功能：对语音识别的基础设置进行初始化
**输入：
     无
**返回：
     初始化状态值
*/
unsigned int C_languageInterationBaseBaidu::languageBaseInit()
{
	Baidu_API_KEY baiduApiKey;
		
	if(REV_TRUE != C_languageInterationWidget::readFeedbackProfile(baiduApiKey))
	{
		printf("\033[31;1m失败 readFeedbackProfile\r\n");
		return REV_FAIL;
	}
	
	printf("\033[32;1m获取百度API钥匙\r\n");
/*
	 // 需要识别的文件
    char *filename = "16k.wav";

    config->file= fopen(filename, "r");
    if (config->file == NULL) {
        //文件不存在
        char cwd[200];
        getcwd(cwd,sizeof(cwd));
        snprintf(g_demo_error_msg, BUFFER_ERROR_SIZE,
                 "current running directory does not contain file %s, %s", filename, cwd);
        return ERROR_ASR_FILE_NOT_EXIST;
    }
	*/

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
unsigned int C_languageInterationBaseBaidu::getInteractionAudio(FILE *p_audio)
{	
	if(REV_FILE_NULL == C_languageInterationWidget::getRecordAudio(p_audio)) //获取音频 录音
	{
		printf("\033[31;1m失败 getRecordAudio 没有音频文件\r\n ");
		return REV_FILE_NULL;
	}
	printf("\033[32;1m获取音频\r\n");
	return REV_TRUE;
}



char *C_languageInterationBaseBaidu::getInteractionQuestion()
{

}


void C_languageInterationBaseBaidu::setInterationAnswer()
{
	char* str = "回答";
	C_languageInterationWidget::sayWarning();
	C_languageInterationWidget::sayInterval();
	C_languageInterationWidget::sayMassage(str);
	C_languageInterationWidget::sayInterval();	
}

void C_languageInterationBaseBaidu::setInteractionRepetition()
{
	
}

