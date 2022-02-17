#include <iostream>
#include <string>
#include <jsoncpp/json/json.h> //编译链接库g++ -o app main.cpp -ljsoncpp
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
参考
https://blog.csdn.net/tennysonsky/article/details/48809835?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164510934516780265459784%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164510934516780265459784&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-48809835.first_rank_v2_pc_rank_v29&utm_term=jsoncpp+%E8%AF%BB%E5%8F%96%E6%96%87%E4%BB%B6&spm=1018.2226.3001.4187
*/
void readFileJson(); //从文件中读取JSON，一个存储了JSON格式字符串的文件
 
int main(int argc, char *argv[]) 
{
	readFileJson();
	
	return 0;
}
 
//从文件中读取JSON
void readFileJson()
{
	Json::Reader reader;
	Json::Value root;
 
	//从文件中读取，保证当前文件有test.json文件
	ifstream in("Key.json", ios::binary);
	//in.open("test.json", ios::binary);
 
	if( !in.is_open() )  
	{ 
	cout << "Error opening file\n"; 
	return; 
	}
 
	/*
	//test.json内容如下：
	{
		"name":"Tsybius",
		"age":23,
		"sex_is_male":true,
		"partner":
		{
			"partner_name":"Galatea",
			"partner_age":21,
			"partner_sex_is_male":false
		},
		"achievement":["ach1","ach2","ach3"]
	}
	*/
 
	if(reader.parse(in,root))
	{
        //读取根节点信息
        string name = root["api_key"].asString();
        int age = root["dev_pid"].asInt();
    
        cout << "My name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
	}
	else
	{
	    cout << "parse error\n" << endl;	
	}
 
	in.close();
}