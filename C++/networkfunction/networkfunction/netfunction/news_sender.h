#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h> //for IP_MULTICAST_TTL option
using namespace std;

#define TTL 64
#define BUF_SIZE 30

class CNewsSender
{
public:
	void newsSender();
	void newsReceiver();
};