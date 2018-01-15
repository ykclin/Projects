#include "myxmlmessage.h"
#include <iostream>
#include <string>
#include <winsock2.h>
#include <fstream> 
#include <io.h>
using namespace std;


int main()
{
	const char* fileName = ".\\eg\\AutoCreatePart.xml";

	TiXmlDocument xmlDoc;
	bool flag = xmlDoc.LoadFile(fileName);
	if (!flag)
	{
		cout<< "load xml file failed" << endl;
	}
	TiXmlElement* pRootEle = xmlDoc.RootElement();
	MAKE_NULL_RETURN(pRootEle);
	xmlDoc.Print();

	cout<<"----------------ReplaceChild---------------"<<endl;
	TiXmlNode* prvHeader = pRootEle->FirstChild("rvHeader");
	MAKE_NULL_RETURN(prvHeader);
	TiXmlNode* pSource = prvHeader->FirstChild("source");
	MAKE_NULL_RETURN(pSource);
	TiXmlNode* pSourceClone = pSource->Clone();
	pSourceClone->SetValue("destination");
	TiXmlNode* pDest = prvHeader->FirstChild("destination");
	MAKE_NULL_RETURN(pDest);
	TiXmlNode* pDestClone = pDest->Clone();
	MAKE_NULL_RETURN(pDest);
	pDestClone->SetValue("source");
	xmlDoc.Print();
	cout<<endl;

	prvHeader->ReplaceChild(pSource,*pDestClone);
	prvHeader->ReplaceChild(pDest,*pSourceClone);
	TiXmlNode* application = prvHeader->FirstChild("replyApplication");
	MAKE_NULL_RETURN(pDest);
	prvHeader->RemoveChild(application);
	xmlDoc.Print();
	
	cout<<"---------------- GetText ------------------------"<< endl;
	TiXmlNode* pMsgHeader = pRootEle->FirstChild("msgHeader");
	MAKE_NULL_RETURN(pMsgHeader);
	TiXmlElement* pSrvMethod = pMsgHeader->FirstChild("srvMethod")->ToElement();
	MAKE_NULL_RETURN(pSrvMethod);

	TiXmlElement* pMsgOwner = pMsgHeader->FirstChild("msgOwner")->ToElement();
	MAKE_NULL_RETURN(pMsgOwner);
		

	string strMethod =  pSrvMethod->GetText();
	cout<< "srvMethod:" << strMethod <<endl;

	cout<<"---------------- LoadFile ------------------------"<< endl;

	string replyFile = ".\\eg\\" + strMethod + ".reply";
	const char* strReplyFile = replyFile.c_str();
	TiXmlDocument xmlReplyDoc;
	xmlReplyDoc.LoadFile(strReplyFile);

	TiXmlElement* pReplyRoot = xmlReplyDoc.RootElement();

	TiXmlNode* pMsgBody = pRootEle->FirstChild("msgBody");
	MAKE_NULL_RETURN(pMsgBody);
	/*string tmp = pMsgBody->ToElement()->GetText();
	cout<< tmp <<endl;*/
	TiXmlNode* pResult = pRootEle->ReplaceChild(pMsgBody,*pReplyRoot);
	if (pResult != NULL)
	{
		xmlDoc.Print();
	}

	cout<<"---------------- Set value------------------------"<< endl;
	TiXmlNode* pMsgHeader2 = pRootEle->FirstChild("msgHeader");
	MAKE_NULL_RETURN(pMsgHeader);
	TiXmlElement* pSrvMethodNode = pMsgHeader2->FirstChild("srvMethod")->ToElement();
	//char* methodNode = "TestSetValue";
	pSrvMethodNode->SetAttribute("name","ykc"); 
	pSrvMethodNode->Clear();//先清除原来的值再设置新值
	pSrvMethodNode->LinkEndChild(new TiXmlText("TestSetValue"));
	//pSrvMethodNode->LinkEndChild(new TiXmlText(":ykc"));
	xmlDoc.Print();
	strMethod = pSrvMethod->GetText();
	cout<< "srvMethod:" << strMethod << ":test"<<endl;

	cout<<"---------------------------------NextSibling--------------------------"<<endl;
	TiXmlNode* pMsgBody2 = pRootEle->FirstChild("msgBody");
	MAKE_NULL_RETURN(pMsgBody2);
	TiXmlNode* pCreateParts = pMsgBody2->FirstChild("createParts");
	MAKE_NULL_RETURN(pCreateParts);

	string value;
	TiXmlNode* pNode = pCreateParts->FirstChild();
	while(pNode)
	{
	    value = pNode->ToElement()->GetText();
		cout << "value:"<<value<<endl;
		pNode = pNode->NextSibling();
	}
	TiXmlNode* pCreateParts2 = (TiXmlNode*)pCreateParts->NextSibling();
	MAKE_NULL_RETURN(pCreateParts2);
	pNode = pCreateParts2->FirstChild();
	while(pNode)
	{
	    value = pNode->ToElement()->GetText();
		cout << "value:"<<value<<endl;
		pNode = pNode->NextSibling();
	}
	cout<<"---------------------------------SaveFile --------------------------"<<endl;
	//pRootEle 指向<msg>
	TiXmlNode* pMsg = pRootEle->FirstChild("msg");
	if(!pMsg)
	{
		cout<<"can not find msg Node"<<endl;
	}
	const char* strSaveFile = "savetmpfile.xml";
	xmlDoc.SaveFile(strSaveFile);
	cout<<"---------------------------------Parse XML string stream--------------------------"<<endl;
	const char* strXml2 = "<msg><msgBody>123</msgBody></msg>";
	TiXmlDocument tmpXmlDoc;
	const char* tmp1 = tmpXmlDoc.Parse(strXml2);//parse 成功返回NULL
	if(!tmp1)
	{
		cout<< "ptr error"<<endl;
	}
	tmpXmlDoc.Print();
	TiXmlElement* pRootEle2 = tmpXmlDoc.RootElement();
	MAKE_NULL_RETURN(pRootEle);
	value = pRootEle2->Value();
	cout<<value<<endl;
	cout<<"---------------------------------LinkEndChild --------------------------"<<endl;
	const char* strXml4 = "<msg><msgBody>123</msgBody><testList><test1>&#x1A;</test1><test2>testb</test2></testList></msg>";
	TiXmlDocument tmpXmlDoc2;
	tmpXmlDoc2.Parse(strXml4);//parse 成功返回NULL
	
	tmpXmlDoc2.Print();
	TiXmlElement* pRootEle3 = tmpXmlDoc2.RootElement();
	TiXmlNode* pParent =  pRootEle3->Parent();//rootNode 的parent value是空，但是指针不为空
	if(!pParent)
	{
		cout<<"it has not parent"<<endl;
	}
	if(pParent)
	{
		cout<<"it has  parent"<<endl;
	}
	TiXmlNode* pParent2 =  pParent->Parent();//rootNode 的parent的parent指针为空
	if(!pParent2)
	{
		cout<<"it has not parent1"<<endl;
	}
	if(pParent2)
	{
		cout<<"it has  parent1"<<endl;
	}
	TiXmlNode* pTestNode = pRootEle3->FirstChild("testList");
	TiXmlNode* tmpNode = new TiXmlElement ("test");
	tmpNode->LinkEndChild(new TiXmlText("TestSetValue"));
	//pTestNode->LinkEndChild(tmpNode);
	TiXmlNode *beforeThis  = pTestNode->FirstChild("test2");
	pTestNode->InsertBeforeChild (beforeThis, *tmpNode);
	tmpXmlDoc2.Print();
	TiXmlElement * 	TiEle = pRootEle3->FirstChildElement() ;//FirstChildElement() == FirstChild()->ToElement()
	const char * tmp2 = TiEle->GetText ();
	cout<<tmp2<<endl;
	//pTestNode->Clear();
	pRootEle3->RemoveChild(pTestNode);
	tmpXmlDoc2.Print();
	cout<<"---------------------------------Accept--------------------------"<<endl;
	TiXmlPrinter *printer = new TiXmlPrinter();  
	pRootEle3->Accept(printer );//保存该节点及其子节点到字符串  
	const char*  strXML = printer->CStr();  
	cout<<"strXML:"<<strXML<<endl; 

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

	cout<<"------------------------SetNodeText---------------------"<<endl;
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
	
	//char fileName1[20];
	/*fputs("please input filename:",stdout);
	scanf("%s",fileName1);*/
	//fileName1[strlen(fileName1)]='\0';
	string filePathName = ".\\1.txt";
	//filePathName += fileName1;
	fstream fp;
	fp.open(filePathName.c_str(),ios::out|ios::trunc|ios::binary);
	if(!fp.is_open())
	{
		cout<<"open file failed"<<endl;
		//return 0;
	}
	if(!fp)
	{
		cout<<"open file failed"<<endl;
		//return 0;
	}
	string ttt="123";
	ttt += "\r\n";
	fp<<ttt<<endl;
	fp<<ttt<<endl;
	fp.close();
    cout<<"---------------------------test unicode---------------------"<<endl;
	#if defined UNICODE
       std::cout << sizeof(L"aaa") <<endl;
       #endif
	printf("%s\n","你好");
	char tmp11[7] = "中文";
	string tmp22 = tmp11;
	cout<<tmp22<<endl;
	string strMsgOwner =  pMsgOwner->GetText();
	cout<< "msgOwner:" << strMsgOwner <<endl;
	if(tmp22 == strMsgOwner)
	{
		cout<<"==:"<<tmp22<<endl;
	}
	const char* psa = "A汉字ABC";
   const wchar_t* psw = L"W汉字ABC";
   
	return 0;
}