#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
using namespace std;
class BaseClass
{
public:
	BaseClass();
	~BaseClass();
	int Add(int a,int b );
	virtual int fun1(int a,int b ){return 0;}
	virtual int fun2(int a,int b ){return 0;}
	virtual int fun3(int a,int b ){return 0;}
	virtual int fun4(int a,int b ){return 0;}
	virtual int fun5(int a,int b ){return 0;}
	virtual int fun6(int a,int b ){return 0;}
	virtual int fun7(int a,int b ){return 0;}
	virtual int fun8(int a,int b ){return 0;}
private:
};

class testClass
{
public:
    //testClass();
	explicit testClass(const int a);
	testClass( const testClass& a);
	testClass& operator=(const testClass& a);
	~testClass();
	int GetValue();
	
private:
	int n;
};


class BitMap
{
public:
	BitMap(const int a,const int b):x(a),y(b){}
private:
	int x;
	int y;
};

class Widget
{
public:
	Widget& operator=(const Widget& rhs);//在operator= 中处理 "自我赋值"
private:
	BitMap* pb;
};

//void logCall(const std::)

#endif




