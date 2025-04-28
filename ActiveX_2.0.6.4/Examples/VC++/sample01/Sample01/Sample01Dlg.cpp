
// Sample01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sample01.h"
#include "Sample01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About

const  long Btn_Index_Clear = 1;
const  long Btn_Index_Save = 2;

CSample01Dlg::CSample01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSample01Dlg::IDD, pParent), languagenum(theApp.language)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mylanguage = (MyEnumLanguage)languagenum;
}

void CSample01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SIGNVIEWERCTRL1, m_SignViewerCtl);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_Btn_PenColor);
	DDX_Control(pDX, IDC_SLIDER_PENWIDTH, m_Slider_PenWidth);
	DDX_Control(pDX, IDC_EDIT_PENWIDTH, m_Edit_PenWidth);
	DDX_Control(pDX, IDC_COMBO1, m_Combo_SignMode);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_Btn_BKColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, m_Btn_BorderColor);
	DDX_Control(pDX, IDC_CHECK1, m_Btn_BorderVisible);
	DDX_Control(pDX, IDC_EDIT_FILEDIR, m_Edit_FileDir);
	DDX_Control(pDX, IDC_BUTTON4, m_Btn_Browser);
	DDX_Control(pDX, IDC_COMBO2, m_Combo_ImageType);
	DDX_Control(pDX, IDC_CHECK2, m_Btn_SingleSign);
	DDX_Control(pDX, IDC_CHECK3, m_Btn_MouseControl);
	DDX_Control(pDX, IDC_CHECK4, m_Btn_ExtendDisplay);
	DDX_Control(pDX, IDC_COMBO3, m_Combo_MappingMode);
	DDX_Control(pDX, IDC_CHECK5, m_Btn_Eraser);
	DDX_Control(pDX, IDC_CHECK6, m_Btn_SystemTouch);
}

BEGIN_MESSAGE_MAP(CSample01Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CSample01Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CSample01Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CSample01Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK6, &CSample01Dlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK5, &CSample01Dlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CSample01Dlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CSample01Dlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CSample01Dlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CSample01Dlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON3, &CSample01Dlg::OnBnClickedMfccolorbutton3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_PENWIDTH, &CSample01Dlg::OnNMCustomdrawSliderPenwidth)
	ON_BN_CLICKED(IDC_BUTTON4, &CSample01Dlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSample01Dlg::OnCbnSelchangeCombo3)
	ON_WM_MOVE()

	ON_CBN_SELCHANGE(IDC_COMBO1, &CSample01Dlg::OnCbnSelchangeComboSignmode)

	ON_BN_CLICKED(IDC_BTN_SAVE2, &CSample01Dlg::OnBnClickedBtnSave2)
	ON_BN_CLICKED(IDC_BTN_SAVE3, &CSample01Dlg::OnBnClickedBtnSave3)
END_MESSAGE_MAP()


// CSample01Dlg message handlers

