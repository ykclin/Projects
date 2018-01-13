import ftplib

#ftp 登陆
ftp = ftplib.FTP("152.135.85.148")
ftp.login("yanyan", "qwer1234")

#ftp.set_debuglevel(2) #打开调试
data = []
ftp.dir(data.append)
for line in data:
  print(line)

# fileList = ftp.nlst()
# for line in fileList:
  # print(line)

pathname = './systemlog'
ftp.cwd(pathname)  #设置FTP当前操作的路径
print(ftp.pwd())   #返回当前所在位置
ftp.cwd('..') 
print(ftp.pwd())

#下载文件
bufsize = 1024                #设置缓冲块大小
fp = open('yy.txt','wb')     #以写模式在本地打开文件
ftp.retrbinary('RETR yy.txt', fp.write, bufsize)   #接收服务器上文件并写入本地文件  RETR 固定写法不能省略
#ftp.set_debuglevel(0)         #关闭调试
fp.close()                    #关闭文件

#上传文件
RemoteFile = 'veryLargeFile.dat'
file_handler = open('veryLargeFile.dat', "rb")
ftp.cwd(pathname)
ftp.storbinary('STOR %s'%RemoteFile, file_handler, bufsize)
file_handler.close()

ftp.quit()
