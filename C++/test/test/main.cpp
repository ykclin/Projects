#include "baseclass.h"
#include "testfun.h"
#include <string>
#include <winsock2.h>
#include "List.h"
#include "singleclass.h"

typedef enum mxml_type_e		/**** The XML node type. ****/
{
  MXML_IGNORE = -1,			/* Ignore/throw away node @since Mini-XML 2.3@ */
  MXML_ELEMENT,				/* XML element with attributes */
  MXML_INTEGER,				/* Integer value */
  MXML_OPAQUE,				/* Opaque string */
  MXML_REAL,				/* Real value */
  MXML_TEXT,				/* Text fragment */
  MXML_CUSTOM				/* Custom data @since Mini-XML 2.1@ */
} mxml_type_t;

class x {};
class Y:public x
{
public:
	Y()
	{
		a=0;
	}
	//x d;
	int a;
	/*char b;
	double c;*/
};

struct A
{
	A()
	{
		a=0;
		b=0;
	}
    int a;
	int b;
	~A()
	{
	cout<<"~A"<<endl;}
};

struct B:public A
{
protected:
	int c;

};

void fun(class Y& y)
{
    y.a = 5;
}

void fun1(struct A& a)
{
    a.a = 4;
	a.b=3;
}

void fun2()
{
    cout<<"fun2"<<endl;
}

class Base
{
private://构造函数声明为private,那么该类不能被继承
	Base(){}
	~Base(){}
};

class drive
{
public:
	drive(){}
	~drive(){}
};

int myfun(int a,int b)
{
	return (a+b);
}

int myfun(int a)
{
	return a;
}

class M
{
public:
	int myfun(int a,int b)
	{
		return (a+b);
	}

	 int myfun(int a)
	{
		return a;
	}
};

class N:public M
{
public:
	 int myfun(int a)
	{
		return a+1;
	}
};

void bubbleSort(int* arr,int n)  
{  
    bool exchange = false;  
    for (int i = 0; i < n-1; i++)  
    {  
        exchange = false;  
        for (int j = 0; j < n - i -1; j++)  
        {  
            if (arr[j] > arr[j+1])//交换元素  
            {  
                int tmp = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = tmp;  
                exchange = true;//置exchange为有交换状态  
            }  
        } 

        if (!exchange)  
        {  
            break;//终止算法  
        }  
    }  
}  




int main()
{
	cout<<"start main function " <<endl;
	//BaseClass bc;
	//int sum = bc.Add(4,5);
	//cout<<"sum = " << sum <<endl;

	//mxml_type_t type1=MXML_OPAQUE;
	//cout<<type1<<endl;

	////GetDemoVec();
	//int index = parseIndex("list[8]");

	//testClass class11 = 5; //error 构造函数声明为 explicit
	testClass class1(5); //ok
	testClass class2(6);
	class2 = class1;
	cout<< class2.GetValue() <<endl;

	//BigEnd();
	//cout<<"start server..."<<endl;
	

	string aa = "aca\bhwb";
	string qa = "\x5C";
	unsigned int ia = aa[3];
	int bb = aa.find('');
	int bb2 = aa.find("\x5C");
	int bb3 = aa.find(ia);
	cout<<aa<<endl;
	aa = aa.replace(aa.find(ia),1,"v");
	cout<<aa<<endl;
	cout <<"empty class x sizeof(x)="<<sizeof(x)<<endl;
	cout <<"class Y sizeof(Y)="<<sizeof(Y)<<endl;
	B cb;
	cb.a = 5;
	cb.b=4;
	//cb.c = 3;
	Y y;
	A a;
	fun(y);
	fun1(a);
	fun2();
	fun2;
	char aa2[6] = "12345";
	cout<<"sizeof(aa)="<<sizeof(aa2)<<endl;
	cout<<"strlen(aa) = "<<strlen(aa2)<<endl;
	int abc[5]={1,2,3,4,5}; 
	int w1 = (int)(&abc);
	int w2 = (int)(&abc+1);
	int w3 = (int)(&abc+2);
	int w4 = (int)(&abc+3);
	int *ptr=(int *)(&abc+1);  
    printf("%d,%d\n",*(abc+1),*(ptr-1));  

	cout<<myfun(1,2)<<endl;
	cout<<myfun(1)<<endl;
	M *pM = new N();
	cout<<"pM->myfun(1,2)="<<pM->myfun(1,2)<<endl;
	cout<<"pM->mmyfun(4)="<<pM->myfun(4)<<endl;

	N n;
	//cout<<"n.myfun(1,2)="<<n.myfun(1,2)<<endl;//隐藏了
	cout<<"n.myfun(4)="<<n.myfun(4)<<endl;
	cout<<"sizeof(M)="<<sizeof(M)<<endl;
	cout<<"sizeof(N)="<<sizeof(N)<<endl;

	List li;
	li.insert(5);
	li.insert(6);
	li.insert(7);
	li.insert(8);
	li.travel();
	li.reverse();
	li.travel();

	int arr[5] = {5,4,3,2,1};
	bubbleSort(arr,5);
	static int a1;
	unsigned int a2 = 0x1<<4;
	unsigned int a3 = ~(0x1<<4);
	 a1 |= (0x1<<3);//将 a 第 3 位置 1  

	 SingleClass* psi = SingleClass::GetInstance();
	 cout<<psi->a<<endl;

	 BaseClass * bp = new BaseClass();
	 cout<<"BaseClass * bp:"<<sizeof(bp)<<endl;
	 cout<<"BaseClass :"<<sizeof(BaseClass)<<endl;

	 //BaseClass *pBa = new BaseClass();
	 delete bp;
	cout<<"end main function " <<endl;
	return 0;

}