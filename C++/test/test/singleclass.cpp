#include "singleclass.h"


SingleClass::CGarbo SingleClass::Garbo;

SingleClass* SingleClass::m_pSingleClass = new SingleClass();

 SingleClass* SingleClass::GetInstance()
 {
	return m_pSingleClass;
 }

     
SingleClass::SingleClass()    
{    
	a = 111;
    cout<<"contructure funcation"<<endl;    
}    
    
SingleClass::~SingleClass()    
{    
    cout<<"deconstructure funcation"<<endl;   
}    
 