#include <iostream>
#include <string>
#include <jsoncpp/json/json.h> //编译链接库g++ -o app main.cpp -ljsoncpp
//https://www.runoob.com/json/json-vs-xml.html
#include <string>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
using namespace std;
 
void readStrJson(); //从字符串中读取JSON 
int main(int argc, char *argv[]) 
{
	readStrJson();	
	return 0;
}
 
//从字符串中读取JSON
void readStrJson() 
{
	//字符串
  const char* str = 
      "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
      "\"born\":-100,\"died\":-44}";
  Json::Reader reader;
  Json::Value root;
 
  //从字符串中读取数据
  if(reader.parse(str,root))
  {
      string praenomen = root["praenomen"].asString();
      string nomen = root["nomen"].asString();
      string cognomen = root["cognomen"].asString();
      int born = root["born"].asInt();
      int died = root["died"].asInt();
 
      cout << praenomen + " " + nomen + " " + cognomen
          << " was born in year " << born 
          << ", died in year " << died << endl;
  }
  
}