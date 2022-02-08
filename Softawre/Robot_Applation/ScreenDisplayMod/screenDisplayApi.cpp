#include "screenDisplayApi.h"

C_ScreenDisplayApi::C_ScreenDisplayApi(/* args */)
{
}

C_ScreenDisplayApi::~C_ScreenDisplayApi()
{
}

void C_ScreenDisplayApi::Begin()
{
    GetScreenDispayBaseObj()->setScreenInform();
}

void C_ScreenDisplayApi::Application()
{
    GetScreenDispayBaseObj()->setScreenText();
}