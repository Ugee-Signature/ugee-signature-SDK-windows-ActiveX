namespace Sample01
{
    partial class frmMain
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.check_SystemTouch = new System.Windows.Forms.CheckBox();
            this.check_Eraser = new System.Windows.Forms.CheckBox();
            this.combo_SignMode = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.combo_MappingMode = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.check_MouseMapping = new System.Windows.Forms.CheckBox();
            this.check_MouseControl = new System.Windows.Forms.CheckBox();
            this.check_SingleSign = new System.Windows.Forms.CheckBox();
            this.combo_ImageType = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.btn_FilePath = new System.Windows.Forms.Button();
            this.text_FilePath = new System.Windows.Forms.TextBox();
            this.check_BorderVisible = new System.Windows.Forms.CheckBox();
            this.text_PenWidth = new System.Windows.Forms.TextBox();
            this.btn_BorderColor = new System.Windows.Forms.Button();
            this.btn_BKColor = new System.Windows.Forms.Button();
            this.track_PenWidth = new System.Windows.Forms.TrackBar();
            this.btn_PenColor = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_ClearSign = new System.Windows.Forms.Button();
            this.btn_SaveSign = new System.Windows.Forms.Button();
            this.status_DevStatus = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.axSignViewer1 = new AxSignViewerLib.AxSignViewer();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.track_PenWidth)).BeginInit();
            this.status_DevStatus.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axSignViewer1)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.check_SystemTouch);
            this.groupBox1.Controls.Add(this.check_Eraser);
            this.groupBox1.Controls.Add(this.combo_SignMode);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Controls.Add(this.combo_MappingMode);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.check_MouseMapping);
            this.groupBox1.Controls.Add(this.check_MouseControl);
            this.groupBox1.Controls.Add(this.check_SingleSign);
            this.groupBox1.Controls.Add(this.combo_ImageType);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.btn_FilePath);
            this.groupBox1.Controls.Add(this.text_FilePath);
            this.groupBox1.Controls.Add(this.check_BorderVisible);
            this.groupBox1.Controls.Add(this.text_PenWidth);
            this.groupBox1.Controls.Add(this.btn_BorderColor);
            this.groupBox1.Controls.Add(this.btn_BKColor);
            this.groupBox1.Controls.Add(this.track_PenWidth);
            this.groupBox1.Controls.Add(this.btn_PenColor);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            resources.ApplyResources(this.groupBox1, "groupBox1");
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.TabStop = false;
            // 
            // check_SystemTouch
            // 
            resources.ApplyResources(this.check_SystemTouch, "check_SystemTouch");
            this.check_SystemTouch.Name = "check_SystemTouch";
            this.check_SystemTouch.UseVisualStyleBackColor = true;
            this.check_SystemTouch.CheckedChanged += new System.EventHandler(this.check_SystemTouch_CheckedChanged);
            // 
            // check_Eraser
            // 
            resources.ApplyResources(this.check_Eraser, "check_Eraser");
            this.check_Eraser.Name = "check_Eraser";
            this.check_Eraser.UseVisualStyleBackColor = true;
            this.check_Eraser.CheckedChanged += new System.EventHandler(this.check_Eraser_CheckedChanged);
            // 
            // combo_SignMode
            // 
            this.combo_SignMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combo_SignMode.FormattingEnabled = true;
            resources.ApplyResources(this.combo_SignMode, "combo_SignMode");
            this.combo_SignMode.Name = "combo_SignMode";
            this.combo_SignMode.SelectedIndexChanged += new System.EventHandler(this.combo_SignMode_SelectedIndexChanged);
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.Name = "label8";
            // 
            // combo_MappingMode
            // 
            this.combo_MappingMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combo_MappingMode.FormattingEnabled = true;
            resources.ApplyResources(this.combo_MappingMode, "combo_MappingMode");
            this.combo_MappingMode.Name = "combo_MappingMode";
            this.combo_MappingMode.SelectedIndexChanged += new System.EventHandler(this.combox_MappingMode_SelectedIndexChanged);
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // check_MouseMapping
            // 
            resources.ApplyResources(this.check_MouseMapping, "check_MouseMapping");
            this.check_MouseMapping.Name = "check_MouseMapping";
            this.check_MouseMapping.UseVisualStyleBackColor = true;
            this.check_MouseMapping.CheckedChanged += new System.EventHandler(this.check_MouseMapping_CheckedChanged);
            // 
            // check_MouseControl
            // 
            resources.ApplyResources(this.check_MouseControl, "check_MouseControl");
            this.check_MouseControl.Name = "check_MouseControl";
            this.check_MouseControl.UseVisualStyleBackColor = true;
            this.check_MouseControl.CheckedChanged += new System.EventHandler(this.check_MouseControl_CheckedChanged);
            // 
            // check_SingleSign
            // 
            resources.ApplyResources(this.check_SingleSign, "check_SingleSign");
            this.check_SingleSign.Name = "check_SingleSign";
            this.check_SingleSign.UseVisualStyleBackColor = true;
            // 
            // combo_ImageType
            // 
            this.combo_ImageType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combo_ImageType.FormattingEnabled = true;
            resources.ApplyResources(this.combo_ImageType, "combo_ImageType");
            this.combo_ImageType.Name = "combo_ImageType";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // btn_FilePath
            // 
            resources.ApplyResources(this.btn_FilePath, "btn_FilePath");
            this.btn_FilePath.Name = "btn_FilePath";
            this.btn_FilePath.UseVisualStyleBackColor = true;
            this.btn_FilePath.Click += new System.EventHandler(this.btn_FilePath_Click);
            // 
            // text_FilePath
            // 
            resources.ApplyResources(this.text_FilePath, "text_FilePath");
            this.text_FilePath.Name = "text_FilePath";
            this.text_FilePath.ReadOnly = true;
            // 
            // check_BorderVisible
            // 
            resources.ApplyResources(this.check_BorderVisible, "check_BorderVisible");
            this.check_BorderVisible.Name = "check_BorderVisible";
            this.check_BorderVisible.UseVisualStyleBackColor = true;
            this.check_BorderVisible.CheckedChanged += new System.EventHandler(this.check_BorderVisible_CheckedChanged);
            // 
            // text_PenWidth
            // 
            resources.ApplyResources(this.text_PenWidth, "text_PenWidth");
            this.text_PenWidth.Name = "text_PenWidth";
            // 
            // btn_BorderColor
            // 
            this.btn_BorderColor.BackColor = System.Drawing.SystemColors.Window;
            resources.ApplyResources(this.btn_BorderColor, "btn_BorderColor");
            this.btn_BorderColor.Name = "btn_BorderColor";
            this.btn_BorderColor.UseVisualStyleBackColor = false;
            this.btn_BorderColor.Click += new System.EventHandler(this.btn_BorderColor_Click);
            // 
            // btn_BKColor
            // 
            this.btn_BKColor.BackColor = System.Drawing.SystemColors.Window;
            resources.ApplyResources(this.btn_BKColor, "btn_BKColor");
            this.btn_BKColor.Name = "btn_BKColor";
            this.btn_BKColor.UseVisualStyleBackColor = false;
            this.btn_BKColor.Click += new System.EventHandler(this.btn_BKColor_Click);
            // 
            // track_PenWidth
            // 
            resources.ApplyResources(this.track_PenWidth, "track_PenWidth");
            this.track_PenWidth.Name = "track_PenWidth";
            this.track_PenWidth.Scroll += new System.EventHandler(this.track_PenWidth_Scroll);
            // 
            // btn_PenColor
            // 
            this.btn_PenColor.BackColor = System.Drawing.SystemColors.Window;
            resources.ApplyResources(this.btn_PenColor, "btn_PenColor");
            this.btn_PenColor.Name = "btn_PenColor";
            this.btn_PenColor.UseVisualStyleBackColor = false;
            this.btn_PenColor.Click += new System.EventHandler(this.btn_PenColor_Click);
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // btn_ClearSign
            // 
            resources.ApplyResources(this.btn_ClearSign, "btn_ClearSign");
            this.btn_ClearSign.Name = "btn_ClearSign";
            this.btn_ClearSign.UseVisualStyleBackColor = true;
            this.btn_ClearSign.Click += new System.EventHandler(this.btn_ClearSign_Click);
            // 
            // btn_SaveSign
            // 
            resources.ApplyResources(this.btn_SaveSign, "btn_SaveSign");
            this.btn_SaveSign.Name = "btn_SaveSign";
            this.btn_SaveSign.UseVisualStyleBackColor = true;
            this.btn_SaveSign.Click += new System.EventHandler(this.btn_SaveSign_Click);
            // 
            // status_DevStatus
            // 
            this.status_DevStatus.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2});
            resources.ApplyResources(this.status_DevStatus, "status_DevStatus");
            this.status_DevStatus.Name = "status_DevStatus";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            resources.ApplyResources(this.toolStripStatusLabel1, "toolStripStatusLabel1");
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            resources.ApplyResources(this.toolStripStatusLabel2, "toolStripStatusLabel2");
            // 
            // axSignViewer1
            // 
            resources.ApplyResources(this.axSignViewer1, "axSignViewer1");
            this.axSignViewer1.Name = "axSignViewer1";
            this.axSignViewer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axSignViewer1.OcxState")));
            this.axSignViewer1.DevNotifyEvent += new AxSignViewerLib._DSignViewerEvents_DevNotifyEventEventHandler(this.SignViewerCtl_DevNotifyEvent);
            this.axSignViewer1.BtnClickEvent += new AxSignViewerLib._DSignViewerEvents_BtnClickEventEventHandler(this.SignViewerCtl_BtnClickEvent);
            this.axSignViewer1.KeyEvent += new AxSignViewerLib._DSignViewerEvents_KeyEventEventHandler(this.SignViewerCtl_KeyEvent);
            this.axSignViewer1.PenEvent += new AxSignViewerLib._DSignViewerEvents_PenEventEventHandler(this.SignViewerCtl_Penevent);
            // 
            // frmMain
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.axSignViewer1);
            this.Controls.Add(this.status_DevStatus);
            this.Controls.Add(this.btn_SaveSign);
            this.Controls.Add(this.btn_ClearSign);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.Move += new System.EventHandler(this.frmMain_Move);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.track_PenWidth)).EndInit();
            this.status_DevStatus.ResumeLayout(false);
            this.status_DevStatus.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axSignViewer1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btn_PenColor;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar track_PenWidth;
        private System.Windows.Forms.Button btn_BorderColor;
        private System.Windows.Forms.Button btn_BKColor;
        private System.Windows.Forms.TextBox text_PenWidth;
        private System.Windows.Forms.CheckBox check_BorderVisible;
        private System.Windows.Forms.Button btn_FilePath;
        private System.Windows.Forms.TextBox text_FilePath;
        private System.Windows.Forms.Button btn_ClearSign;
        private System.Windows.Forms.Button btn_SaveSign;
        private System.Windows.Forms.ComboBox combo_ImageType;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.CheckBox check_SingleSign;
        private System.Windows.Forms.StatusStrip status_DevStatus;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.CheckBox check_MouseControl;
        private System.Windows.Forms.CheckBox check_MouseMapping;
        private System.Windows.Forms.ComboBox combo_MappingMode;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox combo_SignMode;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.CheckBox check_Eraser;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        private System.Windows.Forms.CheckBox check_SystemTouch;
        private AxSignViewerLib.AxSignViewer axSignViewer1;
    }
}

