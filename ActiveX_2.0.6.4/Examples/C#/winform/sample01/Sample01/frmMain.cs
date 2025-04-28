using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using SignViewerLib;
using System.Resources;
using System.Globalization;


namespace Sample01
{
   
    public enum TouchStatus{
        TouchStatus_Up,
        TouchStatus_Down,
        TouchStatus_Move
    }
    public enum PenStatus
    {
        PenStatus_Hover,                //悬浮
        PenStatus_Down,                 //按下
        PenStatus_Move,                 //移动
        PenStatus_Up,                   //抬起
        PenStatus_Leave					//离开
    }
    public partial class frmMain : Form
    {
        public const uint Btn_Index_ClearSign = 1;      //清除按钮事件索引
        public const uint Btn_Index_SaveSign = 2;       //保存按钮事件索引
        private bool bRegClear = false;
        private bool bRegSave = false;
        private bool bFormInit = false;
        private bool bFlagchinese = false;

        private void ApplyResource()
        {
            System.ComponentModel.ComponentResourceManager res = new ComponentResourceManager(typeof(frmMain));
            foreach (Control ctl in Controls)
            {
                res.ApplyResources(ctl, ctl.Name);
            }
            //Caption
            ResourceManager rm = new ResourceManager(typeof(frmMain));
            btn_ClearSign.Text = rm.GetString("btn_ClearSign.Text");
            btn_SaveSign.Text= rm.GetString("btn_SaveSign.Text");
            check_BorderVisible.Text= rm.GetString("check_BorderVisible.Text");
            check_Eraser.Text = rm.GetString("check_Eraser.Text");
            check_MouseControl.Text = rm.GetString("check_MouseControl.Text");
            check_MouseMapping.Text = rm.GetString("check_MouseMapping.Text");
            check_SingleSign.Text = rm.GetString("check_SingleSign.Text");
            check_SystemTouch.Text = rm.GetString("check_SystemTouch.Text");
            groupBox1.Text = rm.GetString("groupBox1.Text");
            label1.Text = rm.GetString("label1.Text");
            label2.Text = rm.GetString("label2.Text");
            label3.Text = rm.GetString("label3.Text");
            label4.Text = rm.GetString("label4.Text");
            label5.Text = rm.GetString("label5.Text");
            label6.Text = rm.GetString("label6.Text");
            label7.Text = rm.GetString("label7.Text");
            label8.Text = rm.GetString("label8.Text");
            res.ApplyResources(this, "$this");

        }
        public frmMain()
        {
            InitializeComponent();
        }
        //设置画笔颜色
        private void btn_PenColor_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                Color color = dlg.Color;
                btn_PenColor.BackColor = color;

                
                axSignViewer1.SetPenColor(color.R, color.G, color.B);
            }
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            //初始化UI配置显示
            string Systemlan = System.Globalization.CultureInfo.InstalledUICulture.Name;
            if (Systemlan == "zh-MO" || Systemlan == "zh-CN" || Systemlan == "zh-Hans" || Systemlan == "zh-SG" || Systemlan == "zh-TW" || Systemlan == "zh-Hant")
            {
                bFlagchinese = true;
            }
            else
            {
                Thread.CurrentThread.CurrentUICulture = CultureInfo.GetCultureInfo("en");
                ApplyResource();
                bFlagchinese = false;
            }
            //获取默认画笔颜色
            Byte r = 0, g = 0, b = 0;
            axSignViewer1.GetPenColor(ref r, ref g, ref b);
            btn_PenColor.BackColor = Color.FromArgb(r, g, b);

            //获取画笔范围
            int min = 1, max = 8;
          //  axSignViewer1.GetPenSizeRange(ref min, ref max);
            track_PenWidth.SetRange(1, 16);
            track_PenWidth.Value = max;
            text_PenWidth.Text = max.ToString();

            //书写模式(touch功能需设备带touch特性）
            if(bFlagchinese == true)
            {
                combo_SignMode.Items.Add("电磁笔");
                combo_SignMode.Items.Add("Touch");
                combo_SignMode.Items.Add("二者混合");
                combo_SignMode.SelectedIndex = axSignViewer1.SignMode;
            }
            else
            {
                combo_SignMode.Items.Add("Pen");
                combo_SignMode.Items.Add("Touch");
                combo_SignMode.Items.Add("Pen&Touch");
                combo_SignMode.SelectedIndex = axSignViewer1.SignMode;
            }


