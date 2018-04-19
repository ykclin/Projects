#include "news_sender.h"

void CNewsSender::newsSender()
{
	WSADATA wsaData;
	SOCKET hSendSock;
	SOCKADDR_IN mulAdr;
	int timeLive=TTL;
	FILE* fp;
	char buf[BUF_SIZE];
	if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0)
	{
		cout<<"WSAStartup error"<<endl;
		return;
	}
	hSendSock = socket(PF_INET,SOCK_DGRAM,0);
	memset(&mulAdr,0,sizeof(mulAdr));
	mulAdr.sin_family=AF_INET;
	mulAdr.sin_addr.s_addr=inet_addr("224.1.1.2");
	mulAdr.sin_port=htons(atoi("9190"));

	setsockopt(hSendSock,IPPROTO_IP,IP_MULTICAST_TTL,(char*)&timeLive,sizeof(timeLive));

	if((fp = fopen("news.txt","r")) == NULL)
	{
		cout<<"open file error"<<endl;
		return ;
	}

	while(!feof(fp))
	{
		fgets(buf,BUF_SIZE,fp);
		sendto(hSendSock,buf,strlen(buf),0,(SOCKADDR*)&mulAdr,sizeof(mulAdr));
		Sleep(2000);
	}
	closesocket(hSendSock);
	WSACleanup();
	return;
}


void CNewsSender::newsReceiver()
{
	WSADATA wsaData;
	SOCKET hRecvSock;
	SOCKADDR_IN adr;
	struct ip_mreq joinAdr;
	char buf[BUF_SIZE];
	int strlen;

	if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0)
	{
		cout<<"WSAStartup error"<<endl;
		return;
	}
	hRecvSock = socket(PF_INET,SOCK_DGRAM,0);
	memset(&adr,0,sizeof(adr));
	adr.sin_family=AF_INET;
	adr.sin_addr.s_addr=htonl(INADDR_ANY);
	adr.sin_port=htons(atoi("9190"));

	if(bind(hRecvSock,(SOCKADDR*)&adr,sizeof(adr)) == SOCKET_ERROR)
	{
		cout<<"bind error"<<endl;
		return;
	}

	joinAdr.imr_multiaddr.s_addr = inet_addr("224.1.1.2");
	joinAdr.imr_interface.s_addr = htonl(INADDR_ANY);
	if(setsockopt(hRecvSock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(char*)&joinAdr,sizeof(joinAdr)) == SOCKET_ERROR)
	{
		cout<<"setsockopt error"<<endl;
		return;
	}

	while(1)
	{
		strlen = recvfrom(hRecvSock,buf,BUF_SIZE-1,0,NULL,0);
		if(strlen < 0)
			break;
		buf[strlen] = 0;
		fputs(buf,stdout);

	}
	closesocket(hRecvSock);
	WSACleanup();
	return;


}