BOOL CSample01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	BYTE r, g, b;
	//default pen colour 
	m_SignViewerCtl.GetPenColor(&r, &g, &b);
	m_Btn_PenColor.SetColor(RGB(r, g, b));

	//Default background color
	m_SignViewerCtl.GetBKColor(&r, &g, &b);
	m_Btn_BKColor.SetColor(RGB(r, g, b));

	//Default border color
	m_SignViewerCtl.GetBorderColor(&r, &g, &b);
	m_Btn_BorderColor.SetColor(RGB(r, g, b));

	//Whether the border is displayed or not
	m_Btn_BorderVisible.SetCheck(m_SignViewerCtl.GetBorderVisible() ? 1 : 0);

	//Writing mode
	if (mylanguage == MyEnumLanguage_chinese)
	{
		m_Combo_SignMode.AddString(_T("µç´Å±Ê"));		//0
		m_Combo_SignMode.AddString(_T("Touch"));		//1
		m_Combo_SignMode.AddString(_T("»ìºÏÄ£Ê½"));		//2
		m_Combo_SignMode.SetCurSel(m_SignViewerCtl.GetSignMode());
	}
	else
	{
		m_Combo_SignMode.AddString(_T("Pen"));			//0
		m_Combo_SignMode.AddString(_T("Touch"));		//1
		m_Combo_SignMode.AddString(_T("Pen&Touch"));	//2
		m_Combo_SignMode.SetCurSel(m_SignViewerCtl.GetSignMode());
	}


	//Pen width
	LONG min = 0, max = 0;
	m_SignViewerCtl.GetPenSizeRange(&min, &max);
	m_Slider_PenWidth.SetRange(min, max);
	m_Slider_PenWidth.SetPos(max / 2);

	//Save Picture Types
	m_Combo_ImageType.AddString(_T("0-jpg"));
	m_Combo_ImageType.AddString(_T("1-png"));
	m_Combo_ImageType.AddString(_T("2-gif"));
	m_Combo_ImageType.AddString(_T("3-bmp"));
	m_Combo_ImageType.SetCurSel(0);

	//default path
	m_Edit_FileDir.SetWindowText(_T("D:\\"));

	//Write mapping mode (0 screen 1 control), which is invalid for digital screen, default mapping of digital screen to screen
	if (mylanguage == MyEnumLanguage_chinese)
	{
		m_Combo_MappingMode.AddString(_T("0-ÆÁÄ»"));
		m_Combo_MappingMode.AddString(_T("1-¿Ø¼þ"));
	}
	else
	{
		m_Combo_MappingMode.AddString(_T("0-Screen"));
		m_Combo_MappingMode.AddString(_T("1-Control"));
	}
	m_Combo_MappingMode.SetCurSel(0);


	m_Bar_StatusBar.Create(WS_CHILD | WS_VISIBLE | SBT_OWNERDRAW, CRect(0, 0, 0, 0), this, 0);

	int strPartDim[3] = { 60, 180, -1 }; //Split quantity
	m_Bar_StatusBar.SetParts(3, strPartDim);

	//Setting status bar text
	if (mylanguage == MyEnumLanguage_chinese)
	{
		m_Bar_StatusBar.SetText(_T("Á¬½Ó×´Ì¬"), 0, 0);
		m_Bar_StatusBar.SetText(m_SignViewerCtl.IsConnected() ? _T("ÒÑÁ¬½Ó") : _T("Î´Á¬½Ó"), 1, 0);
	}
	else
	{
		m_Bar_StatusBar.SetText(_T("Status"), 0, 0);
		m_Bar_StatusBar.SetText(m_SignViewerCtl.IsConnected() ? _T("connected") : _T("disconnected"), 1, 0);
	}

	m_Bar_StatusBar.SetText(_T(""), 2, 0);

	m_bRegBtnClear = FALSE;
	m_bRegBtnSave = FALSE;

	//Screen push and pen click events for digital screens 
	long left = 0, top, right = 0, bottom = 0;
	m_SignViewerCtl.GetScreenRect(&left, &top, &right, &bottom);
	if (right - left > 0)
	{
		CRect rect;
		GetWindowRect(&rect);
		//Push the window to the center of the screen
		SetWindowPos(CWnd::FromHandle(HWND_TOPMOST), left + (right - left - rect.Width()) / 2, top + (bottom - top - rect.Height()) / 2, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);

		//Registered Pen Click Event
		CRect rectClear, rectSave;
		GetDlgItem(IDC_BTN_CLEAR)->GetWindowRect(&rectClear);
		//Screen Seat Converting Button Coordinates to Relative Extension Screen
		rectClear.left -= left;
		rectClear.right -= left;
		m_SignViewerCtl.RegBtnClickEvent(Btn_Index_Clear, rectClear.left, rectClear.top, rectClear.Width(), rectClear.Height());
		m_bRegBtnClear = TRUE;

		GetDlgItem(IDC_BTN_SAVE)->GetWindowRect(&rectSave);
		//Convert button coordinates to screen coordinates of relative expansion screen
		rectSave.left -= left;
		rectSave.right -= left;
		m_SignViewerCtl.RegBtnClickEvent(Btn_Index_Save, rectSave.left, rectSave.top, rectSave.Width(), rectSave.Height());
		m_bRegBtnSave = TRUE;
	}
	//m_SignViewerCtl.SetBKPicture(_T("E:\\WizardImage00.bmp"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSample01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSample01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//SetBorderVisible
void CSample01Dlg::OnBnClickedCheck1()
{
	m_SignViewerCtl.SetBorderVisible(m_Btn_BorderVisible.GetCheck());
}

//MouseControl
void CSample01Dlg::OnBnClickedCheck3()
{
	m_SignViewerCtl.MouseControl(m_Btn_MouseControl.GetCheck());
}

//SetExtendDisplay
void CSample01Dlg::OnBnClickedCheck4()
{
	m_SignViewerCtl.SetExtendDisplay(m_Btn_ExtendDisplay.GetCheck());
}

