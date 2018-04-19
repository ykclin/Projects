#include "testmyXmlMessage.h"

void testGetNodeText()
{
	cout<<"---------------------------------myXmlMessage--------------------------"<<endl;

	const char* strXml3 = "<msg><msgBody><testList><test1>testa</test1><test2>testb</test2></testList><ruleType>Primary</ruleType><equipmentId>UTSCR01</equipmentId><currentLots>UC000031.06;UC000055.03;UC038938.100;UC038938.94</currentLots><toState>RUN</toState><fromFAB>B2</fromFAB><toFAB>B1</toFAB><eventName>TrackOut</eventName><txnComment /></msgBody></msg>";
	myXmlMessage XmlMessage(strXml3);
	XmlMessage.Print();
	string tmpp = XmlMessage.GetNodeText("msgBody/testList[1]/test1");
	cout<<tmpp <<endl;
	tmpp = XmlMessage.GetNodeText("msgBody/testList[1]/test2");
	cout<<tmpp <<endl;
	tmpp = XmlMessage.GetNodeText("msgBody/testList[2]/test1");
	cout<<tmpp <<endl;
}
void testSetNodeText()
{
	cout<<"------------------------SetNodeText---------------------"<<endl;
	const char* strXml3 = "<msg><msgBody><testList><test1>testa</test1><test2>testb</test2></testList><ruleType>Primary</ruleType><equipmentId>UTSCR01</equipmentId><currentLots>UC000031.06;UC000055.03;UC038938.100;UC038938.94</currentLots><toState>RUN</toState><fromFAB>B2</fromFAB><toFAB>B1</toFAB><eventName>TrackOut</eventName><txnComment /></msgBody></msg>";
	myXmlMessage XmlMessage(strXml3);

	XmlMessage.SetNodeText("msgBody/testList[1]/test2","testSetNodeText");
	XmlMessage.SetNodeText("msgBody/testList[1]/test3","test123");
	XmlMessage.SetNodeText("msgBody/testList[2]/test1","testAbc");
	XmlMessage.Print();
	XmlMessage.SetNodeText("msgBody/testList[2]/test2","testDef");
	XmlMessage.SetNodeText("msgBody/testList[2]/test3","testFg");
	XmlMessage.Print();
	cout<<"testList number: "<<XmlMessage.CountNodes("msgBody/testList")<<endl;
	cout<<"ruleType number: "<<XmlMessage.CountNodes("msgBody/ruleType")<<endl;
	cout<<"ToXmlString:"<<XmlMessage.ToXmlString()<<endl;
	cout<<"ToXmlString:"<<XmlMessage.ToXmlString("")<<endl;
}