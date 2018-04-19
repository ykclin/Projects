#include "baseclass.h"

static bool InitSticFun()
{
    cout<<"InitSticFun"<<endl;
    return true;
}

static bool sticVal = InitSticFun();//静态成员变量在main函数之前初始化

BaseClass::BaseClass()
{
	cout<<"BaseClass..."<<endl;
}
BaseClass::~BaseClass()
{
	cout<<"~BaseClass..."<<endl;
}

int BaseClass::Add(int a,int b )
{
	return (a+b);
}

//testClass::testClass()
//{
//}
testClass::~testClass()
{
}
testClass::testClass( const testClass& a)
{
	//
	n = a.n;
}
testClass& testClass::operator=(const testClass& a)
{
		if(this == &a)
			return *this;
		this->n = a.n;
		return (*this);
}

int testClass::GetValue()
{
	return n;
}

testClass::testClass(int a)
{
	n = a;
}

Widget& Widget::operator=(const Widget& rhs)
{
	if(this == &rhs)  //证同测试
		return *this;
	BitMap* pOrig = pb;
	pb = new BitMap(*rhs.pb);
	delete pOrig;
	return *this;
}


