#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;


class CNetIOFun
{
public:
	CNetIOFun();
	~CNetIOFun();
	void testwritevreadv();

	void testgetsockopt();
	void testsetsockopt();
	void testgethostbyname();
	void testgethostbyaddr();
};