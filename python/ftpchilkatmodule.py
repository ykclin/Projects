
import sys
import chilkat
ftp = chilkat.CkFtp2()

#  Any string unlocks the component for the 1st 30-days.
success = ftp.UnlockComponent("Anything for 30-day trial")
if (success != True):
    print(ftp.lastErrorText())
    sys.exit()

ftp.put_Hostname("152.135.85.148")
ftp.put_Username("yanyan")
ftp.put_Password("qwer1234")

#  Connect and login to the FTP server.
success = ftp.Connect()
if (success != True):
    print(ftp.lastErrorText())
    sys.exit()

#  Change to the remote directory where the file will be uploaded.
success = ftp.ChangeRemoteDir("./systemlog")
if (success != True):
    print(ftp.lastErrorText())
    sys.exit()
localPath = "C:\\Users\\kyangx088571\\Desktop\\software\\python\\veryLargeFile.dat"
remoteFilename = "veryLargeFile.dat"
#  Upload in chunks of 10 million bytes.
chunkSize = 10000000
success = ftp.LargeFileUpload(localPath,remoteFilename,chunkSize)
if (success != True):
    print(ftp.lastErrorText())
    sys.exit()

success = ftp.Disconnect()

print("Large File Uploaded!")
