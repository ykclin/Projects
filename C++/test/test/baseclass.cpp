#include "baseclass.h"

static bool InitSticFun()
{
    cout<<"InitSticFun"<<endl;
    return true;
}

static bool sticVal = InitSticFun();//静态成员变量在main函数之前初始化

BaseClass::BaseClass()
{
	cout<<"BaseClass"<<endl;
}
BaseClass::~BaseClass()
{
	cout<<"~BaseClass"<<endl;
}

int BaseClass::Add(int a,int b )
{
	return (a+b);
}


