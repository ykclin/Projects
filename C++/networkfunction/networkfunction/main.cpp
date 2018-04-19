#include "netfunction/netiofun.h"
#include "function/function.h"


void funDemo(int a,int* p = NULL);

int main()
{
	cout<<"start main function " <<endl;

	CNetIOFun netFun;
	netFun.testgetsockopt();
	netFun.testsetsockopt();
	netFun.testgethostbyname();
	//netFun.testgethostbyaddr();

	CFunction fun;
	fun.testspecialcharacter();
	fun.testMaxNum();
	
	int * p1 = NULL;
	int *p2;
	p2 = (int*)5;
	p2 = (int*)0;
	int a = 5;
	int b = 6;
	funDemo(a,&b);
	//funDemo(a);
	cout<<"end main function " <<endl;
	return 0;

}

void funDemo(int a,int* p )
{
	int add = (int)&p;
	*p = a;
	int v = 5;
}