//SetPenMode
void CSample01Dlg::OnBnClickedCheck5()
{
	m_SignViewerCtl.SetPenMode(m_Btn_Eraser.GetCheck() ? 1 : 0);
}

//EnableSystemTouch
void CSample01Dlg::OnBnClickedCheck6()
{
	m_SignViewerCtl.EnableSystemTouch(m_Btn_SystemTouch.GetCheck());
}

//ClearSign
void CSample01Dlg::OnBnClickedBtnClear()
{
	m_SignViewerCtl.ClearSign();
	m_Bar_StatusBar.SetText(_T(""), 2, 0);

}

//Save Sign
void CSample01Dlg::OnBnClickedBtnSave()
{
	CString strFileDir, strFilePath;
	m_Edit_FileDir.GetWindowText(strFileDir);


	int nType = m_Combo_ImageType.GetCurSel();
	CString strImgType = _T("");
	switch (nType)
	{
	case 0:
	{
		strImgType = _T(".jpg");
	}
	break;
	case 1:
	{
		strImgType = _T(".png");
	}
	break;
	case 2:
	{
		strImgType = _T(".gif");
	}
	break;
	case 3:
	{
		strImgType = _T(".bmp");

	}
	break;
	default:
	{
		strImgType = _T(".jpg");

	}

	break;
	}
	strFilePath += strFileDir;

	GetDlgItem(IDC_BTN_SAVE)->EnableWindow(FALSE);
	if (m_Btn_SingleSign.GetCheck() == 1)
	{

		strFilePath += "sign11.png";

		m_SignViewerCtl.SaveSignToFile(strFilePath, 0, 0);	//Width = 0 height = 0 uses default width and height to specify custom width to scale images
	}
	else
	{
		strFilePath += "sign";
		strFilePath += strImgType;
		m_SignViewerCtl.SaveImageToFile(strFilePath, nType);
	}
	if (mylanguage==MyEnumLanguage_chinese)
	{
		m_Bar_StatusBar.SetText(_T("±£´æÍê³É"), 2, 0);
	}
	else
	{
		m_Bar_StatusBar.SetText(_T("save ok"), 2, 0);
	}
	Sleep(200);
	GetDlgItem(IDC_BTN_SAVE)->EnableWindow(TRUE);
}

//PenColor
void CSample01Dlg::OnBnClickedMfccolorbutton1()
{
	DWORD color = m_Btn_PenColor.GetColor();
	m_SignViewerCtl.SetPenColor(GetRValue(color), GetGValue(color), GetBValue(color));
}

//BKColor
void CSample01Dlg::OnBnClickedMfccolorbutton2()
{
	DWORD color = m_Btn_BKColor.GetColor();
	m_SignViewerCtl.SetBKColor(GetRValue(color), GetGValue(color), GetBValue(color));
	m_SignViewerCtl.ClearSign();
}

//BorderColor
void CSample01Dlg::OnBnClickedMfccolorbutton3()
{
	DWORD color = m_Btn_BorderColor.GetColor();
	m_SignViewerCtl.SetBorderColor(GetRValue(color), GetGValue(color), GetBValue(color));
}

//SetPenSizeRange
void CSample01Dlg::OnNMCustomdrawSliderPenwidth(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;

	int size = m_Slider_PenWidth.GetPos();
	m_SignViewerCtl.SetPenSizeRange(1, size);

	CString strMax;
	strMax.Format(_T("%d"), size);
	m_Edit_PenWidth.SetWindowText(strMax);
}


void CSample01Dlg::OnBnClickedButton4()
{

	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT("");
	BROWSEINFO      sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	if (mylanguage==MyEnumLanguage_chinese)
	{
		sInfo.lpszTitle = _T("ÇëÑ¡ÔñÒ»¸öÎÄ¼þ¼Ð£º");
	}
	else
	{
		sInfo.lpszTitle = _T("Select folder:");
	}
	
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}

	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}

	if (strFolderPath.GetLength() > 0)
	{
		m_Edit_FileDir.SetWindowText(strFolderPath);
	}
}

