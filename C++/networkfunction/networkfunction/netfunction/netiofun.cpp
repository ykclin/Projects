#include "netiofun.h"


CNetIOFun::CNetIOFun()
{
	WSADATA wsaData;
	int err = WSAStartup(MAKEWORD(2,2),&wsaData);
	if(err != 0)
	{
		cout<<"init winsock failed"<<endl;
	}
}
CNetIOFun::~CNetIOFun()
{
	WSACleanup();
}
void CNetIOFun::testwritevreadv()
{
	//struct iovec vec[2];
}

void CNetIOFun::testgetsockopt()
{
	cout<<"------------------start getsockopt()---------------------------"<<endl;
	SOCKET tcpSock,udpSock;
	int sockType;
	int optLen;

	optLen = sizeof(sockType);
	tcpSock = socket(PF_INET,SOCK_STREAM,0);
	udpSock = socket(PF_INET,SOCK_DGRAM,0);
	cout<<"SOCK_STREAM:"<<SOCK_STREAM<<endl;
	cout<<"SOCK_DGRAM:"<<SOCK_DGRAM<<endl;

	int state = getsockopt(tcpSock,SOL_SOCKET,SO_TYPE,(char*)&sockType,&optLen);
	if(state == -1)
	{
		cout<< "getsockopt error"<<endl;
		return;
	}
	cout<<"sockType one:"<<sockType<<endl;

	state = getsockopt(udpSock,SOL_SOCKET,SO_TYPE,(char*)&sockType,&optLen);
	if(state == -1)
	{
		cout<< "getsockopt error"<<endl;
		return;
	}
	cout<<"sockType two:"<<sockType<<endl;

	int sendBuf,rcvBuf;
	optLen = sizeof(sendBuf);
	state = getsockopt(tcpSock,SOL_SOCKET,SO_SNDBUF,(char*)&sendBuf,&optLen);
	if(state == -1)
	{
		cout<< "getsockopt error"<<endl;
		return;
	}
	cout<<"SO_SENDBUF:"<<sendBuf<<endl;

	optLen = sizeof(rcvBuf);
	state = getsockopt(tcpSock,SOL_SOCKET,SO_RCVBUF,(char*)&rcvBuf,&optLen);
	if(state == -1)
	{
		cout<< "getsockopt error"<<endl;
		return;
	}
	cout<<"SO_RCVBUF:"<<rcvBuf<<endl;

	cout<<"------------------end getsockopt()---------------------------"<<endl;

}

void CNetIOFun::testsetsockopt()
{
	cout<<"------------------start getsockopt()---------------------------"<<endl;
	SOCKET sock;
	int sndBuf = 1024,rcvBuf = 1024*3;
	int state;
	int len;
    
	sock = socket(PF_INET,SOCK_STREAM,0);
	
	state = setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&sndBuf,sizeof(sndBuf));
	if(state == -1)
	{
		cout<<"setsockopt error"<<endl;
		return ;
	}

	int modifySndBuf;
	len = sizeof(sndBuf);
	state = getsockopt(sock,SOL_SOCKET,SO_SNDBUF,(char*)&modifySndBuf,&len);
	if(state == -1)
	{
		cout<<"getscokopt error"<<endl;
		return ;
	}
	cout<<"modify SO_SNDBUF:"<<modifySndBuf<<endl;

	state = setsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&rcvBuf,sizeof(rcvBuf));
	if(state == -1)
	{
		cout<<"setsockopt error"<<endl;
		return ;
	}

	int modifyRcvBuf;
	len = sizeof(rcvBuf);
	state = getsockopt(sock,SOL_SOCKET,SO_RCVBUF,(char*)&modifyRcvBuf,&len);
	if(state == -1)
	{
		cout<<"getscokopt error"<<endl;
		return ;
	}
	cout<<"modify SO_RCVBUF:"<<modifyRcvBuf<<endl;


}

void CNetIOFun::testgethostbyname()
{
	cout<<"------------------start gethostbyname()---------------------------"<<endl;
	//	struct hostent  
	//{  
	//    char *h_name;         //正式主机名  
	//    char **h_aliases;     //主机别名  
	//    int h_addrtype;       //主机IP地址类型：IPV4-AF_INET  
	//    int h_length;         //主机IP地址字节长度，对于IPv4是四字节，即32位  
	//    char **h_addr_list;   //主机的IP地址列表  
	//}; 
    const char* hostName = "www.baidu.com";
	struct hostent* hostAddr = gethostbyname(hostName);
	string addrType = "AF_INET";
	if(hostAddr->h_addrtype == AF_INET)
	{
		addrType = "AF_INET";
	}
	else
	{
		addrType = "AF_INET6";
	}
	cout<<"input host name:"<<hostName<<endl;
	cout<<"official name of host:"<<hostAddr->h_name<<endl;
	cout<<"host address type:"<<addrType<<endl;
	cout<<"length of address:"<<hostAddr->h_length<<endl;
	for(int i = 0;hostAddr->h_addr_list[i];i++)
	{
	   const char* addr = inet_ntoa(*(struct in_addr*)hostAddr->h_addr_list[i]);
	   cout<<"list of addresses:"<<addr<<endl;
	}
	cout<<"------------------end gethostbyname()---------------------------"<<endl;
}
void CNetIOFun::testgethostbyaddr()
{
	cout<<"------------------start gethostbyaddr()---------------------------"<<endl;
	SOCKADDR_IN addr;
	memset(&addr,0,sizeof(addr));
	const char* strAddr = "10.208.68.64";
	addr.sin_addr.s_addr = inet_addr(strAddr);
	struct hostent* hostAddr1 = gethostbyaddr((char*)&addr.sin_addr,4,AF_INET);
	if(!hostAddr1)
	{
		cout<< "gethostbyaddr failed" <<endl;
		return ;
	}
	string addrType;
	if(hostAddr1->h_addrtype == AF_INET)
	{
		addrType = "AF_INET";
	}
	else
	{
		addrType = "AF_INET6";
	}
	cout<<"input addr:"<<strAddr<<endl;
	cout<<"official name of host:"<<hostAddr1->h_name<<endl;
	cout<<"host address type:"<<addrType<<endl;
	cout<<"length of address:"<<hostAddr1->h_length<<endl;
	for(int i = 0;hostAddr1->h_addr_list[i];i++)
	{
	   const char* addr = inet_ntoa(*(struct in_addr*)hostAddr1->h_addr_list[i]);
	   cout<<"list of addresses:"<<addr<<endl;
	}

	cout<<"------------------end gethostbyaddr()---------------------------"<<endl;
}

