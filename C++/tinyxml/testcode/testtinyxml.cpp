#include "testtinyxml.h"

void CTestTinyXml::testLoadFile()
{
	cout<<"----------------------testLoadFile--------------------"<<endl;
	const char* fileName = ".\\eg\\AutoCreatePart.xml";

	
	bool flag = xmlDoc.LoadFile(fileName);
	if (!flag)
	{
		cout<< "load xml file failed" << endl;
	}
	pRootEle = xmlDoc.RootElement();
	MAKE_NULL_RETURN(pRootEle);
	xmlDoc.Print();
}
void CTestTinyXml::testReplaceChild()
{
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

	//RemoveChild 
	TiXmlNode* application = prvHeader->FirstChild("replyApplication");
	MAKE_NULL_RETURN(pDest);
	prvHeader->RemoveChild(application);
	xmlDoc.Print();
}
void CTestTinyXml::testGetText()
{
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

	TiXmlNode* pResult = pRootEle->ReplaceChild(pMsgBody,*pReplyRoot);
	if (pResult != NULL)
	{
		xmlDoc.Print();
	}

}
void CTestTinyXml::testSetValue()
{
	cout<<"---------------- Set value------------------------"<< endl;
	TiXmlNode* pMsgHeader2 = pRootEle->FirstChild("msgHeader");
	MAKE_NULL_RETURN(pMsgHeader2);
	TiXmlElement* pSrvMethodNode = pMsgHeader2->FirstChild("srvMethod")->ToElement();
	//char* methodNode = "TestSetValue";
	pSrvMethodNode->SetAttribute("name","ykc"); 
	pSrvMethodNode->Clear();//先清除原来的值再设置新值
	pSrvMethodNode->LinkEndChild(new TiXmlText("TestSetValue"));
	//pSrvMethodNode->LinkEndChild(new TiXmlText(":ykc"));
	xmlDoc.Print();
	TiXmlNode* pMsgHeader = pRootEle->FirstChild("msgHeader");
	MAKE_NULL_RETURN(pMsgHeader);
	TiXmlElement* pSrvMethod = pMsgHeader->FirstChild("srvMethod")->ToElement();
	MAKE_NULL_RETURN(pSrvMethod);
	string strMethod = pSrvMethod->GetText();
	cout<< "srvMethod:" << strMethod << ":test"<<endl;
}
void CTestTinyXml::testNextSibling()
{
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
}
void CTestTinyXml::testSaveFile()
{
	cout<<"---------------------------------SaveFile --------------------------"<<endl;
	//pRootEle 指向<msg>
	TiXmlNode* pMsg = pRootEle->FirstChild("msg");
	if(!pMsg)
	{
		cout<<"can not find msg Node"<<endl;
	}
	const char* strSaveFile = "savetmpfile.xml";
	xmlDoc.SaveFile(strSaveFile);
}
void CTestTinyXml::testParse()
{
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
	string value = pRootEle2->Value();
	cout<<value<<endl;
}
void CTestTinyXml::testLinkEndChild()
{
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
}
void CTestTinyXml::testXMLPrinter()
{
	cout<<"---------------------------------Accept--------------------------"<<endl;
	const char* strXml4 = "<msg><msgBody>123</msgBody><testList><test1>&#x1A;</test1><test2>testb</test2></testList></msg>";
	TiXmlDocument tmpXmlDoc2;
	tmpXmlDoc2.Parse(strXml4);//parse 成功返回NULL
	tmpXmlDoc2.Print();
	TiXmlElement* pRootEle3 = tmpXmlDoc2.RootElement();
	TiXmlPrinter *printer = new TiXmlPrinter();  
	pRootEle3->Accept(printer );//保存该节点及其子节点到字符串  
	const char*  strXML = printer->CStr();  
	cout<<"strXML:"<<strXML<<endl; 

}