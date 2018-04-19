#include "testdemo.h"

void testWriteFile()
{
	string filePathName = ".\\1.txt";
	fstream fp;
	fp.open(filePathName.c_str(),ios::out|ios::trunc|ios::binary);
	if(!fp.is_open())
	{
		cout<<"open file failed"<<endl;
		//return 0;
	}
	if(!fp)
	{
		cout<<"open file failed"<<endl;
		//return 0;
	}
	string ttt="123";
	ttt += "\r\n";
	fp<<ttt<<endl;
	fp<<ttt<<endl;
	fp.close();
}