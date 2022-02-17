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
	
	
	if(REV_TRUE != C_languageInterationWidget::readFeedbackProfile(&Interaction_Config))
	{
		printf("\033[31;1m失败 readFeedbackProfile\r\n");
		return REV_FAIL;
	}
	printf("\033[32;1m获取百度API钥匙\r\n");
	return REV_TRUE;
}

/*
**时间：22.2.12 22：48
**作者：田小花
**功能：获取语音识别设置配置
**输入：
     语音识别配置信息结构体
**返回：
     初始化状态值
*/
INTERACTION_CONFIG *C_languageInterationBaseBaidu::getInteractionConfig(INTERACTION_CONFIG *p_Interaction_Config) //获取语音识别的配置设置
{
	//INTERACTION_CONFIG * p_Interaction_Config = (INTERACTION_CONFIG *)Sys_malloc(sizeof(INTERACTION_CONFIG));
	
	memcpy(p_Interaction_Config, &Interaction_Config, sizeof(INTERACTION_CONFIG));
	
	printf("%s\n%s\n",p_Interaction_Config->BaiduApiConfig.api_key,p_Interaction_Config->BaiduApiConfig.secret_key);
	
	return p_Interaction_Config;
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
	printf("\033[32;1m获取音频success\r\n");
	return REV_TRUE;
}


/*
**时间：22.2.12 22：56
**作者：田小花
**功能：生成百度语音请求url
**输入：
     url配置
**返回：
     状态值
*/
unsigned int C_languageInterationBaseBaidu::getInteractionSpeedUrl(INTERACTION_CONFIG *p_Interaction_Config, char *p_url)
{	
    printf("getInteractionSpeedUrl!!\n:%s\n:%s\n:%s\n:%s\n", Interaction_Config.Url_Config.Url_pattern, Interaction_Config.Url_Config.Url_api, Interaction_Config.BaiduApiConfig.api_key, Interaction_Config.BaiduApiConfig.secret_key);
    snprintf(p_url, 200, Interaction_Config.Url_Config.Url_pattern, Interaction_Config.Url_Config.Url_api, Interaction_Config.BaiduApiConfig.api_key, Interaction_Config.BaiduApiConfig.secret_key);
    printf("url is: %s\n", p_url);

	return REV_TRUE;
}

unsigned int obtain_json_str(const char *json, const char *key, char *value, int value_size) 
{
    int len = 4 + strlen(key) + 1;
	
    char search_key[len];
	
	printf("obtain_json_str!!\n");
	
    snprintf(search_key, len, "\"%s\":\"\n", key);
		
    const char *start = strstr(json, search_key);
	
    if (start == NULL) // 没有找到
	{ 
        fprintf(stderr, "%s key not exist\n", key);
		
        return REV_FAIL;
    }
	
    start += strlen(search_key);
	
    const char *end = strstr(start, "\"");
		
    // 最大可复制的string
    int copy_size = (value_size < end - start) ? value_size : end - start;
	/*
    snprintf(value, copy_size + 1, "%s", start);
	*/
	printf("obtain_json_str 结束\n");
    return REV_TRUE;
}


// 解析json，获取某个key对应的value ;为了不引用第三方json库，仅仅做简单的字符串操作
// 正式使用请使用json库解析，json库解析推荐@see www.json.org
unsigned int parse_token(const char *response, const char *scope, char *token) 
{
	int MAX_TOKEN_SIZE = 100;
	unsigned int res;
    //  ====  获取 token字段 =========
    res = obtain_json_str(response, "access_token", token, MAX_TOKEN_SIZE);
	
    if (res != REV_TRUE) 
	{
        printf("parse token error: %s\n", response);
		
        return REV_URL_NONE;
    }

    // ==== 检查scope =========
    char scopes[400];
	
    res = obtain_json_str(response, "scope", scopes, 400);
	
    if (res != REV_TRUE) 
	{
        printf("parse scope error: %s\n", response);
        return REV_URL_NONE;
    }
    if (strlen(scope) > 0) 
	{
        char *scope_pos = strstr(scopes, scope);
		
        if (scope_pos == NULL) 
		{
            printf("scope： %s not exist in:%s \n", scope, response);
			
            return REV_URL_NONE;
        }
    }
    return REV_TRUE;
}



// libcurl 返回回调
size_t writefunc(void *ptr, size_t size, size_t nmemb, char **result) 
{
    size_t result_len = size * nmemb;
    int is_new = (*result == NULL);
    if (is_new) 
	{
        *result = (char *) malloc(result_len + 1);
        if (*result == NULL) 
		{
            printf("realloc failure!\n");
            return 1;
        }
        memcpy(*result, ptr, result_len);
        (*result)[result_len] = '\0';
    } 
	else 
	{
        size_t old_size = strlen(*result);
        *result = (char *) realloc(*result, result_len + old_size);
        if (*result == NULL) 
		{
            printf("realloc failure!\n");
            return 1;
        }
        memcpy(*result + old_size, ptr, result_len);
        (*result)[result_len + old_size] = '\0';
    }
    return result_len;
}


/*
**时间：22.2.12 22：56
**作者：田小花
**功能：获取百度返回数据
**输入：
     url配置
**返回：
     状态值
*/
unsigned int C_languageInterationBaseBaidu::getInteractionBaiduRecv(INTERACTION_CONFIG *p_Interaction_Config, char *p_url, char *p_BaiduTocken)//获取百度返回数据
{
	char *response = NULL;

    printf("url is: %s\n", p_url);
	/**/
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, p_url); // 注意返回值判读
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60); // 60s超时
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response); 

    CURLcode res_curl = curl_easy_perform(curl); 
	printf("res_curl:%d\n",res_curl);
	
    unsigned int res = REV_TRUE;
	
    if (res_curl != CURLE_OK) 
	{
        printf("perform curl error:%s\n",curl_easy_strerror(res_curl));
        res = REV_FAIL;
    } 
	else 
	{
        res = parse_token(response, p_Interaction_Config->BaiduApiConfig.scope, p_BaiduTocken); // 解析token，结果保存在token里

		if (res == REV_TRUE) 
		{
            printf("REV_TRUE token: %s of %s\n", p_BaiduTocken, response);
        }
    }
    free(response);
	
    curl_easy_cleanup(curl);
	/**/
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

