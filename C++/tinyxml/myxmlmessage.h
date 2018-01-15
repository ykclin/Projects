#include <iostream>
#include <string>
#include "tinyxml.h"
using namespace std;

#define SIZE_PATH            512
#define MAKE_NULL_RETURN(ptr) \
	if (!ptr)                             \
	{                                     \
		cout<< "ptr is NULL" <<endl;      \
		throw "ptr is NULL";      \
	}   


class myXmlMessage
{
public:
	myXmlMessage(const char* formattedXmlMessage);
	bool myXmlLoadFile(const char* xmlfileName);
	const char* GetNodeText(const char *nodePath);
	void SetNodeText(const char *nodePath, const char *nodeText);
	int CountNodes(const char *nodePath);
	void SetNodeAttribute(TiXmlNode *node, const char *attrName, const char *attrValue);
	void SetNodeAttributeByPath(const char *nodePath, const char *attrName, const char *attrValue);
	const char *GetNodeAttribute(TiXmlNode *node, const char *attrName);
	const char *GetNodeAttributeByPath(const char *nodePath, const char *attrName);
	// remove a node and all of its children and release their memory
    // node is found by path.
    void RemoveNodeByPath(const char *nodePath);
    
    // remove a node and all of its children and release their memory
    void RemoveNode(TiXmlNode *node);

	const char *ToXmlString();
	const char *ToXmlString(const char* indent );
	void Print();
	void Clear(const char *nodePath);
private:
	TiXmlNode* GetNodeByPath(TiXmlNode *parentNode, const char *nodePath);
	TiXmlNode* AddNode(const char *nodePath);
	TiXmlNode* NextSameNameSibling(TiXmlNode* sibling);
	TiXmlNode* TiXmlNewElementAfterInster(TiXmlNode *parentNode,TiXmlNode *afterThis, const char * nodeName);

	TiXmlDocument xmlDoc;
	TiXmlElement* pRootNode;
};
