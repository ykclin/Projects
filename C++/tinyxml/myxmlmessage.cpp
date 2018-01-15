#include "myxmlmessage.h"

myXmlMessage::myXmlMessage(const char* formattedXmlMessage)
{
	const char* fileName = ".\\tmp.dat";
	FILE *fp;                     /*定义文件指针*/
    fp=fopen(fileName, "w");    /*建立一个文字文件只写*/
    fputs(formattedXmlMessage,fp);/*向所建文件写入一串字符*/
	//fprintf(fp, "%s", s);         /*向所建文件写一字符串*/
    //fputc(':', fp);               /*向所建文件写冒号:*/
    //fprintf(fp, "%d\n", i);       /*向所建文件写一整型数*/
    
    fclose(fp);  
	bool flag = xmlDoc.LoadFile(fileName);
	if (!flag)
	{
		cout<< "init myXmlMessage failed" << endl;
		throw "init myXmlMessage failed";
	}
	pRootNode = xmlDoc.RootElement();
	if(!pRootNode)
	{
		cout<< "init pRootNode failed" << endl;
		throw "init pRootNode failed";
	}
	int fileFlag = remove(fileName);
	if(fileFlag== -1)
	{
		cout<< "remove tmp xml file failed" << endl;
		throw "remove tmp xml file failed";
	}
	//MAKE_NULL_RETURN(pRootNode);
}
bool myXmlMessage::myXmlLoadFile(const char* xmlfileName)
{
	TiXmlDocument xmlDoc;
	bool flag = xmlDoc.LoadFile(xmlfileName);
	if (!flag)
	{
		cout<< "myXmlLoadFile failed" << endl;
		throw "myXmlLoadFile failed";
	}
	pRootNode = xmlDoc.RootElement();
	if(!pRootNode)
	{
		return false;
	}

	return true;
}
TiXmlNode* myXmlMessage::GetNodeByPath(TiXmlNode *parentNode, const char *nodePath)
{
	if(!nodePath)
    {
        throw "Node path cannot be NULL!";
    }
	if(!parentNode)
    {
        throw "Node cannot be NULL!";
    }
	const char* parentNodeName = parentNode->Value();
	if(strcmp(parentNodeName,nodePath) == 0)
	{
		return parentNode;
	}
	// split the nodePath to identify nodes and indexes.
    char *nodeName;    
    char path [SIZE_PATH];
    strcpy(path, nodePath);

	nodeName = strtok(path, "/");
    while(nodeName)
    {
        // check if index is specified. specified index example: Carrier[2] in "CarrierList/Carrier[2]/CarrierId"
        int nodeIndex = 1; // the nodeIndex is the index of a specified node name in its parent, default is 1.
        
        char *pLeftSquare = strstr(nodeName, "[");
        char *pRightSquare = strstr(nodeName, "]");
        if(pLeftSquare && pRightSquare && pRightSquare - pLeftSquare > 1)
        {
            // nodeName contains '[' and ']', get the inner string as index
            *pLeftSquare = NULL; // trim the []
            pLeftSquare++;
            *pRightSquare = NULL;
            nodeIndex = atoi(pLeftSquare); // convert to integer
            
            if(nodeIndex < 1) 
            {
                throw "Index cannot be less than 1";
            }
        }

		TiXmlNode * child = parentNode->FirstChild(nodeName);
		if(!child)
		{
			return NULL;
		}
		int index = 1;
		while(child && index < nodeIndex)
		{
			child = NextSameNameSibling(child);
			if(!child)
			{
				return NULL;
			}
			index++;
		}

		//go to next level
		parentNode = child;
		nodeName = strtok(NULL,"/");
	}

	return parentNode;
}
TiXmlNode* myXmlMessage::NextSameNameSibling(TiXmlNode* sibling)
{
	if(!sibling)
	{
		return NULL;
	}
	string oriName = sibling->Value();
	TiXmlNode* tarNode = sibling->NextSibling();
	while(tarNode)
	{
		string nodeName = tarNode->Value();
		if(oriName == nodeName)
		{
			return tarNode;
		}
		tarNode = tarNode->NextSibling();
	}
	return NULL;
}
const char* myXmlMessage::GetNodeText(const char *nodePath)
{
	TiXmlNode * node = GetNodeByPath(pRootNode, nodePath);
	if(!node)
	{
		return "";
	}
	else
	{
		TiXmlElement* pElement = node->ToElement();
		if(!pElement)
		{
			return "";
		}
		return pElement->GetText();
	}
}

void myXmlMessage::SetNodeText(const char *nodePath, const char *nodeText)
{
		TiXmlNode* tarNode = AddNode(nodePath);
		if(!tarNode)
		{
			cout << "AddNode failed"<<endl;
			return;
		}
		tarNode->Clear();
		tarNode->LinkEndChild(new TiXmlText(nodeText));
}

TiXmlNode* myXmlMessage::TiXmlNewElementAfterInster(TiXmlNode *parentNode,TiXmlNode *afterThis, const char * nodeName)
{
	if(!parentNode || !afterThis)
	{
		return NULL;
	}
	TiXmlNode* tmpNode = new TiXmlElement (nodeName);
	//Adds a child after the specified child. Returns a pointer to the new object or NULL if an error occured.
	TiXmlNode* newNode = parentNode->InsertAfterChild (afterThis, *tmpNode);
	return newNode;
}

