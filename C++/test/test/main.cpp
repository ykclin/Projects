#include "baseclass.h"
#include "testfun.h"
#include <string>
#include <winsock2.h>
typedef enum mxml_type_e		/**** The XML node type. ****/
{
  MXML_IGNORE = -1,			/* Ignore/throw away node @since Mini-XML 2.3@ */
  MXML_ELEMENT,				/* XML element with attributes */
  MXML_INTEGER,				/* Integer value */
  MXML_OPAQUE,				/* Opaque string */
  MXML_REAL,				/* Real value */
  MXML_TEXT,				/* Text fragment */
  MXML_CUSTOM				/* Custom data @since Mini-XML 2.1@ */
} mxml_type_t;

int main()
{
	cout<<"start main function " <<endl;
	BaseClass bc;
	int sum = bc.Add(4,5);
	cout<<"sum = " << sum <<endl;

	mxml_type_t type1=MXML_OPAQUE;
	cout<<type1<<endl;

	//GetDemoVec();
	int index = parseIndex("list[8]");

	//testClass class1 = 5; //error
	testClass class1(5); //ok
	testClass class2;
	class2 = class1;
	cout<< class2.GetValue() <<endl;

	BigEnd();
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
	}
	char recvMsg[100];
	recv(clin_Soc,recvMsg,strlen(recvMsg),0);
	cout<<"recvMsg:"<< recvMsg << endl;
	char* msg = "hello";
	int num = send(clin_Soc, msg, strlen(msg)+1, 0);
	if(num < 0)
	{
		cout<<"send msg failed"<<endl;
	}
	closesocket(srv_Soc);
	closesocket(clin_Soc);
	WSACleanup();
	cout<<"end main function " <<endl;
	return 0;

}