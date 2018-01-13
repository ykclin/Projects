#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;

#define BUF_SIZE 1024

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
	char recvMsg[BUF_SIZE];
	int msgLen = 0;
	while(1)
	{
		if((clin_Soc = accept(srv_Soc,(struct sockaddr*)&clin_address,&len)) == -1)
		{
			cout<<"accept failed"<<endl;
			return 0;
		}

		cout<<"accept one client:"<<clin_Soc<<endl;

		
		while((msgLen = recv(clin_Soc,recvMsg,BUF_SIZE,0)) > 0)//recv 是阻塞函数 会一直等着数据直到接收到数据
		{
			send(clin_Soc, recvMsg, msgLen, 0);
		}
		cout<<"close one client:"<<clin_Soc<<endl;
		closesocket(clin_Soc);
		if(strcmp(recvMsg,"qserver\n") == 0)
			break;

	}
	closesocket(srv_Soc);

	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}