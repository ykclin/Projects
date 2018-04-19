using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;
using System.IO;
using System.Threading;




namespace OCXTester
{

    public partial class MessageSimulator : Form
    {
        public MessageSimulator()
        {
            InitializeComponent();
            
        }

        private bool status;
        private int errorCode=150000;
        private string errorInfo = string.Empty;
        private string replyMSg = string.Empty;
        private string replyFolder = string.Empty;
        private string sendFolder = string.Empty;
        private bool delayReplyFlag = false;
        private int totalNum = 0;
        Dictionary<string, Dictionary<string, string>> allFilm = new Dictionary<string, Dictionary<string, string>>();
        Dictionary<KeyValuePair<int, string>, string> replyMsgSet = new Dictionary<KeyValuePair<int, string>, string>();
        string dateTime = DateTime.Now.ToString("hh:mm:ss ");

        //function
        private void MessageSimulator_Load(object sender, EventArgs e)
        {
            InitUiParam();
            this.axTibcoOCX1.AdvisoryMessage += new AxTIBCOOCXLib._DTibcoOCXEvents_AdvisoryMessageEventHandler(axTibcoOCX1_AdvisoryMessage);
            this.axTibcoOCX1.ConnectionFailed += new AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionFailedEventHandler(axTibcoOCX1_ConnectionFailed);
            this.axTibcoOCX1.ConnectionLost += new AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionLostEventHandler(axTibcoOCX1_ConnectionLost);
            this.axTibcoOCX1.ConnectionMade += new AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionMadeEventHandler(axTibcoOCX1_ConnectionMade);
            this.axTibcoOCX1.BroadcastReceived += new AxTIBCOOCXLib._DTibcoOCXEvents_BroadcastReceivedEventHandler(axTibcoOCX1_BroadcastReceived);
            this.axTibcoOCX1.MessageReceived += new AxTIBCOOCXLib._DTibcoOCXEvents_MessageReceivedEventHandler(axTibcoOCX1_MessageReceived);

        }
        private void InitUiParam()
        {
            MappingType a;
            
            Dictionary<string, string> film = new Dictionary<string, string>();

            //string iniFilePath = @"C:\Documents and Settings\Admin\Desktop\YKC\xmleg\app.ini";
            string iniFilePath = @".\app.ini";
            StreamReader objReader = new StreamReader(iniFilePath);
            string strLine = "";
            string strTitle = "";
            strLine = objReader.ReadLine();
            string tmpKey = "";
            string tmpValue = "";
            getKeyAndValue(strLine, ref tmpKey, ref tmpValue);
            strTitle = tmpValue;
            strLine = objReader.ReadLine();
            while (strLine != null)
            {
                if (strLine.Contains("serviceTitle"))
                {
                    Dictionary<string, string> tmpFilm = new Dictionary<string, string>(film);
                    allFilm.Add(strTitle, tmpFilm);
                    
                    film.Clear();
                    getKeyAndValue(strLine, ref tmpKey, ref tmpValue);
                    strTitle = tmpValue;
                    strLine = objReader.ReadLine();
                    continue;
                }
                if (!strLine.Contains("="))
                {
                    strLine = objReader.ReadLine();
                    continue;
                }
                string key = "";
                string value = "";
                getKeyAndValue(strLine, ref key, ref value);
                film.Add(key, value);
                strLine = objReader.ReadLine();
            }
            allFilm.Add(strTitle, film);
            //film.Clear();

            int i = 0;
            foreach (var item in allFilm)
            {
                if (i == 0)
                {
                    string tt = item.Key;
                    //this.sevices.Items.Add(tt);
                    this.sevices.Text = tt;
                    film = item.Value;
                    string getVal = "";
                    if (film.TryGetValue("Service", out getVal))
                    {
                        this.ServiceText.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("Network", out getVal))
                    {
                        this.NetworkText.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("Deamon", out getVal))
                    {
                        this.DaemonText.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("Timout", out getVal))
                    {
                        this.TimoutText.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("ReplyFolder", out getVal))
                    {
                        this.replyFolder = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("SendFolder", out getVal))
                    {
                        this.sendFolder = getVal;
                        this.filePath.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("ListenSubject", out getVal))
                    {
                        this.LSubjectText.Text = getVal;
                    }

                    getVal = "";
                    if (film.TryGetValue("TargetSubject", out getVal))
                    {
                        this.TSubjectText.Text = getVal;
                    }
                    break;
                }
                i++;
            }
            

            objReader.Close();

            


        }
        private void getKeyAndValue(string strmsg, ref string key, ref string value)
        {

            if (strmsg == null)
                return;
            string tar = "=";
            //char[] removeTar = {' '};
            //strmsg.Trim(removeTar);
            int len = strmsg.Length;
            int index = strmsg.LastIndexOf(tar);
            key = strmsg.Substring(0, index);
            value = strmsg.Substring(index + 1, len - index - 1);
        }
        private string FormatXml(string sUnformattedXml)
        {
            XmlDocument xd = new XmlDocument();
            xd.LoadXml(sUnformattedXml);
            StringBuilder sb = new StringBuilder();
            StringWriter sw = new StringWriter(sb);
            XmlTextWriter xtw = null;
            try
            {
                xtw = new XmlTextWriter(sw);
                xtw.Formatting = Formatting.Indented;
                xtw.Indentation = 1;
                xtw.IndentChar = '\t';
                xd.WriteTo(xtw);
            }
            finally
            {
                if (xtw != null)
                    xtw.Close();
            }
            return sb.ToString();
        }
        private bool parseAndPrepareXml(string xmlMessage, ref string replyMessage, ref string replyaddress)
        {
            //初始化一个xml实例
            XmlDocument receiveXmlDoc = new XmlDocument();
            try
            {
                //加载xml
                receiveXmlDoc.LoadXml(xmlMessage);
                //replace source and destination
                XmlNode sourceNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/source");
                XmlNode destinationNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/destination");
                //destinationNode.InsertAfter(sourceNode, destinationNode);
                XmlNode sourceapplicationNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/source/application");
                XmlNode cloneapplicationNode = sourceapplicationNode.Clone();
                XmlNode sourcemsgBusNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/source/msgBus");
                XmlNode clonemsgBusNode = sourcemsgBusNode.Clone();
                XmlNode sourcedomainNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/source/domain");
                XmlNode clonedomainNode = sourcedomainNode.Clone();
                XmlNode sourceaddressNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/source/address");
                XmlNode cloneaddressNode = sourceaddressNode.Clone();

                XmlNode destinationapplicationNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/destination/application");
                XmlNode clonedestinationapplicationNode = destinationapplicationNode.Clone();
                XmlNode destinationmsgBusNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/destination/msgBus");
                XmlNode clonedestinationmsgBusNode = destinationmsgBusNode.Clone();
                XmlNode destinationdomainNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/destination/domain");
                XmlNode clonedestinationdomainNode = destinationdomainNode.Clone();
                XmlNode destinationaddressNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/destination/address");
                XmlNode clonedestinationaddressNode = destinationaddressNode.Clone();

                sourceNode.ReplaceChild(clonedestinationapplicationNode, sourceapplicationNode);
                sourceNode.ReplaceChild(clonedestinationmsgBusNode, sourcemsgBusNode);
                sourceNode.ReplaceChild(clonedestinationdomainNode, sourcedomainNode);
                sourceNode.ReplaceChild(clonedestinationaddressNode, sourceaddressNode);

                destinationNode.ReplaceChild(cloneapplicationNode, destinationapplicationNode);
                destinationNode.ReplaceChild(clonemsgBusNode, destinationmsgBusNode);
                destinationNode.ReplaceChild(clonedomainNode, destinationdomainNode);
                destinationNode.ReplaceChild(cloneaddressNode, destinationaddressNode);

                //remove replyApplication
                XmlNode replyApplicationNode = receiveXmlDoc.SelectSingleNode("/msg/rvHeader/replyApplication");
                XmlNode address = replyApplicationNode.LastChild;
                if (replyApplicationNode.ChildNodes.Count > 2)
                {
                    for (int i = replyApplicationNode.ChildNodes.Count - 1; i > 1; i--)
                    {
                        replyApplicationNode.RemoveChild(replyApplicationNode.ChildNodes.Item(i));
                    }
                }
                replyaddress = address.InnerText;
            }
            catch (Exception ex)
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message);
                return false;

            }
            //rvHeader.ReplaceChild(destinationNode, sourceNode);
            //find reply file

