import os
import shutil

#定义一个函数，带有4个参数
#fileName 表示要更新的文件名称
#beReplace 表示要被替换的内容
#toReplace 表示 替换后的内容
#flag 默认参数为 1 表示只替换第一个匹配到的字符串
# 如果参数为 flag = 'g' 则表示全文替换
def string_switch(fileName,beReplace,toReplace,flag):
    with open(fileName, "r", encoding="utf-8") as f:
        #readlines以列表的形式将文件读出
        lines = f.readlines()
 
    with open(fileName, "w", encoding="utf-8") as f_w:
        #定义一个数字，用来记录在读取文件时在列表中的位置
        n = 0
        #默认选项，只替换第一次匹配到的行中的字符串
        if flag == 1:
            for line in lines:
                if beReplace in line:
                    line = line.replace(beReplace,toReplace)
                    f_w.write(line)
                    n += 1
                    break
                f_w.write(line)
                n += 1
            #将剩余的文本内容继续输出
            for i in range(n,len(lines)):
                f_w.write(lines[i])
        #全局匹配替换
        elif flag == 'g':
            for line in lines:
                if beReplace in line:
                    line = line.replace(beReplace,toReplace)
                f_w.write(line)

				
# rootPath 文件路径
# beReplace 表示要被替换的内容
# toReplace 表示 替换后的内容
#flag 默认参数为 1 表示只替换第一个匹配到的字符串
# 如果参数为 flag = 'g' 则表示全文替换

def replace_filecontent_InPath(rootPath,beReplace,toReplace,flag=1):
	list = os.listdir(rootPath) #列出文件夹下所有的目录与文件
	for i in range(0,len(list)):
		for i in range(0,len(list)):
			path = os.path.join(rootPath,list[i])
			if os.path.isfile(path):
				string_switch(path,beReplace,toReplace,flag)


#string_switch("C:\\Users\\kyangx088571\\Desktop\\software\\python\\tmp.txt","primer","Primary","g")			
replace_filecontent_InPath("C:\\Users\\kyangx088571\\Desktop\\software\\python\\xmleg","MFG/Others/SMIC-BJ B2 &#x1A;&#x1A;&#x1A;&#x1A;CU FOUP","","g")