            //背景颜色 
            axSignViewer1.GetBKColor(ref r, ref g, ref b);
            btn_BKColor.BackColor = Color.FromArgb(r, g, b);

            check_BorderVisible.Checked = axSignViewer1.BorderVisible;

            //axSignViewer1.CursorVisible = axSignViewer1.CursorVisible;

            //边框颜色
            axSignViewer1.GetBorderColor(ref r, ref g, ref b);
            btn_BorderColor.BackColor = Color.FromArgb(r, g, b);

            //保存目录
            text_FilePath.Text = @"D:\";

            //存储类型
            combo_ImageType.Items.Add("0-jpg");
            combo_ImageType.Items.Add("1-png");
            combo_ImageType.Items.Add("2-gif");
            combo_ImageType.Items.Add("3-bmp");
            combo_ImageType.SelectedIndex = 0;

            //书写映射到控件或屏幕
            if(bFlagchinese==true)
            {
                combo_MappingMode.Items.Add("映射到屏幕");
                combo_MappingMode.Items.Add("映射到控件");
            }
            else
            {
                combo_MappingMode.Items.Add("0-Screen");
                combo_MappingMode.Items.Add("1-Control");
            }

            if (axSignViewer1.DisplayMapMode == 0)
            {
                combo_MappingMode.SelectedIndex = 0;
            }
            else
            {
                combo_MappingMode.SelectedIndex = 1;
            }

            if (bFlagchinese == true)
            {
                toolStripStatusLabel1.Text = "连接状态:" + (axSignViewer1.IsConnected() ? "已连接" : "未连接");
            }
            else
            {
                toolStripStatusLabel1.Text = "Status:" + (axSignViewer1.IsConnected() ? "connected" : "disconnected");
            }

