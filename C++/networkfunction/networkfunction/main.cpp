#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;


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

	cout<<"------------------gethostbyname()---------------------------"<<endl;
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
	cout<<"official name of host:"<<hostAddr->h_name<<endl;
	cout<<"host address type:"<<addrType<<endl;
	cout<<"length of address:"<<hostAddr->h_length<<endl;
	for(int i = 0;hostAddr->h_addr_list[i];i++)
	{
	   const char* addr = inet_ntoa(*(struct in_addr*)hostAddr->h_addr_list[i]);
	   cout<<"list of addresses:"<<addr<<endl;
	}

	cout<<"------------------gethostbyaddr()---------------------------"<<endl;
	SOCKADDR_IN addr;
	memset(&addr,0,sizeof(addr));
	const char* strAddr = "10.208.68.64";
	addr.sin_addr.s_addr = inet_addr(strAddr);
	struct hostent* hostAddr1 = gethostbyaddr((char*)&addr.sin_addr,4,AF_INET);
	if(!hostAddr1)
	{
		cout<< "gethostbyaddr failed" <<endl;
		return 0;
	}
	if(hostAddr1->h_addrtype == AF_INET)
	{
		addrType = "AF_INET";
	}
	else
	{
		addrType = "AF_INET6";
	}
	cout<<"official name of host:"<<hostAddr1->h_name<<endl;
	cout<<"host address type:"<<addrType<<endl;
	cout<<"length of address:"<<hostAddr1->h_length<<endl;
	for(int i = 0;hostAddr1->h_addr_list[i];i++)
	{
	   const char* addr = inet_ntoa(*(struct in_addr*)hostAddr1->h_addr_list[i]);
	   cout<<"list of addresses:"<<addr<<endl;
	}
	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}