TiXmlNode* myXmlMessage::AddNode(const char *nodePath)
{
	if(!nodePath)
    {
        throw "Node path cannot be NULL!";
    }
	if(!pRootNode)
    {
        throw "Node cannot be NULL!";
    }
	TiXmlNode *parentNode = pRootNode;
	// split the nodePath to identify nodes and indexes.
    char *nodeName;    
    char path [SIZE_PATH];
    strcpy(path, nodePath);

	nodeName = strtok(path, "/");
    while(nodeName)
    {
        // check if index is specified. specified index example: Carrier[2] in "CarrierList/Carrier[2]/CarrierId"
        int nodeIndex = 1; // the nodeIndex is the index of a specified node name in its parent, default is 1.
        
        char *pLeftSquare = strstr(nodeName, "[");
        char *pRightSquare = strstr(nodeName, "]");
        if(pLeftSquare && pRightSquare && pRightSquare - pLeftSquare > 1)
        {
            // nodeName contains '[' and ']', get the inner string as index
            *pLeftSquare = NULL; // trim the []
            pLeftSquare++;
            *pRightSquare = NULL;
            nodeIndex = atoi(pLeftSquare); // convert to integer
            
            if(nodeIndex < 1) 
            {
                throw "Index cannot be less than 1";
            }
        }
		
		TiXmlNode * child = parentNode->FirstChild(nodeName);
		if(!child)//找不到子节点
		{
			TiXmlNode* tmpNode = new TiXmlElement (nodeName);
			parentNode->LinkEndChild(tmpNode);
			child = tmpNode;
		}
		int index = 1;
		while(child && index < nodeIndex)
		{
			TiXmlNode* primaryNode = child;
			child = NextSameNameSibling(child);
			if(!child)//找不到同名兄弟节点
			{
				TiXmlNode* tmpNode = TiXmlNewElementAfterInster(parentNode,primaryNode,nodeName);
				//parentNode->LinkEndChild(tmpNode);
				child = tmpNode;
			}
			index++;
		}

		//go to next level
		parentNode = child;
		nodeName = strtok(NULL,"/");
	}

	return parentNode;
}

void myXmlMessage::Print()
{
	xmlDoc.Print();
}

int myXmlMessage::CountNodes(const char *nodePath)
{
	if(!nodePath || (strlen(nodePath) == 0))
	{
		return 0;
	}
	TiXmlNode* tarNode = GetNodeByPath(pRootNode,nodePath);
	if(!tarNode)
	{
		return 0;
	}
	const char* nodeName = tarNode->Value();
	TiXmlNode* parentNode = tarNode->Parent();
	if(!parentNode)
	{
		return 0;
	}
	int num = 0;
	TiXmlNode* child = parentNode->FirstChild(nodeName);
	while(child)
	{
		child = NextSameNameSibling(child);
		num++;
	}
	return num;
}

void myXmlMessage::Clear(const char *nodePath)
{
	if(!nodePath || (strlen(nodePath) == 0))
	{
		return ;
	}
	TiXmlNode* tarNode = GetNodeByPath(pRootNode,nodePath);
	if(!tarNode)
	{
		return ;
	}
	tarNode->Clear();
}

const char * myXmlMessage::ToXmlString()
{
	TiXmlPrinter *printer = new TiXmlPrinter();  
	//default  indent( "    " ), lineBreak( "\n" )
	printer->SetIndent("");
	printer->SetLineBreak("");
	pRootNode->Accept(printer);//保存该节点及其子节点到字符串  
	const char*  strXML = printer->CStr();  
	return strXML;
}
const char * myXmlMessage::ToXmlString(const char* indent)
{
	TiXmlPrinter *printer = new TiXmlPrinter();  
	//default  indent( "    " ), lineBreak( "\n" )
	printer->SetIndent(indent);
	printer->SetLineBreak(indent);
	pRootNode->Accept(printer);//保存该节点及其子节点到字符串  
	const char*  strXML = printer->CStr();  
	return strXML;
}

const char *myXmlMessage::GetNodeAttribute(TiXmlNode *node, const char *attrName)
{
	if(!node)
	{
		return NULL;
	}
	TiXmlElement* TiEle = node->ToElement();
	if(!TiEle)
	{
		return NULL;
	}
	const char* attrValue = TiEle->Attribute(attrName);

	return attrValue;
}

const char *myXmlMessage::GetNodeAttributeByPath(const char *nodePath, const char *attrName)
{
	TiXmlNode* tiNode = GetNodeByPath(pRootNode, nodePath);

	if(!tiNode)
	{
		return NULL;
	}

	TiXmlElement* TiEle = tiNode->ToElement();
	if(!TiEle)
	{
		return NULL;
	}
	const char* attrValue = TiEle->Attribute(attrName);

	return attrValue;
}

void myXmlMessage::SetNodeAttribute(TiXmlNode *node, const char *attrName, const char *attrValue)
{
	if(!node)
	{
		return ;
	}
	
	
	TiXmlElement* TiEle = node->ToElement();
	if(!TiEle)
	{
		return;
	}
	TiEle->SetAttribute(attrName,attrValue);
}

void myXmlMessage::SetNodeAttributeByPath(const char *nodePath, const char *attrName, const char *attrValue)
{
	TiXmlNode* tiNode = GetNodeByPath(pRootNode, nodePath);

	if(!tiNode)
	{
		return ;
	}
	TiXmlElement* TiEle = tiNode->ToElement();
	if(!TiEle)
	{
		return;
	}
	TiEle->SetAttribute(attrName,attrValue);
}

void myXmlMessage::RemoveNode(TiXmlNode *node)
{
	if(!node)
	{
		return;
	}
	TiXmlNode* TiParent = node->Parent();
	if(!TiParent)
	{
		return ;
	}
	TiParent->RemoveChild(node);
}

 void myXmlMessage::RemoveNodeByPath(const char *nodePath)
 {
	 TiXmlNode* tarNode = GetNodeByPath(pRootNode, nodePath);
	 if(!tarNode)
	 {
		return;
	 }
	RemoveNode(tarNode);
 }