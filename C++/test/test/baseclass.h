#include <iostream>
using namespace std;
class BaseClass
{
public:
	BaseClass();
	~BaseClass();
	int Add(int a,int b );
private:
};

class testClass
{
public:
    testClass(){}
	explicit testClass(int a)
	{
		n = a;
	}
	testClass::testClass( const testClass& a)
	{
		//
		n = a.n;
	}
	testClass& operator=(const testClass& a)
	{
		if(this == &a)
			return *this;
		this->n = a.n;
		return (*this);
	}

	~testClass()
	{}
	int GetValue()
	{
		return n;
	}
private:
	int n;
};

