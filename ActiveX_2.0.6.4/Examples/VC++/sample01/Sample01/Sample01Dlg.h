
// Sample01Dlg.h : header file
//

#pragma once
#include "SignViewerCtrl.h"
#include "afxcolorbutton.h"
#include "afxcmn.h"
#include "afxwin.h"

enum MyEnumLanguage
{
	MyEnumLanguage_english = 1,
	MyEnumLanguage_chinese
};


// CSample01Dlg dialog
class CSample01Dlg : public CDialogEx
{
	// Construction
public:
	CSample01Dlg(CWnd* pParent = NULL);	// standard constructor

										// Dialog Data
	
	enum { IDD = IDD_SAMPLE01_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	const int languagenum;			// Implementation
	MyEnumLanguage mylanguage;
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

private:
	CSignViewerCtrl m_SignViewerCtl;
	CMFCColorButton m_Btn_PenColor;
	CSliderCtrl m_Slider_PenWidth;
	CEdit m_Edit_PenWidth;
	CComboBox m_Combo_SignMode;
	CMFCColorButton m_Btn_BKColor;
	CMFCColorButton m_Btn_BorderColor;
	CButton m_Btn_BorderVisible;
	CEdit m_Edit_FileDir;
	CButton m_Btn_Browser;
	CComboBox m_Combo_ImageType;
	CButton m_Btn_SingleSign;
	CButton m_Btn_MouseControl;
	CButton m_Btn_ExtendDisplay;
	CComboBox m_Combo_MappingMode;
	CButton m_Btn_Eraser;
	CButton m_Btn_SystemTouch;
	CStatusBarCtrl m_Bar_StatusBar;

	BOOL	m_bRegBtnClear;
	BOOL	m_bRegBtnSave;
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	afx_msg void OnBnClickedMfccolorbutton3();
	afx_msg void OnNMCustomdrawSliderPenwidth(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCbnSelchangeCombo3();
	DECLARE_EVENTSINK_MAP()
	void DevNotifyEventSignviewerctrl1(long status);
	void BtnClickEventSignviewerctrl1(long nBtnIndex);
	void KeyEventSignviewerctrl1(long PKeyCode, long VKeyCode);

	afx_msg void OnMove(int x, int y);

	afx_msg void OnCbnSelchangeComboSignmode();

	afx_msg void OnBnClickedBtnSave2();
	afx_msg void OnBnClickedBtnSave3();
};
