#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;

#define BUF_SIZE 1024
int main()
{
	cout<<"start main function " <<endl;
	cout<<"start client..."<<endl;

	char message[BUF_SIZE];
	int i = 0;
	int str_len = 0;

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
	/*char* msg = "hello server";
	int num = send(clin_Soc, msg, strlen(msg)+1, 0);
	if(num < 0)
	{
		cout<<"send msg failed"<<endl;
	}*/
	//测试TCP套接字 无数据边界特性
	//recv(clin_Soc,recvMsg,strlen(recvMsg),0);
	/*while((rcv_len = recv(clin_Soc,&recvMsg[i++],1,0)) > 0)
	{
		str_len += rcv_len;
	}*/
	while(1)
	{
		fputs("Input message(Q to quit):",stdout);
		fgets(message,BUF_SIZE,stdin);//stdin 输入的 enter键算一个字符 所以只敲一个enter键 message长度是2（''和\0）
		if(strcmp(message,"q\n") == 0 || strcmp(message,"Q\n") == 0)
			break;
		int strLen = send(clin_Soc, message,strlen(message)+1,0);
		int rcvLen = 0;
		while(rcvLen < strLen)
		{
			rcvLen += recv(clin_Soc,&message[rcvLen],BUF_SIZE,0);
		}
		
		cout<<"client recvMsg:"<< message;
		cout<<"client recvMsg Len:"<< rcvLen << endl;
		if(strcmp(message,"qserver\n") == 0 )
			break;
	}
	closesocket(clin_Soc);
	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}