            //针对数位屏的笔点击事件回调注册（注册的按钮区域相对于屏是固定区域，如窗口移动或按钮移动，需重新计算注册)
            int left = 0, top = 0, right = 0, bottom = 0;
            axSignViewer1.GetScreenRect(ref left, ref top, ref right, ref bottom);
            if (right - left > 0)
            {
                //将窗口推送到签字屏
                this.Location = (Point)new Size(left + (right - left - this.Width) / 2, top + (bottom - top - this.Height) / 2);
                Point pt_clear = PointToScreen(btn_ClearSign.Location);
                //转换到相对于扩展屏的屏幕坐标
                pt_clear.X -= left;
                pt_clear.Y -= top;
                axSignViewer1.RegBtnClickEvent(Btn_Index_ClearSign, pt_clear.X, pt_clear.Y, btn_ClearSign.Width, btn_ClearSign.Height);
                bRegClear = true;
                Point pt_save = PointToScreen(btn_SaveSign.Location);
                //转换到相对于扩展屏的屏幕坐标
                pt_save.X -= left;
                pt_save.Y -= top;
                axSignViewer1.RegBtnClickEvent(Btn_Index_SaveSign, pt_save.X, pt_save.Y, btn_SaveSign.Width, btn_SaveSign.Height);
                bRegSave = true;

            }
            bFormInit = true;
        }

        //设置画布背景颜色
        private void btn_BKColor_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                Color color = dlg.Color;
                btn_BKColor.BackColor = color;

                axSignViewer1.SetBKColor(color.R, color.G, color.B);

                //画布颜色需清除当前笔迹后生效
                axSignViewer1.ClearSign();
            }
        }

        //设置笔宽度范围，这里只调整笔上限，如需笔宽固定，设置笔下限与上限相等即可
        private void track_PenWidth_Scroll(object sender, EventArgs e)
        {
            text_PenWidth.Text = track_PenWidth.Value.ToString();

            axSignViewer1.SetPenSizeRange(1, int.Parse(text_PenWidth.Text));
        }

        private void check_BorderVisible_CheckedChanged(object sender, EventArgs e)
        {
            axSignViewer1.BorderVisible = check_BorderVisible.Checked;
        }

        //设置边框颜色
        private void btn_BorderColor_Click(object sender, EventArgs e)
        {
            ColorDialog dlg = new ColorDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                Color color = dlg.Color;
                btn_BorderColor.BackColor = color;

                axSignViewer1.SetBorderColor(color.R, color.G, color.B);

            }
        }

        private void btn_FilePath_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dlg = new FolderBrowserDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                text_FilePath.Text = dlg.SelectedPath;
            }
        }

        //清除笔迹
        private void btn_ClearSign_Click(object sender, EventArgs e)
        {
            ClearSign();
        }

        //保存笔迹为图像
        private void btn_SaveSign_Click(object sender, EventArgs e)
        {
            SaveSign();
        }

        //设置事件通知
        private void SignViewerCtl_DevNotifyEvent(object sender, AxSignViewerLib._DSignViewerEvents_DevNotifyEventEvent e)
        {
            if(bFlagchinese==true)
            {
                toolStripStatusLabel1.Text = "连接状态:" + (e.status == 1 ? "已连接" : "未连接");
            }
            else
            {
                toolStripStatusLabel1.Text = "Status:" + (e.status == 1 ? "connected" : "disconnected");
            }

        }

        // 设置按键消息通知
        private void SignViewerCtl_KeyEvent(object sender, AxSignViewerLib._DSignViewerEvents_KeyEventEvent e)
        {
            switch (e.vKeyCode)
            {
                case 8:
                    SaveSign();
                    break;
                case 9:
                    ClearSign();
                    break;
                case 10:
                    ClearSign();
                    break;
                default:
                    break;
            }
        }


        //控制鼠标
        private void check_MouseControl_CheckedChanged(object sender, EventArgs e)
        {
            axSignViewer1.MouseControl(check_MouseControl.Checked);
        }

        //设置鼠标映射活动屏为扩展屏
        private void check_MouseMapping_CheckedChanged(object sender, EventArgs e)
        {
            axSignViewer1.ExtendDisplay = check_MouseMapping.Checked;
        }

        //设置书写映射模式（屏幕区域或控件区域)
        private void combox_MappingMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            axSignViewer1.DisplayMapMode = combo_MappingMode.SelectedIndex;
        }

        //设置书写方式（电磁笔或手指触摸)
        private void combo_SignMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            axSignViewer1.SignMode = combo_SignMode.SelectedIndex;
        }

        //切换到橡皮擦功能
        private void check_Eraser_CheckedChanged(object sender, EventArgs e)
        {
            axSignViewer1.SetPenMode(check_Eraser.Checked ? 1 : 0);
        }

        //笔点击事件响应
        private void SignViewerCtl_BtnClickEvent(object sender, AxSignViewerLib._DSignViewerEvents_BtnClickEventEvent e)
        {
            switch ((uint)e.nBtnIndex)
            {
                case Btn_Index_ClearSign:
                    {
                        btn_ClearSign.Enabled = false;
                        btn_ClearSign_Click(sender, null);
                        System.Threading.Thread.Sleep(200);
                        btn_ClearSign.Enabled = true;
                    }
                    break;
                case Btn_Index_SaveSign:
                    {
                        btn_SaveSign.Enabled = false;
                        btn_SaveSign_Click(sender, null);
                        System.Threading.Thread.Sleep(200);
                        btn_SaveSign.Enabled = true;
                    }
                    break;
            }
        }

        //系统Touch开关
        private void check_SystemTouch_CheckedChanged(object sender, EventArgs e)
        {
            if (check_SystemTouch.Checked)
            {
                axSignViewer1.EnableSystemTouch(true);
            }
            else
            {
                axSignViewer1.EnableSystemTouch(false);
            }
        }


        //针对数位屏的笔点击事件回调注册（注册的按钮区域相对于屏是固定区域，如窗口移动或按钮移动，需重新计算注册)
        private void frmMain_Move(object sender, EventArgs e)
        {

            if (bFormInit == false)
                return;

            int left = 0, top = 0, right = 0, bottom = 0;
            axSignViewer1.GetScreenRect(ref left, ref top, ref right, ref bottom);
            if (right - left > 0)
            {
                Point pt_clear = PointToScreen(btn_ClearSign.Location);
                //转换到相对于扩展屏的屏幕坐标
                pt_clear.X -= left;
                pt_clear.Y -= top;
                if (bRegClear)
                {
                    axSignViewer1.UnregBtnClickEvent((int)Btn_Index_ClearSign);
                }
                axSignViewer1.RegBtnClickEvent(Btn_Index_ClearSign, pt_clear.X, pt_clear.Y, btn_ClearSign.Width, btn_ClearSign.Height);
                bRegClear = true;
                Point pt_save = PointToScreen(btn_SaveSign.Location);
                //转换到相对于扩展屏的屏幕坐标
                pt_save.X -= left;
                pt_save.Y -= top;
                if (bRegSave)
                {
                    axSignViewer1.UnregBtnClickEvent((int)Btn_Index_SaveSign);
                }
                axSignViewer1.RegBtnClickEvent(Btn_Index_SaveSign, pt_save.X, pt_save.Y, btn_SaveSign.Width, btn_SaveSign.Height);
                bRegSave = true;
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void SignViewerCtl_TouchEvent(object sender, AxSignViewerLib._DSignViewerEvents_TouchEventEvent e)
        {
            //该事件响应条件：需将控件SignMode 属性设置为1或2，以保证触控模式是使用的
            ushort x = (ushort)(e.data & 0xFFFF);
            ushort y = (ushort)(e.data >> 16);
            switch((TouchStatus)e.type)
            {
                case TouchStatus.TouchStatus_Down:
                    {
                        Console.WriteLine("Down  x:"+x.ToString()+" y:"+y.ToString());
                    }
                    break;
                case TouchStatus.TouchStatus_Move:
                    {
                        Console.WriteLine("Move  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
                case TouchStatus.TouchStatus_Up:
                    {
                        Console.WriteLine("Up  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
            }
        }


        // 清空显示
        private void ClearSign()
        {
            axSignViewer1.ClearSign();

            toolStripStatusLabel2.Text = "";
        }

        private void SaveSign()
        {
            if (text_FilePath.Text.Length == 0)
            {
                if(bFlagchinese==true)
                {
                    MessageBox.Show("未设置笔迹存储目录");
                }
                else
                {
                    MessageBox.Show("invalid file directory!");
                } 
                return;
            }

            string strType = "";
            switch (combo_ImageType.SelectedIndex)
            {
                case 0:
                    {
                        strType = "jpg";
                    }
                    break;
                case 1:
                    {
                        strType = "png";
                    }
                    break;
                case 2:
                    {
                        strType = "gif";
                    }
                    break;
                case 3:
                    {
                        strType = "bmp";
                    }
                    break;
                default:
                    {
                        strType = "bmp";
                    }
                    break;
            }

            string file_path = text_FilePath.Text + "sign." + strType;

            if (check_SingleSign.Checked)
            {
                //保存为带透明通道的笔迹图片(png格式)
                axSignViewer1.SaveSignToFile(text_FilePath.Text + "sign.png", 0, 0);
            }
            else
            {
                axSignViewer1.SaveImageToFile(file_path, (short)combo_ImageType.SelectedIndex);
            }
            if(bFlagchinese==true)
            {
                toolStripStatusLabel2.Text = "保存笔迹完成";
            }
            else
            {
                toolStripStatusLabel2.Text = "save ok";
            }
        }
       
        private void SignViewerCtl_Penevent(object sender, AxSignViewerLib._DSignViewerEvents_PenEventEvent e)
        {
            ushort x = (ushort)(e.data & 0xFFFF);
            ushort y = (ushort)(e.data >> 16);
            switch ((PenStatus)e.type)
            {
                case PenStatus.PenStatus_Hover:
                    {
                        Console.WriteLine("Hover  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
                case PenStatus.PenStatus_Down:
                    {
                        Console.WriteLine("Down  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
                case PenStatus.PenStatus_Move:
                    {
                        Console.WriteLine("Move  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
                case PenStatus.PenStatus_Up:
                    {
                        Console.WriteLine("Up  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
                case PenStatus.PenStatus_Leave:
                    {
                        Console.WriteLine("Leave  x:" + x.ToString() + " y:" + y.ToString());
                    }
                    break;
            }
        }
    }
}
