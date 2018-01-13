#include <iostream>
#include <string>
#include <winsock2.h>
#include <fstream> 
#include <io.h>
using namespace std;

#define BUF_SIZE 1024
#define FILENAMESIZE 255
#define FILEPATHSIZE 248
bool IsExistFileInSystem(char* filename,string& fileFullPath);
int main()
{
	cout<<"start main function " <<endl;
	cout<<"start server..."<<endl;
	WSADATA wsaData;
	int err = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(err != 0)
	{
		cout<<"init winsock failed"<<endl;
	}
    SOCKET srv_Soc = socket(PF_INET,SOCK_STREAM,0);
	if(!srv_Soc)
	{
		cout<<"socket failed"<<endl;
	}
	sockaddr_in ser_address;
	memset(&ser_address,0,sizeof(ser_address));
	ser_address.sin_family = AF_INET;
	ser_address.sin_port = htons(9527);
	ser_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(srv_Soc,(struct sockaddr*)&ser_address,sizeof(ser_address)) == -1)
	{
		cout<<"bind failed"<<endl;
	}
	if(listen(srv_Soc,5) == -1)
	{
		cout<<"listen failed"<<endl;
	}
	sockaddr_in clin_address;
	memset(&clin_address,0,sizeof(clin_address));
	int len = sizeof(clin_address);
	SOCKET clin_Soc;
	if((clin_Soc = accept(srv_Soc,(struct sockaddr*)&clin_address,&len)) == -1)
	{
		cout<<"accept failed"<<endl;
		return 0;
	}
	
	char fileName[FILENAMESIZE];
	recv(clin_Soc,fileName,FILENAMESIZE,0);
	string fileFullPath;
	bool isExist = IsExistFileInSystem(fileName,fileFullPath);
	if(!isExist)
	{
		char sResult[100] = "1 file is not exist";
		send(clin_Soc, sResult, strlen(sResult) + 1, 0);
	}
	else
	{
		fstream fp;
		fp.open(fileFullPath.c_str(),ios::in);
		if(!fp.is_open())
		{
			cout<<"open file failed"<<endl;
			return 0;
		}
		char senMsg[BUF_SIZE];
		string oneLine;
		while(getline(fp,oneLine))//在C++中读取一行的getline函数是不读入文件换行符的，而gcc / g++ 中getline函数是读入换行符的
		{
			oneLine += "\r\n";//文件换行符
            const char* strOneLine = oneLine.c_str();
			strcpy(senMsg,strOneLine);
			int len = strlen(senMsg);//
			send(clin_Soc, senMsg, len, 0);//不发送字符串最后面的'\0'
			Sleep(3000);
        }
		fp.close();
		
	}
	
	closesocket(clin_Soc);
	closesocket(srv_Soc);

	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}

bool IsExistFileInSystem(char* filename,string& fileFullPath)
{
	if(!filename || !strlen(filename))
		return false;
	/*fileFullPath = getenv("FILEPATH");
	fileFullPath = fileFullPath + "//" + filename;*/
	fileFullPath = ".\\";
	fileFullPath += filename;

	int rValue = _access(fileFullPath.c_str(),0);//判断文件是否存在
	if(rValue == -1)
		return false;
	return true;
}
