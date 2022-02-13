#ifndef SCREEN_DISPLAY_APPLAY
#define SCREEN_DISPLAY_APPLAY

/*API里面没有线程，再应用里面启动Api里面的线程，
主函数会调用应用里面的线程启动此模块的主体功能，
其他模块调用Api实现对此模块的其他部分功能实现*/
class C_ScreenDisplaApplay
{
private:
    /* data */
public:
    C_ScreenDisplaApplay(/* args */);
    ~C_ScreenDisplaApplay();

    void UpdateWindow(); //窗口刷新
};



#endif
