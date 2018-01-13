#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;

#define BUF_SIZE 1024
#define OPSZ 4
int calculate(int opcnt,int opnds[],char op);
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
	
	char cOpcnt;
	recv(clin_Soc,&cOpcnt,1,0);
	int opcnt = cOpcnt;
	char recvMsg[BUF_SIZE];
	int rcv_len = 0;
	while(rcv_len < (opcnt*OPSZ +1))
	{
		int len = recv(clin_Soc,&recvMsg[rcv_len],BUF_SIZE-1,0);
		rcv_len += len;
	}
	int result = calculate(opcnt,(int*)recvMsg,recvMsg[rcv_len-1]);
	char sResult[4] = "";
	sprintf(sResult,"%d",result);
	send(clin_Soc, sResult, sizeof(sResult), 0);
	closesocket(clin_Soc);
	closesocket(srv_Soc);

	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}

int calculate(int opcnt,int opnds[],char op)
{
	int result = opnds[0];
	switch(op)
	{
	case '+':
		for(int i = 1; i < opcnt; i++)  result += opnds[i];
		break;
	case '-':
		for(int i = 1; i < opcnt; i++) result -= opnds[i];
		break;
	case '*':
		for(int i = 1; i < opcnt; i++) result *= opnds[i];
		break;
	}

	return result;
}