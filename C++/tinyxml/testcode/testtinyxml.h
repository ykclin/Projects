#include <iostream>
#include <string>
#include "../tinyxml.h"
using namespace std;

#define MAKE_NULL_RETURN(ptr) \
	if (!ptr)                             \
	{                                     \
		cout<< "ptr is NULL" <<endl;      \
		throw "ptr is NULL";      \
	}  

class CTestTinyXml 
{
public:
    void testLoadFile();
	void testReplaceChild();
	void testGetText();
	void testSetValue();
	void testNextSibling();
	void testSaveFile();
	void testParse();
	void testLinkEndChild();
	void testXMLPrinter();

private:
	TiXmlElement* pRootEle;
	TiXmlDocument xmlDoc;

};