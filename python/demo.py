print ("Hello, Python!");

def printme( str ):
	print (str);
	return;

#调用函数
print ("call user defined fun");
print ("call same fun too");

#全局变量
Money = 2000
def AddMoney():
   # 想改正代码就取消以下注释:
	global Money
	Money = Money + 1
 
print ( Money);
AddMoney();
print ( Money);

# 导入内置math模块
import math
 
content = dir(math)
 
print (content);

str = input("please input:");
print ("your input is: ", str);