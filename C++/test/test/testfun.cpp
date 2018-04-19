
#include "testfun.h"


int parseIndex(const char* pStr)
{
	int nodeIndex = 0;
   //char nodeName* = "list[5]"; //只可读，不可写  指针指向常量字符串"list[5]"
	//char nodeName[] = "list[5]"; //可读写  nodeName数组重新开辟空间存贮"list[5]"
	char str[20] = {0};
	strcpy_s(str,strlen(pStr)+1,pStr);
	
	    char *pLeftSquare = strstr(str, "[");
        char *pRightSquare = strstr(str, "]");
        if(pLeftSquare && pRightSquare && pRightSquare - pLeftSquare > 1)
        {
            // nodeName contains '[' and ']', get the inner string as index
            *pLeftSquare = NULL; // trim the [] start
            pLeftSquare++;
            *pRightSquare = NULL; // trim the [] end
            nodeIndex = atoi(pLeftSquare); // convert to integer
            //throw "Index cannot be less than 1";
            if(nodeIndex < 1) 
            {
                throw "Index cannot be less than 1";
            }
        }
		cout<<"string:"<<pStr<<",Index:"<<nodeIndex<<endl;
		//std::abort();
		return nodeIndex;
}


bool BigEnd()
{
	union endJudge
	{
		unsigned short unInt;
		char cChar[2];
	};
	endJudge end;
	end.unInt = 0x1234;
	printf("%#x\n",end.unInt);
	printf("%#x\n",end.cChar[0]);
	printf("%#x\n",end.cChar[1]);
	if(end.cChar[0] == 0x12)
	{
		printf("it is Big end\n");//低位地址存高位字节0x12 0x34
		return true;
	}
	printf("it is small end\n");//低位地址存低位字节 0x34 0x12
	return false;
}

string int2string(int num)
{
	std::stringstream ss;
	string str;
	ss<<num;
	ss>>str;
	//str.sprintf("%d",num);
	return str;
}

string dec2bin(unsigned int num)
{
	if(num == 0)
	{
		return "0";
	}
	string strBin;
	while(num > 0)
	{
		int tmp = num%2;
		string strTmp = int2string(tmp);
		strBin += strTmp;
		num = num/2;
	}
	
	reverse(strBin.begin(),strBin.end());
	
	return strBin;
}