//SetDisplayMapMode
void CSample01Dlg::OnCbnSelchangeCombo3()
{
	m_SignViewerCtl.SetDisplayMapMode(m_Combo_MappingMode.GetCurSel());
}
BEGIN_EVENTSINK_MAP(CSample01Dlg, CDialogEx)
	ON_EVENT(CSample01Dlg, IDC_SIGNVIEWERCTRL1, 2, CSample01Dlg::DevNotifyEventSignviewerctrl1, VTS_I4)
	ON_EVENT(CSample01Dlg, IDC_SIGNVIEWERCTRL1, 4, CSample01Dlg::BtnClickEventSignviewerctrl1, VTS_I4)
	ON_EVENT(CSample01Dlg, IDC_SIGNVIEWERCTRL1, 6, CSample01Dlg::KeyEventSignviewerctrl1, VTS_I4 VTS_I4)
END_EVENTSINK_MAP()

//DevNotifyEventSignviewerctrl
void CSample01Dlg::DevNotifyEventSignviewerctrl1(long status)
{
	if (mylanguage==MyEnumLanguage_chinese)
	{	
		if (status == 0)
		{

			m_Bar_StatusBar.SetText(_T("ÒÑ¶Ï¿ª"), 1, 0);

		}
		else
		{
			m_Bar_StatusBar.SetText(_T("ÒÑÁ¬½Ó"), 1, 0);
		}
	}
	else
	{
		if (status == 0)
		{
			m_Bar_StatusBar.SetText(_T("disconnected"), 1, 0);

		}
		else
		{
			m_Bar_StatusBar.SetText(_T("connected"), 1, 0);
		}
	}
}

//BtnClickEventSignviewerctrl
void CSample01Dlg::BtnClickEventSignviewerctrl1(long nBtnIndex)
{
	switch (nBtnIndex)
	{
	case Btn_Index_Clear:
	{
		OnBnClickedBtnClear();
	}
	break;
	case Btn_Index_Save:
	{
		OnBnClickedBtnSave();
	}
	break;
	default:
		break;
	}
}

// KeyEventSignviewerctrl
void CSample01Dlg::KeyEventSignviewerctrl1(long PKeyCode, long VKeyCode)
{
	switch (VKeyCode)
	{
	case 8:
	{
		OnBnClickedBtnSave();
	}
	break;
	case 9:
	{
		OnBnClickedBtnClear();
	}
	break;
	case 10:
	{
		OnBnClickedBtnClear();
	}
	default:
		break;
	}
}

void CSample01Dlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	//Dynamic registration button coordinates
	if (GetSafeHwnd() != NULL && x > 0 && y > 0 && IsWindowVisible())
	{
		//Screen push and pen click events for digital screens
		long left = 0, top, right = 0, bottom = 0;
		m_SignViewerCtl.GetScreenRect(&left, &top, &right, &bottom);
		if (right - left > 0)
		{
			CRect rect;
			GetWindowRect(&rect);

			//Registered Pen Click Event
			CRect rectClear, rectSave;
			GetDlgItem(IDC_BTN_CLEAR)->GetWindowRect(&rectClear);
			//Convert button coordinates to screen coordinates of relative expansion screen
			rectClear.left -= left;
			rectClear.right -= left;

			if (m_bRegBtnClear)
			{
				m_SignViewerCtl.UnregBtnClickEvent(Btn_Index_Clear);
			}
			m_SignViewerCtl.RegBtnClickEvent(Btn_Index_Clear, rectClear.left, rectClear.top, rectClear.Width(), rectClear.Height());


			GetDlgItem(IDC_BTN_SAVE)->GetWindowRect(&rectSave);
			//Convert button coordinates to screen coordinates of relative expansion screen
			rectSave.left -= left;
			rectSave.right -= left;
			if (m_bRegBtnSave)
			{
				m_SignViewerCtl.UnregBtnClickEvent(Btn_Index_Save);
			}
			m_SignViewerCtl.RegBtnClickEvent(Btn_Index_Save, rectSave.left, rectSave.top, rectSave.Width(), rectSave.Height());
		}
	}
}

void CSample01Dlg::OnCbnSelchangeComboSignmode()
{
	int index = m_Combo_SignMode.GetCurSel();
	switch (index)
	{
	case 0:
	{
		m_SignViewerCtl.SetSignMode(0);
	}
	break;
	case 1:
	{
		m_SignViewerCtl.SetSignMode(1);
	}
	break;
	case 2:
	{
		m_SignViewerCtl.SetSignMode(2);
	}
	break;
	}
}



void CSample01Dlg::OnBnClickedBtnSave2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_SignViewerCtl.SaveTrajectory(_T("D:\\Sign.txt"));
}


void CSample01Dlg::OnBnClickedBtnSave3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_SignViewerCtl.ReshowTrajectory(_T("D:\\Sign.txt"),5);
}
