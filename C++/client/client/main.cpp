#include <iostream>
#include <string>
#include <winsock2.h>
#include <fstream> 
#include <io.h>
using namespace std;

#define BUF_SIZE 1024
#define FILENAMESIZE 255
#define FILEPATHSIZE 248

int main()
{
	cout<<"start main function " <<endl;
	cout<<"start client..."<<endl;

	char opmsg[BUF_SIZE];
	int opnd_cnt,i;

	WSADATA wsaData;
	int err = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(err != 0)
	{
		cout<<"init winsock failed"<<endl;
	}
    SOCKET clin_Soc = socket(PF_INET,SOCK_STREAM,0);
	if(!clin_Soc)
	{
		cout<<"socket failed"<<endl;
	}
	sockaddr_in ser_address;
	memset(&ser_address,0,sizeof(ser_address));
	ser_address.sin_family = AF_INET;
	ser_address.sin_port = htons(9527);
	ser_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(clin_Soc,(struct sockaddr*)&ser_address,sizeof(ser_address)) == -1)
	{
		cout<<"connect failed"<<endl;
		return 0;
	}
	char fileName[FILENAMESIZE];
	fputs("please input filename:",stdout);
	scanf("%s",fileName);

	send(clin_Soc,fileName,strlen(fileName) + 1,0);
	string filePathName = ".\\";
	filePathName += fileName;
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
	int rcvLen = 0;
	char result[BUF_SIZE];
	//recv是阻塞函数当server端关闭客户端的socket, recv函数结束，否则一直等待接受数据
	while((rcvLen = recv(clin_Soc,result,BUF_SIZE,0)) != 0) 
	{
		fp.write(result,rcvLen);
		//fp<<tmp<<endl;//不能这样用，处理不了'\0' 如果接受道德数据中间有'\0' 那么后面的数据写不进文件中去
	}
	fp.close();

	closesocket(clin_Soc);
	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}