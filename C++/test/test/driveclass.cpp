#include <iostream>

using namespace std;
static bool InitdriveFun()
{

    cout<<"InitdriveFun"<<endl;
	
    return true;
}

static bool sticVal = InitdriveFun();//静态成员变量在main函数之前初始化