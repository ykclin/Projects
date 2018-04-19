#ifndef _SINGLECLASS_
#define _SINGLECLASS_
#include <iostream>
using namespace std;

class SingleClass
{
public:
	static SingleClass* GetInstance();
	int a;
private:
	SingleClass();
	~SingleClass();
	SingleClass(const SingleClass& single);
	SingleClass& operator==(const SingleClass& single);

	static SingleClass* m_pSingleClass;
	class CGarbo //它的唯一工作就是在析构函数中删除CSingleton的实例
    {
        public:
            ~CGarbo()
            {
				 cout<<"CGarbo deconstructure funcation"<<endl;   
                if( SingleClass::m_pSingleClass )
                { 
					delete SingleClass::m_pSingleClass;
				    SingleClass::m_pSingleClass = NULL;
				}
			}
	};
    static CGarbo Garbo; //定义一个静态成员，程序结束时，系统会自动调用它的析构函数
};


#endif
