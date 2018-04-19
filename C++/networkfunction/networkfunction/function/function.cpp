#include "function.h"

void CFunction::testspecialcharacter()
{
	string aa = "aca\1hwb";
	int m = 92;
	aa += m;
	unsigned int ia = aa[3];
	int bb3 = aa.find(m);
	cout<<aa<<endl;
	aa = aa.replace(aa.find(m),1,"v");
	cout<<aa<<endl;
}

void CFunction::testMaxNum()
{
	int iInt = 0x7fffffff;
	unsigned int uInt = 0xffffffff;
	
	cout<<iInt<<endl;
	cout<<uInt<<endl;

	iInt+=1;
	cout<<iInt<<endl;
}