#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;

#define BUF_SIZE 1024
#define OPSZ 4

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
	
	fputs("please input opcnt:",stdout);
	scanf("%d",&opnd_cnt);
	opmsg[0] = (char)opnd_cnt;

	for(i =0 ; i < opnd_cnt; i++)
	{
		printf("Operand: %d: ", i+1);
		scanf("%d",(int*)&opmsg[i*OPSZ + 1]);
	}
	fgetc(stdin);
	fputs("Operator:",stdout);
	scanf("%c",&opmsg[opnd_cnt*OPSZ + 1]);
	send(clin_Soc,opmsg,opnd_cnt*OPSZ + 2,0);
	char result[BUF_SIZE];
	recv(clin_Soc,result,4,0);
	printf("Operation result:%s\n",result);

	closesocket(clin_Soc);
	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}