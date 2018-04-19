namespace OCXTester
{
    partial class MessageSimulator
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MessageSimulator));
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnSend = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel8 = new System.Windows.Forms.Panel();
            this.replyMethod = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.retMsg = new System.Windows.Forms.TextBox();
            this.retMsg1 = new System.Windows.Forms.Label();
            this.retCode1 = new System.Windows.Forms.Label();
            this.retCode = new System.Windows.Forms.TextBox();
            this.panel5 = new System.Windows.Forms.Panel();
            this.LSubjectText = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.NetworkText = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.TimoutText = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.ServiceText = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.DaemonText = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.message = new System.Windows.Forms.GroupBox();
            this.delayreplyedit = new System.Windows.Forms.TextBox();
            this.delayReply = new System.Windows.Forms.CheckBox();
            this.panel7 = new System.Windows.Forms.Panel();
            this.checkxml = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.save = new System.Windows.Forms.Button();
            this.label12 = new System.Windows.Forms.Label();
            this.fileList = new System.Windows.Forms.ComboBox();
            this.filePath = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.interval = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.autoSend = new System.Windows.Forms.CheckBox();
            this.receiveMsg = new System.Windows.Forms.RichTextBox();
            this.requestMsg = new System.Windows.Forms.RichTextBox();
            this.panel6 = new System.Windows.Forms.Panel();
            this.replyIndexedit = new System.Windows.Forms.TextBox();
            this.replyIndex = new System.Windows.Forms.CheckBox();
            this.delaysend = new System.Windows.Forms.CheckBox();
            this.delaysendedit = new System.Windows.Forms.TextBox();
            this.TSubjectText = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.LOG = new System.Windows.Forms.GroupBox();
            this.txtLog = new System.Windows.Forms.RichTextBox();
            this.Refresh = new System.Windows.Forms.Button();
            this.axTibcoOCX1 = new AxTIBCOOCXLib.AxTibcoOCX();
            this.btnClose = new System.Windows.Forms.Button();
            this.myTimer = new System.Windows.Forms.Timer(this.components);
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.panel9 = new System.Windows.Forms.Panel();
            this.panel11 = new System.Windows.Forms.Panel();
            this.panel12 = new System.Windows.Forms.Panel();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.panel10 = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.sevices = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.panel8.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.message.SuspendLayout();
            this.panel7.SuspendLayout();
            this.panel6.SuspendLayout();
            this.LOG.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axTibcoOCX1)).BeginInit();
            this.panel9.SuspendLayout();
            this.panel11.SuspendLayout();
            this.panel12.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.panel10.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnConnect
            // 
            this.btnConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.Location = new System.Drawing.Point(81, 10);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(93, 52);
            this.btnConnect.TabIndex = 0;
            this.btnConnect.Text = "Start";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnSend
            // 
            this.btnSend.Enabled = false;
            this.btnSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSend.Location = new System.Drawing.Point(347, 5);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(74, 23);
            this.btnSend.TabIndex = 1;
            this.btnSend.Text = "Send";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // btnClear
            // 
            this.btnClear.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClear.Location = new System.Drawing.Point(792, 134);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(91, 29);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "ClearLog";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDisconnect.Location = new System.Drawing.Point(81, 68);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(93, 54);
            this.btnDisconnect.TabIndex = 0;
            this.btnDisconnect.Text = "Stop";
            this.btnDisconnect.UseVisualStyleBackColor = true;
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.panel11);
            this.groupBox1.Controls.Add(this.panel9);
            this.groupBox1.Controls.Add(this.panel8);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(946, 153);
            this.groupBox1.TabIndex = 26;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Service Title";
            // 
            // panel8
            // 
            this.panel8.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel8.Controls.Add(this.label9);
            this.panel8.Controls.Add(this.sevices);
            this.panel8.Controls.Add(this.replyMethod);
            this.panel8.Controls.Add(this.label1);
            this.panel8.Controls.Add(this.retMsg);
            this.panel8.Controls.Add(this.retMsg1);
            this.panel8.Controls.Add(this.retCode1);
            this.panel8.Controls.Add(this.retCode);
            this.panel8.Location = new System.Drawing.Point(433, 16);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(291, 140);
            this.panel8.TabIndex = 30;
            // 
            // replyMethod
            // 
            this.replyMethod.Location = new System.Drawing.Point(131, 41);
            this.replyMethod.Name = "replyMethod";
            this.replyMethod.Size = new System.Drawing.Size(157, 20);
            this.replyMethod.TabIndex = 32;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(6, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(122, 20);
            this.label1.TabIndex = 31;
            this.label1.Text = "replyMethod : ";
            // 
            // retMsg
            // 
            this.retMsg.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.retMsg.Location = new System.Drawing.Point(131, 91);
            this.retMsg.Name = "retMsg";
            this.retMsg.Size = new System.Drawing.Size(157, 20);
            this.retMsg.TabIndex = 30;
            // 
            // retMsg1
            // 
            this.retMsg1.AutoSize = true;
            this.retMsg1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.retMsg1.Location = new System.Drawing.Point(6, 91);
            this.retMsg1.Name = "retMsg1";
            this.retMsg1.Size = new System.Drawing.Size(79, 20);
            this.retMsg1.TabIndex = 29;
            this.retMsg1.Text = "retMsg : ";
            // 
            // retCode1
            // 
            this.retCode1.AutoSize = true;
            this.retCode1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.retCode1.Location = new System.Drawing.Point(6, 65);
            this.retCode1.Name = "retCode1";
            this.retCode1.Size = new System.Drawing.Size(88, 20);
            this.retCode1.TabIndex = 28;
            this.retCode1.Text = "retCode : ";
            // 
            // retCode
            // 
            this.retCode.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.retCode.Location = new System.Drawing.Point(131, 65);
            this.retCode.Name = "retCode";
            this.retCode.Size = new System.Drawing.Size(157, 20);
            this.retCode.TabIndex = 27;
            // 
            // panel5
            // 
            this.panel5.Controls.Add(this.LSubjectText);
            this.panel5.Controls.Add(this.label5);
            this.panel5.Location = new System.Drawing.Point(3, 104);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(401, 30);
            this.panel5.TabIndex = 29;
            // 
            // LSubjectText
            // 
            this.LSubjectText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.LSubjectText.Location = new System.Drawing.Point(138, 4);
            this.LSubjectText.Name = "LSubjectText";
            this.LSubjectText.Size = new System.Drawing.Size(243, 20);
            this.LSubjectText.TabIndex = 33;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(3, 2);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(129, 20);
            this.label5.TabIndex = 3;
            this.label5.Text = "ListenSubject :";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.NetworkText);
            this.panel2.Controls.Add(this.label7);
            this.panel2.Location = new System.Drawing.Point(3, 26);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(398, 23);
            this.panel2.TabIndex = 7;
            // 
            // NetworkText
            // 
            this.NetworkText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.NetworkText.Location = new System.Drawing.Point(135, 2);
            this.NetworkText.Name = "NetworkText";
            this.NetworkText.Size = new System.Drawing.Size(243, 20);
            this.NetworkText.TabIndex = 30;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(20, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(84, 20);
            this.label7.TabIndex = 5;
            this.label7.Text = "Network :";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.TimoutText);
            this.panel4.Controls.Add(this.label4);
            this.panel4.Location = new System.Drawing.Point(3, 73);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(398, 29);
            this.panel4.TabIndex = 28;
            // 
            // TimoutText
            // 
            this.TimoutText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.TimoutText.Location = new System.Drawing.Point(135, 5);
            this.TimoutText.Name = "TimoutText";
            this.TimoutText.Size = new System.Drawing.Size(243, 20);
            this.TimoutText.TabIndex = 32;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(20, 2);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(73, 20);
            this.label4.TabIndex = 2;
            this.label4.Text = "Timout :";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.ServiceText);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(398, 25);
            this.panel1.TabIndex = 6;
            // 
            // ServiceText
            // 
            this.ServiceText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.ServiceText.Location = new System.Drawing.Point(135, 2);
            this.ServiceText.Name = "ServiceText";
            this.ServiceText.Size = new System.Drawing.Size(243, 20);
            this.ServiceText.TabIndex = 27;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(20, 2);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 20);
            this.label3.TabIndex = 1;
            this.label3.Text = "Service : ";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.DaemonText);
            this.panel3.Controls.Add(this.label6);
            this.panel3.Location = new System.Drawing.Point(3, 49);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(398, 27);
            this.panel3.TabIndex = 27;
            // 
            // DaemonText
            // 
            this.DaemonText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.DaemonText.Location = new System.Drawing.Point(135, 1);
            this.DaemonText.Name = "DaemonText";
            this.DaemonText.Size = new System.Drawing.Size(246, 20);
            this.DaemonText.TabIndex = 31;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(20, 3);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(86, 20);
            this.label6.TabIndex = 4;
            this.label6.Text = "Deamon :";
            // 
            // message
            // 
            this.message.Controls.Add(this.delayreplyedit);
            this.message.Controls.Add(this.panel7);
            this.message.Controls.Add(this.panel6);
            this.message.Dock = System.Windows.Forms.DockStyle.Fill;
            this.message.Location = new System.Drawing.Point(0, 153);
            this.message.Name = "message";
            this.message.Size = new System.Drawing.Size(946, 546);
            this.message.TabIndex = 27;
            this.message.TabStop = false;
            this.message.Text = "message";
            // 
            // delayreplyedit
            // 
            this.delayreplyedit.Location = new System.Drawing.Point(852, 38);
            this.delayreplyedit.Name = "delayreplyedit";
            this.delayreplyedit.Size = new System.Drawing.Size(24, 20);
            this.delayreplyedit.TabIndex = 29;
            // 
            // delayReply
            // 
            this.delayReply.AutoSize = true;
            this.delayReply.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.delayReply.Location = new System.Drawing.Point(728, 17);
            this.delayReply.Name = "delayReply";
            this.delayReply.Size = new System.Drawing.Size(114, 21);
            this.delayReply.TabIndex = 30;
            this.delayReply.Text = "Delay Reply";
            this.delayReply.UseVisualStyleBackColor = true;
            this.delayReply.CheckedChanged += new System.EventHandler(this.delayReply_CheckedChanged);
            // 
            // panel7
            // 
            this.panel7.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel7.Controls.Add(this.panel10);
            this.panel7.Controls.Add(this.panel12);
            this.panel7.Location = new System.Drawing.Point(6, 58);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(940, 313);
            this.panel7.TabIndex = 8;
            // 
            // checkxml
            // 
            this.checkxml.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.checkxml.Location = new System.Drawing.Point(6, 218);
            this.checkxml.Name = "checkxml";
            this.checkxml.Size = new System.Drawing.Size(160, 23);
            this.checkxml.TabIndex = 43;
            this.checkxml.Text = "Check XML Format";
            this.checkxml.UseVisualStyleBackColor = true;
            this.checkxml.Click += new System.EventHandler(this.checkxml_Click);
            // 
            // delete
            // 
            this.delete.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.delete.Location = new System.Drawing.Point(424, 192);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(73, 23);
            this.delete.TabIndex = 42;
            this.delete.Text = "Delete";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.delete_Click);
            // 
            // save
            // 
            this.save.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.save.Location = new System.Drawing.Point(361, 192);
            this.save.Name = "save";
            this.save.Size = new System.Drawing.Size(57, 23);
            this.save.TabIndex = 31;
            this.save.Text = "Save";
            this.save.UseVisualStyleBackColor = true;
            this.save.Click += new System.EventHandler(this.save_Click);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(6, 195);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(52, 20);
            this.label12.TabIndex = 41;
            this.label12.Text = "Files:";
            // 
            // fileList
            // 
            this.fileList.FormattingEnabled = true;
            this.fileList.Location = new System.Drawing.Point(64, 194);
            this.fileList.Name = "fileList";
            this.fileList.Size = new System.Drawing.Size(293, 21);
            this.fileList.TabIndex = 40;
            this.fileList.DropDown += new System.EventHandler(this.fileList_DropDown);
            this.fileList.SelectedIndexChanged += new System.EventHandler(this.fileList_SelectedIndexChanged);
            // 
            // filePath
            // 
            this.filePath.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.filePath.Location = new System.Drawing.Point(103, 274);
            this.filePath.Name = "filePath";
            this.filePath.Size = new System.Drawing.Size(403, 20);
            this.filePath.TabIndex = 39;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(12, 272);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(85, 20);
            this.label11.TabIndex = 38;
            this.label11.Text = "filePath : ";
            // 
            // interval
            // 
            this.interval.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.interval.Location = new System.Drawing.Point(209, 248);
            this.interval.Name = "interval";
            this.interval.Size = new System.Drawing.Size(163, 20);
            this.interval.TabIndex = 37;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(121, 245);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 20);
            this.label2.TabIndex = 36;
            this.label2.Text = "interval : ";
            // 
            // autoSend
            // 
            this.autoSend.AutoSize = true;
            this.autoSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.autoSend.Location = new System.Drawing.Point(13, 247);
            this.autoSend.Name = "autoSend";
            this.autoSend.Size = new System.Drawing.Size(102, 21);
            this.autoSend.TabIndex = 35;
            this.autoSend.Text = "Auto Send";
            this.autoSend.UseVisualStyleBackColor = true;
            // 
            // receiveMsg
            // 
            this.receiveMsg.Dock = System.Windows.Forms.DockStyle.Fill;
            this.receiveMsg.Location = new System.Drawing.Point(3, 16);
            this.receiveMsg.Name = "receiveMsg";
            this.receiveMsg.Size = new System.Drawing.Size(417, 288);
            this.receiveMsg.TabIndex = 29;
            this.receiveMsg.Text = "";
            // 
            // requestMsg
            // 
            this.requestMsg.Dock = System.Windows.Forms.DockStyle.Fill;
            this.requestMsg.Location = new System.Drawing.Point(3, 16);
            this.requestMsg.Name = "requestMsg";
            this.requestMsg.Size = new System.Drawing.Size(496, 164);
            this.requestMsg.TabIndex = 29;
            this.requestMsg.Text = "";
            // 
            // panel6
            // 
            this.panel6.Controls.Add(this.replyIndexedit);
            this.panel6.Controls.Add(this.replyIndex);
            this.panel6.Controls.Add(this.delaysend);
            this.panel6.Controls.Add(this.delayReply);
            this.panel6.Controls.Add(this.delaysendedit);
            this.panel6.Controls.Add(this.TSubjectText);
            this.panel6.Controls.Add(this.label8);
            this.panel6.Controls.Add(this.btnSend);
            this.panel6.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel6.Location = new System.Drawing.Point(3, 16);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(940, 42);
            this.panel6.TabIndex = 7;
            // 
            // replyIndexedit
            // 
            this.replyIndexedit.Location = new System.Drawing.Point(603, 8);
            this.replyIndexedit.Name = "replyIndexedit";
            this.replyIndexedit.Size = new System.Drawing.Size(24, 20);
            this.replyIndexedit.TabIndex = 35;
            // 
            // replyIndex
            // 
            this.replyIndex.AutoSize = true;
            this.replyIndex.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.replyIndex.Location = new System.Drawing.Point(486, 8);
            this.replyIndex.Name = "replyIndex";
            this.replyIndex.Size = new System.Drawing.Size(111, 21);
            this.replyIndex.TabIndex = 34;
            this.replyIndex.Text = "Reply Index";
            this.replyIndex.UseVisualStyleBackColor = true;
            this.replyIndex.CheckedChanged += new System.EventHandler(this.replyIndex_CheckedChanged);
            // 
            // delaysend
            // 
            this.delaysend.AutoSize = true;
            this.delaysend.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.delaysend.Location = new System.Drawing.Point(730, -1);
            this.delaysend.Name = "delaysend";
            this.delaysend.Size = new System.Drawing.Size(110, 21);
            this.delaysend.TabIndex = 33;
            this.delaysend.Text = "Delay Send";
            this.delaysend.UseVisualStyleBackColor = true;
            this.delaysend.CheckedChanged += new System.EventHandler(this.delaysend_CheckedChanged);
            // 
            // delaysendedit
            // 
            this.delaysendedit.Location = new System.Drawing.Point(848, 0);
            this.delaysendedit.Name = "delaysendedit";
            this.delaysendedit.Size = new System.Drawing.Size(22, 20);
            this.delaysendedit.TabIndex = 32;
            // 
            // TSubjectText
            // 
            this.TSubjectText.Location = new System.Drawing.Point(123, 7);
            this.TSubjectText.Name = "TSubjectText";
            this.TSubjectText.Size = new System.Drawing.Size(218, 20);
            this.TSubjectText.TabIndex = 27;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(1, 6);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(125, 17);
            this.label8.TabIndex = 1;
            this.label8.Text = "Target Subject :";
            // 
            // LOG
            // 
            this.LOG.Controls.Add(this.txtLog);
            this.LOG.Controls.Add(this.Refresh);
            this.LOG.Controls.Add(this.btnClear);
            this.LOG.Controls.Add(this.axTibcoOCX1);
            this.LOG.Controls.Add(this.btnClose);
            this.LOG.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.LOG.Location = new System.Drawing.Point(0, 530);
            this.LOG.Name = "LOG";
            this.LOG.Size = new System.Drawing.Size(946, 169);
            this.LOG.TabIndex = 28;
            this.LOG.TabStop = false;
            this.LOG.Text = "LOG";
            // 
            // txtLog
            // 
            this.txtLog.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtLog.Location = new System.Drawing.Point(3, 16);
            this.txtLog.Name = "txtLog";
            this.txtLog.Size = new System.Drawing.Size(940, 118);
            this.txtLog.TabIndex = 29;
            this.txtLog.Text = "";
            // 
            // Refresh
            // 
            this.Refresh.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.Refresh.Location = new System.Drawing.Point(6, 140);
            this.Refresh.Name = "Refresh";
            this.Refresh.Size = new System.Drawing.Size(75, 23);
            this.Refresh.TabIndex = 28;
            this.Refresh.Text = "Refresh";
            this.Refresh.UseVisualStyleBackColor = true;
            this.Refresh.Click += new System.EventHandler(this.Refresh_Click);
            // 
            // axTibcoOCX1
            // 
            this.axTibcoOCX1.Enabled = true;
            this.axTibcoOCX1.Location = new System.Drawing.Point(625, 137);
            this.axTibcoOCX1.Name = "axTibcoOCX1";
            this.axTibcoOCX1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axTibcoOCX1.OcxState")));
            this.axTibcoOCX1.Size = new System.Drawing.Size(56, 28);
            this.axTibcoOCX1.TabIndex = 24;
            this.axTibcoOCX1.Visible = false;
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.Location = new System.Drawing.Point(354, 137);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(91, 23);
            this.btnClose.TabIndex = 14;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Visible = false;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // myTimer
            // 
            this.myTimer.Tick += new System.EventHandler(this.myTimer_Tick);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // panel9
            // 
            this.panel9.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel9.Controls.Add(this.btnDisconnect);
            this.panel9.Controls.Add(this.btnConnect);
            this.panel9.Location = new System.Drawing.Point(736, 16);
            this.panel9.Name = "panel9";
            this.panel9.Size = new System.Drawing.Size(207, 140);
            this.panel9.TabIndex = 31;
            // 
            // panel11
            // 
            this.panel11.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.panel11.Controls.Add(this.panel1);
            this.panel11.Controls.Add(this.panel2);
            this.panel11.Controls.Add(this.panel5);
            this.panel11.Controls.Add(this.panel3);
            this.panel11.Controls.Add(this.panel4);
            this.panel11.Location = new System.Drawing.Point(12, 22);
            this.panel11.Name = "panel11";
            this.panel11.Size = new System.Drawing.Size(415, 131);
            this.panel11.TabIndex = 32;
            // 
            // panel12
            // 
            this.panel12.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.panel12.Controls.Add(this.groupBox3);
            this.panel12.Controls.Add(this.filePath);
            this.panel12.Controls.Add(this.delete);
            this.panel12.Controls.Add(this.label11);
            this.panel12.Controls.Add(this.checkxml);
            this.panel12.Controls.Add(this.interval);
            this.panel12.Controls.Add(this.save);
            this.panel12.Controls.Add(this.label2);
            this.panel12.Controls.Add(this.label12);
            this.panel12.Controls.Add(this.autoSend);
            this.panel12.Controls.Add(this.fileList);
            this.panel12.Location = new System.Drawing.Point(9, 0);
            this.panel12.Name = "panel12";
            this.panel12.Size = new System.Drawing.Size(508, 307);
            this.panel12.TabIndex = 45;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.receiveMsg);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 0);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(423, 307);
            this.groupBox2.TabIndex = 46;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Receive Message";
            // 
            // panel10
            // 
            this.panel10.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel10.Controls.Add(this.groupBox2);
            this.panel10.Location = new System.Drawing.Point(521, 3);
            this.panel10.Name = "panel10";
            this.panel10.Size = new System.Drawing.Size(423, 307);
            this.panel10.TabIndex = 47;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.requestMsg);
            this.groupBox3.Location = new System.Drawing.Point(3, 3);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(502, 183);
            this.groupBox3.TabIndex = 44;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Send Message";
            // 
            // sevices
            // 
            this.sevices.FormattingEnabled = true;
            this.sevices.Location = new System.Drawing.Point(131, 9);
            this.sevices.Name = "sevices";
            this.sevices.Size = new System.Drawing.Size(160, 21);
            this.sevices.TabIndex = 41;
            this.sevices.DropDown += new System.EventHandler(this.sevices_DropDown);
            this.sevices.SelectedIndexChanged += new System.EventHandler(this.sevices_SelectedIndexChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(6, 10);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(60, 20);
            this.label9.TabIndex = 42;
            this.label9.Text = "ENV : ";
            // 
            // MessageSimulator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.AutoSize = true;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(946, 699);
            this.Controls.Add(this.LOG);
            this.Controls.Add(this.message);
            this.Controls.Add(this.groupBox1);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(100, 100);
            this.Name = "MessageSimulator";
            this.Text = "MessageSimulator";
            this.Load += new System.EventHandler(this.MessageSimulator_Load);
            this.Resize += new System.EventHandler(this.MessageSimulator_Resize);
            this.groupBox1.ResumeLayout(false);
            this.panel8.ResumeLayout(false);
            this.panel8.PerformLayout();
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.message.ResumeLayout(false);
            this.message.PerformLayout();
            this.panel7.ResumeLayout(false);
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.LOG.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.axTibcoOCX1)).EndInit();
            this.panel9.ResumeLayout(false);
            this.panel11.ResumeLayout(false);
            this.panel12.ResumeLayout(false);
            this.panel12.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.panel10.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnDisconnect;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.TextBox LSubjectText;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.TextBox NetworkText;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.TextBox TimoutText;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox ServiceText;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.TextBox DaemonText;
        private System.Windows.Forms.GroupBox message;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.CheckBox delayReply;
        private System.Windows.Forms.TextBox delayreplyedit;
        private System.Windows.Forms.TextBox TSubjectText;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.GroupBox LOG;
        private System.Windows.Forms.Button btnClose;
        private AxTIBCOOCXLib.AxTibcoOCX axTibcoOCX1;
        private System.Windows.Forms.Button Refresh;
        private System.Windows.Forms.CheckBox delaysend;
        private System.Windows.Forms.TextBox delaysendedit;
        private System.Windows.Forms.TextBox replyIndexedit;
        private System.Windows.Forms.CheckBox replyIndex;
        private System.Windows.Forms.RichTextBox txtLog;
        private System.Windows.Forms.RichTextBox receiveMsg;
        private System.Windows.Forms.RichTextBox requestMsg;
        private System.Windows.Forms.Timer myTimer;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.TextBox retMsg;
        private System.Windows.Forms.Label retMsg1;
        private System.Windows.Forms.Label retCode1;
        private System.Windows.Forms.TextBox retCode;
        private System.Windows.Forms.TextBox replyMethod;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox filePath;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox interval;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox autoSend;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ComboBox fileList;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Button save;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Button checkxml;
        private System.Windows.Forms.Panel panel11;
        private System.Windows.Forms.Panel panel9;
        private System.Windows.Forms.Panel panel12;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Panel panel10;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox sevices;
    }
}