            //modify retCode retMsg value
            XmlNode retCodeNode = receiveXmlDoc.SelectSingleNode("/msg/msgHeader/retCode");
            if (retCodeNode == null)
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText(dateTime + "XML File retCode is Error " + System.Environment.NewLine);
                return false;
            }
            retCodeNode.InnerText = "0";
            if (this.retCode.Text != "")
            {
                retCodeNode.InnerText = this.retCode.Text;
            }

            XmlNode retMsgNode = receiveXmlDoc.SelectSingleNode("/msg/msgHeader/retMsg");
            if (retMsgNode == null)
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText(dateTime + "XML File retMsg is Error " + System.Environment.NewLine);
                return false;
            }
            if (this.retMsg.Text != "")
            {
                retMsgNode.InnerText = this.retMsg.Text;
            }


            XmlNode srvMethodNode = receiveXmlDoc.SelectSingleNode("/msg/msgHeader/srvMethod");
            if (srvMethodNode == null)
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText(dateTime + "XML File srvMethodNode is Error " + System.Environment.NewLine);
                return false;
            }

            //获取该节点的值（即：InnerText）
            string srvMethodText = srvMethodNode.InnerText;
            string replyFileName = srvMethodText + ".reply";
            string filePathTmp = this.replyFolder;
            if (this.replyMethod.Text != "")
            {
                srvMethodNode.InnerText = this.replyMethod.Text;
            }
            filePathTmp = filePathTmp + replyFileName;
            //get
            string filePath = "";
            GetCorrectFileName(filePathTmp, ref filePath);
            if (!File.Exists(filePath))
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText(dateTime + ":" + filePath + " is not access " + System.Environment.NewLine);
                return false;
            }

            try
            {


                //replyxmlmsgbody
                XmlDocument replyXmlDoc = new XmlDocument();
                replyXmlDoc.Load(filePath);

                string replyInnerXml = replyXmlDoc.InnerXml;
                XmlNode msgNode = receiveXmlDoc.SelectSingleNode("/msg");
                XmlNode receiveMsgBodyNode = receiveXmlDoc.SelectSingleNode("/msg/msgBody");
                msgNode.RemoveChild(receiveMsgBodyNode);

                string receiveInnerXml = receiveXmlDoc.InnerXml;

                //remove </msg> string
                string tar = "</msg>";
                int index = receiveInnerXml.LastIndexOf(tar);
                int len = tar.Length;
                string msg = receiveInnerXml.Substring(index, len);
                receiveInnerXml = receiveInnerXml.Remove(index, len);

                receiveInnerXml = receiveInnerXml + replyInnerXml + tar;

                //assign
                replyMessage = receiveInnerXml;
            }
            catch (Exception ex)
            {
                this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message);
                return false;

            }
            return true;
        }
        private void GetCorrectFileName(string fileName, ref string refFileName)
        {
            if (this.replyIndex.Checked == true)
            {
                string strIndex = this.replyIndexedit.Text;
                int iReplyindex = 0;
                int.TryParse(strIndex, out iReplyindex);
                refFileName = fileName + "." + strIndex;
                iReplyindex++;
                strIndex = iReplyindex.ToString();

                this.replyIndexedit.Text = strIndex;
            }
            else
            {
                refFileName = fileName;
            }
        }
        private bool getInboxFromAddress(string replyaddress, ref string replyInbox)
        {

            if (replyaddress == "_INBOX")
            {
                replyInbox = this.axTibcoOCX1.GetInbox();
                return true;
            }
            return false;
        }
        private void foreachSendMsg()
        {
            foreach (var item in replyMsgSet)
            {
                this.txtLog.AppendText(dateTime + "replyaddress: " + item.Key.Value + System.Environment.NewLine);
                this.txtLog.AppendText(dateTime + "reply messages: " + item.Value + System.Environment.NewLine);
                status = this.axTibcoOCX1.SendNoReply(item.Key.Value, item.Value);

                if (status != true)
                {
                    this.axTibcoOCX1.GetError(ref errorCode, ref errorInfo);
                    this.txtLog.SelectionColor = Color.Red;
                    this.txtLog.AppendText("Error info is:" + errorCode.ToString() + errorInfo);   //Send message failed. Print the error code and error information.
                }
            }

            replyMsgSet.Clear();
        }
       
        
        //ykc
        private void btnConnect_Click(object sender, EventArgs e)
        {

            string clientService = this.ServiceText.Text;
            string clientNetwork = this.NetworkText.Text;
            string clientDeamon = this.DaemonText.Text;
            string subject = this.LSubjectText.Text;
            if (string.IsNullOrEmpty(clientService) || string.IsNullOrEmpty(subject))
            {
                string tmpMsg = "Service text and ListenSubject text can not be empty!";
                MessageBox.Show(tmpMsg);
                return;
            }
            
            this.Cursor = Cursors.WaitCursor;
            this.axTibcoOCX1.remoteMode = false;
            this.axTibcoOCX1.AddClientTransParam(clientService, clientNetwork, clientDeamon);
            try
            { 
                status=this.axTibcoOCX1.Connect();
                this.Cursor = Cursors.Default;
                if (status != true)
                {
                    this.txtLog.AppendText(dateTime+"Connection failed!" + System.Environment.NewLine);
                    this.axTibcoOCX1.GetError(ref errorCode, ref errorInfo);
                    this.txtLog.AppendText(dateTime + "Connect info is:" + errorCode.ToString() + ":" + errorInfo + System.Environment.NewLine);
                }
                else
                {
                    this.btnConnect.Visible = false;
                    this.btnDisconnect.Visible = true;
                    //status = this.axTibcoOCX1.AddDQSubject("testdqcase");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            if (subject != string.Empty)
            {
                status = this.axTibcoOCX1.AddListen(subject);
                if (status == true)
                {
                    this.btnSend.Enabled = true;
                    this.txtLog.AppendText(dateTime + "Add one new listener, the listener name is " + subject + System.Environment.NewLine);
                }
                else
                {
                    this.txtLog.AppendText(dateTime + "Listener already exist! ");
                }
            }
            else
            {
                this.txtLog.AppendText(dateTime + "ListenSubject is Empty,please input " + System.Environment.NewLine);
            }
          
        }
        //ykc
        private void axTibcoOCX1_BroadcastReceived(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_BroadcastReceivedEvent e)
        {
            // delay reply deal


            string message = "Broadcast message received:" + e.message + System.Environment.NewLine;
            string inXmlMessage = e.message;
            string replyMessage = "";
            string replyaddress = "";
            inXmlMessage = FormatXml(inXmlMessage);
            //print receive msg
            //this.receiveMsg.Text = inXmlMessage;
            this.receiveMsg.AppendText("BroadcastReceived: " + inXmlMessage + System.Environment.NewLine);


            parseAndPrepareXml(inXmlMessage, ref replyMessage, ref replyaddress);
            string replyMsg = FormatXml(replyMessage);
            replyMsg = replyMsg.Replace("&gt;", ">");

            KeyValuePair<int, string> pairVal = new KeyValuePair<int, string>(totalNum, replyaddress);
            totalNum++;
            replyMsgSet.Add(pairVal, replyMsg);

            if (this.delayReply.Checked == true)
            {

                string str = this.delayreplyedit.Text;
                int timeout = 0;
                int.TryParse(str, out timeout);
                this.txtLog.AppendText(dateTime + "delay reply time: " + str + "s" + System.Environment.NewLine);
                timeout = timeout * 1000;

                if (!this.delayReplyFlag)
                {
                    delayReplyFlag = true;

                    this.myTimer.Start();
                    this.myTimer.Enabled = true;
                    this.myTimer.Interval = timeout;
                }
                this.myTimer.Interval = timeout;
            }
            else
            {
                foreachSendMsg();
            }


        }

        private void axTibcoOCX1_MessageReceived(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_MessageReceivedEvent e)
        {

            //string message = "Received one private message:" + e.message.ToString() + System.Environment.NewLine;
            //txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ") + "received msg in Receive Message Box." + System.Environment.NewLine);
            //this.receiveMsg.Text = e.message.ToString();

            string message = "Broadcast message received:" + e.message + System.Environment.NewLine;
            string inXmlMessage = e.message;
            string replyMessage = "";
            string replyaddress = "";
            inXmlMessage = FormatXml(inXmlMessage);
            //print receive msg
            //this.receiveMsg.Text = inXmlMessage;
            this.receiveMsg.AppendText("MessageReceived: " + inXmlMessage + System.Environment.NewLine);


            parseAndPrepareXml(inXmlMessage, ref replyMessage, ref replyaddress);
            string replyMsg = FormatXml(replyMessage);
            replyMsg = replyMsg.Replace("&gt;", ">");

            KeyValuePair<int, string> pairVal = new KeyValuePair<int, string>(totalNum, replyaddress);
            totalNum++;
            replyMsgSet.Add(pairVal, replyMsg);

            if (this.delayReply.Checked == true)
            {

                string str = this.delayreplyedit.Text;
                int timeout = 0;
                int.TryParse(str, out timeout);
                this.txtLog.AppendText(dateTime + "delay reply time: " + str + "s" + System.Environment.NewLine);
                timeout = timeout * 1000;

                if (!this.delayReplyFlag)
                {
                    delayReplyFlag = true;

                    this.myTimer.Start();
                    this.myTimer.Enabled = true;
                    this.myTimer.Interval = timeout;
                }
                this.myTimer.Interval = timeout;
            }
            else
            {
                foreachSendMsg();
            }

        }
        
        private void axTibcoOCX1_ConnectionMade(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionMadeEvent e)
        {

            string message = "Connection Made success :" + e.message.ToString() + System.Environment.NewLine;
            if (txtLog.InvokeRequired)
            {
                txtLog.BeginInvoke(new Action<String>(msg =>
                {
                    txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ")+msg);
                }), message);
            }
            else
                txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ")+message);
        }

        private void axTibcoOCX1_ConnectionFailed(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionFailedEvent e)
        {
            
            string message = "Connection Failed: " + e.message.ToString() + System.Environment.NewLine;
            if (txtLog.InvokeRequired)
            {
                txtLog.BeginInvoke(new Action<String>(msg =>
                {
                    txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ")+msg);
                }), message);
            }

        }

        private void axTibcoOCX1_ConnectionLost(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_ConnectionLostEvent e)
        {
            string message = "Connection lost: " + e.message.ToString() + System.Environment.NewLine;
            if (txtLog.InvokeRequired)
            {
                txtLog.BeginInvoke(new Action<String>(msg =>
                {
                    txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ")+msg);
                }), message);
            }
        }

        private void axTibcoOCX1_AdvisoryMessage(object sender, AxTIBCOOCXLib._DTibcoOCXEvents_AdvisoryMessageEvent e)
        {
           // MessageBox.Show("Get one Advisory message:"+e.message.ToString());
            string message ="Advisory Message Received:"+ e.message + System.Environment.NewLine;
            if (txtLog.InvokeRequired)
            {
                txtLog.BeginInvoke(new Action<String>(msg =>
                {
                    txtLog.AppendText(DateTime.Now.ToString("hh:mm:ss ")+msg);
                }), message);
            }
        }

        private void myTimer_Tick(object sender, EventArgs e)
        {

            foreachSendMsg();
            
            totalNum = 0;

            delayReplyFlag = false;
            this.myTimer.Enabled = false;
            this.myTimer.Stop();
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            
            string targetListen = this.TSubjectText.Text;
            string sendMsg = "";
            //Auto Send start
            if (this.autoSend.Checked == true)
            {
                string str = this.interval.Text;
                int timeout = 0;
                int.TryParse(str, out timeout);
                this.txtLog.AppendText(dateTime + "delay time: " + str + "s" + System.Environment.NewLine);
                timeout = timeout * 1000;
                string filePath = this.filePath.Text;
                DirectoryInfo d = new DirectoryInfo(filePath);
                FileSystemInfo[] fsinfos = d.GetFileSystemInfos();
                foreach (FileSystemInfo fsinfo in fsinfos)
                {
                    if (fsinfo is DirectoryInfo)     //判断是否为文件夹  
                    {
                        //Director(fsinfo.FullName);//递归调用  
                    }
                    else
                    {
                        string filename = fsinfo.FullName;//文件路径 
                        XmlDocument XmlDoc = new XmlDocument();
                        try
                        {
                            //加载xml
                            XmlDoc.Load(filename);
                            sendMsg = XmlDoc.InnerXml;
                            //sendMsg = FormatXml(sendMsg);
            
                        }
                        catch (Exception ex)
                        {
                            //this.txtLog.ForeColor = Color.Red;
                            this.txtLog.SelectionColor = Color.Red;
                            this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message + System.Environment.NewLine);

                        }
                        sendMsg = sendMsg.Replace("&gt;", ">");

                        this.txtLog.AppendText(dateTime + "Send messages to Target Subject:" + targetListen + System.Environment.NewLine);
                        //this.txtLog.AppendText(dateTime + "messages:" + sendMsg + System.Environment.NewLine);
                        status = this.axTibcoOCX1.SendNoReply(targetListen, sendMsg);

                        if (status != true)
                        {
                            this.axTibcoOCX1.GetError(ref errorCode, ref errorInfo);
                            this.txtLog.AppendText("Error info is:" + errorCode.ToString() + errorInfo);   //Send message failed. Print the error code and error information.
                        }
                        Thread.Sleep(timeout);//time interval
                    }
                }
                return;
            }
            //Auto Send end
            sendMsg = this.requestMsg.Text;

            // delay send deal
            if (this.delaysend.Checked == true)
            {
                string str = this.delaysendedit.Text;
                int timeout = 0;
                int.TryParse(str, out timeout);
                this.txtLog.AppendText(dateTime + "delay time: " + str + "s" + System.Environment.NewLine);
                timeout = timeout * 1000;
                Thread.Sleep(timeout);
            }
            XmlDocument sendXmlDoc = new XmlDocument();
            try
            {
                //加载xml
                sendXmlDoc.LoadXml(sendMsg);
                //replace source and destination
                XmlNode replyApplicationNode = sendXmlDoc.SelectSingleNode("/msg/rvHeader/replyApplication");
                XmlNode addressNode = replyApplicationNode.LastChild;
                string address = addressNode.InnerText;
                string inbox = "";
                if (getInboxFromAddress(address, ref inbox))
                {
                    addressNode.InnerText = inbox;
                    sendMsg = sendXmlDoc.InnerXml;
                    sendMsg = FormatXml(sendMsg);
                }
            }
            catch (Exception ex)
            {
                //this.txtLog.ForeColor = Color.Red;
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message + System.Environment.NewLine);
                
            }
            sendMsg = sendMsg.Replace("&gt;", ">");

            this.txtLog.AppendText(dateTime + "Send messages to Target Subject:" + targetListen + System.Environment.NewLine);
            //this.txtLog.AppendText(dateTime + "messages:" + sendMsg + System.Environment.NewLine);
            status = this.axTibcoOCX1.SendNoReply(targetListen, sendMsg);
          
           if (status != true)
           {
               this.axTibcoOCX1.GetError(ref errorCode, ref errorInfo);
               this.txtLog.AppendText("Error info is:" + errorCode.ToString() + errorInfo);   //Send message failed. Print the error code and error information.
           }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            this.txtLog.Clear();
            this.receiveMsg.Clear();
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            status=this.axTibcoOCX1.Disconnect();
            if (status != true)
                MessageBox.Show("Disconnected Failed!");
            this.btnConnect.Visible = true;
            this.btnDisconnect.Visible = false;
            this.btnSend.Enabled = false;
        }

        private void btnSendAndReply_Click(object sender, EventArgs e)
        {
            string sendMsg = "<msg><rvHeader><source><application>B2-MES</application><address>QA.SMNC.MESMCS.B2MES</address><replyApplication><addressNo>1</addressNo><address>QA.SMNC.MESMCS.B2MES._INBOX</address></replyApplication></source><destination><application>MCS-Agent</application><msgBus>TibRv</msgBus><domain>B2</domain><address >QA.SMNC.MESMCS.MCSAGENT.CarrierMoveRequest</address></destination></rvHeader></msg>";
            string replyMsg=string.Empty;
            bool result;
            try
            {
                result = this.axTibcoOCX1.SendAndReply("test", sendMsg, 10000, ref replyMsg);
                if (result == false)
                {
                    this.axTibcoOCX1.GetError(ref errorCode, ref errorInfo);
                    this.txtLog.AppendText(dateTime+"Error info is:" + errorCode.ToString() + errorInfo);
                }
                this.txtLog.AppendText(dateTime+"Got the sync message: "+replyMsg+System.Environment.NewLine);
            }
            catch(Exception ex)
            {
                MessageBox.Show("SendAndRequest: "+ex.Message);
                
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.axTibcoOCX1.Disconnect();
            this.Close();
        }

        private void showMessage(string msg)
        {
            string message = msg;
            if (txtLog.InvokeRequired)
            {
                txtLog.BeginInvoke(new Action<String>(msg1 =>
                {
                    txtLog.AppendText(dateTime+msg1);
                }), message);
            }
        }

        private void btnGetInbox_Click(object sender, EventArgs e)
        {
            string inbox = string.Empty;
            inbox = this.axTibcoOCX1.GetInbox();
            if (inbox != string.Empty)
                this.txtLog.AppendText("The inbox name is:" + inbox);
            else
                this.txtLog.AppendText("No inbox!S");
        }

        private void btnGetDaemon_Click(object sender, EventArgs e)
        {
            //string strDaemon = "";
            return;     
        }

        private void delayReply_CheckedChanged(object sender, EventArgs e)
        {
            if (this.delayReply.Checked == true)
            {
                
                this.delayreplyedit.Text = "3";
            }
            else
            {
               
                this.delayreplyedit.Text = "";
            }
        }

        private void delaysend_CheckedChanged(object sender, EventArgs e)
        {
            if (this.delaysend.Checked == true)
            {
                this.delaysendedit.Text = "3";
            }
            else
            {
                this.delaysendedit.Text = "";
            }
        }

        private void MessageSimulator_Resize(object sender, EventArgs e)
        {
            //float[] scale = (float[])Tag;
            //int i = 2;

            //foreach (Control ctrl in this.Controls)
            //{
            //    ctrl.Left = (int)(Size.Width * scale[i++]);
            //    ctrl.Top = (int)(Size.Height * scale[i++]);
            //    ctrl.Width = (int)(Size.Width / (float)scale[0] * ((Size)ctrl.Tag).Width);//!!!
            //    ctrl.Height = (int)(Size.Height / (float)scale[1] * ((Size)ctrl.Tag).Height);//!!!

            //    //每次使用的都是最初始的控件大小，保证准确无误。
            //}
        }

        private void Refresh_Click(object sender, EventArgs e)
        {
            InitUiParam();
        }

        private void replyIndex_CheckedChanged(object sender, EventArgs e)
        {
            if (this.replyIndex.Checked == true)
            {
                this.replyIndexedit.Text = "1";
            }
            else
            {
                this.replyIndexedit.Text = "";
            }
        }

        private void fileList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string requestMsg = "";
            string filePath = this.sendFolder + this.fileList.Text;
            XmlDocument XmlDoc = new XmlDocument();
            try
            {
                //加载xml
                XmlDoc.Load(filePath);
                requestMsg = XmlDoc.InnerXml;
                requestMsg = FormatXml(requestMsg);

            }
            catch (Exception ex)
            {
                //this.txtLog.ForeColor = Color.Red;
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message + System.Environment.NewLine);

            }
            requestMsg = requestMsg.Replace("&gt;", ">");

            this.requestMsg.Text = requestMsg;
            
        }

        private void fileList_DropDown(object sender, EventArgs e)
        {
            this.fileList.Items.Clear();
            string filePath = this.sendFolder;
            DirectoryInfo d = new DirectoryInfo(filePath);
            FileSystemInfo[] fsinfos = d.GetFileSystemInfos();
            foreach (FileSystemInfo fsinfo in fsinfos)
            {
                if (fsinfo is DirectoryInfo)     //判断是否为文件夹  
                {
                    //Director(fsinfo.FullName);//递归调用  
                }
                else
                {
                    string name = fsinfo.Name;//文件名
                    //string filename = fsinfo.FullName;//文件完整路径 
                    this.fileList.Items.Add(name);
                    
                }
            }
            
        }

        private void save_Click(object sender, EventArgs e)
        {
            
            if (this.fileList.Text == "")
            {
                string msg = "fileName is empty,please select one file";
                MessageBox.Show(msg, "ERROR");
                return;
            }
            string text = this.requestMsg.Text;
            if (text == "")
            {
                string msg = "msg is empty,make sure you want to save it";
                if (MessageBox.Show(msg, "Warning", MessageBoxButtons.YesNo) == System.Windows.Forms.DialogResult.No)
                {
                    return;
                }
            }


            
            string filename = this.sendFolder + this.fileList.Text;
            //if (!File.Exists(filename))
            //{
            //    this.txtLog.SelectionColor = Color.Red;
            //    this.txtLog.AppendText(dateTime + "filename : " + filename + " is not access " + System.Environment.NewLine);
            //    return ;
            //}
            /*
                 写文件流 
                 StreamWriter sw = new StreamWriter("test.txt", false);
                 StreamWriter sw = File.AppendText("test.txt");
                 false---覆盖
                 true ---追加
             */
            StreamWriter sw = new StreamWriter(filename, false);
            sw.WriteLine(text);
            sw.Flush();
            sw.Close();
        }

        private void delete_Click(object sender, EventArgs e)
        {
            if (this.fileList.Text == "")
            {
                string msg = "fileName is empty,please select one file";
                MessageBox.Show(msg, "ERROR");
                return;
            }
            string filename = this.sendFolder + this.fileList.Text;
            File.Delete(filename);
            this.fileList.Text = "";
            this.requestMsg.Text = "";
        }

        private void checkxml_Click(object sender, EventArgs e)
        {
            string xmlMessage = this.requestMsg.Text;
            XmlDocument xmlDoc = new XmlDocument();
            try
            {
                xmlDoc.LoadXml(xmlMessage);
            }
            catch (Exception ex)
            {
                this.txtLog.SelectionColor = Color.Red;
                this.txtLog.AppendText("XML format is Error,errmsg is " + ex.Message + System.Environment.NewLine);
                //string xmlerr = "XML format is Error,errmsg is " + ex.Message;
                MessageBox.Show(ex.Message, "XML format is Error");
                return ;

            }
            MessageBox.Show("XML Format is OK", "MSG");
        }

        private void sevices_DropDown(object sender, EventArgs e)
        {
            sevices.Items.Clear();
            foreach (var item in allFilm)
            {
                
                string tt = item.Key;
                sevices.Items.Add(tt);
            }
        }

        private void sevices_SelectedIndexChanged(object sender, EventArgs e)
        {
            Dictionary<string, string> film = new Dictionary<string, string>();
            film = allFilm[this.sevices.Text];
            string getVal = "";
            if (film.TryGetValue("Service", out getVal))
            {
                this.ServiceText.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("Network", out getVal))
            {
                this.NetworkText.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("Deamon", out getVal))
            {
                this.DaemonText.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("Timout", out getVal))
            {
                this.TimoutText.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("ReplyFolder", out getVal))
            {
                this.replyFolder = getVal;
            }

            getVal = "";
            if (film.TryGetValue("SendFolder", out getVal))
            {
                this.sendFolder = getVal;
                this.filePath.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("ListenSubject", out getVal))
            {
                this.LSubjectText.Text = getVal;
            }

            getVal = "";
            if (film.TryGetValue("TargetSubject", out getVal))
            {
                this.TSubjectText.Text = getVal;
            }
        }

    }
}
