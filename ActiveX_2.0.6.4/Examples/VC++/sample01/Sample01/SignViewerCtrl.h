#pragma once

// Computer generated IDispatch wrapper class created by Microsoft Visual C++.
// Note: Do not modify the contents of this file. If this is the case
// Microsoft Visual C++ is rebuilt and your changes will be overwritten.

/////////////////////////////////////////////////////////////////////////////

// CSignviewerctrl wrapper class

class CSignViewerCtrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CSignViewerCtrl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x5E845176, 0xC3D3, 0x4A79, { 0x92, 0xD7, 0xCD, 0x38, 0xF1, 0x11, 0x26, 0x21 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Characteristic
public:


// operation
public:

// _DSignViewer

// Functions
//

	void ClearSign()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SetPenColor(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
	{
		static BYTE parms[] = VTS_UI1 VTS_UI1 VTS_UI1 ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nRed, nGreen, nBlue);
	}
	void GetPenColor(unsigned char * lpRed, unsigned char * lpGreen, unsigned char * lpBlue)
	{
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lpRed, lpGreen, lpBlue);
	}
	void SetPenSizeRange(long nMin, long nMax)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMin, nMax);
	}
	void GetPenSizeRange(long * lpMin, long * lpMax)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lpMin, lpMax);
	}
	BOOL IsConnected()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void MouseControl(BOOL bEnabled)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bEnabled);
	}
	void SetBorderColor(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
	{
		static BYTE parms[] = VTS_UI1 VTS_UI1 VTS_UI1 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nRed, nGreen, nBlue);
	}
	void GetBorderColor(unsigned char * lpRed, unsigned char * lpGreen, unsigned char * lpBlue)
	{
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lpRed, lpGreen, lpBlue);
	}
	void SetBKColor(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
	{
		static BYTE parms[] = VTS_UI1 VTS_UI1 VTS_UI1 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nRed, nGreen, nBlue);
	}

	void GetBKColor(unsigned char * lpRed, unsigned char * lpGreen, unsigned char * lpBlue)
	{
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PUI1 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lpRed, lpGreen, lpBlue);
	}
	BOOL SaveImageToFile(LPCTSTR lpstrFileName, short nFormat)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I2 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, lpstrFileName, nFormat);
		return result;
	}
	BOOL SaveImageToFileEx(LPCTSTR lpstrFileName, short nFormat, unsigned short width, unsigned short height, unsigned short quality)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_UI2 VTS_UI2 VTS_UI2 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, lpstrFileName, nFormat, width, height, quality);
		return result;
	}
	BOOL SaveSignToFile(LPCTSTR lpstrFileName, unsigned short width, unsigned short height)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_UI2 VTS_UI2 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, lpstrFileName, width, height);
		return result;
	}
	void SetPenMode(long nMode)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMode);
	}
	long RegBtnClickEvent(unsigned long nBtnIndex, long x, long y, long w, long h)
	{
		long result;
		static BYTE parms[] = VTS_UI4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nBtnIndex, x, y, w, h);
		return result;
	}
	void UnregBtnClickEvent(long nBtnIndex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nBtnIndex);
	}
	CString SaveImageToBase64(short nFormat, unsigned short width, unsigned short height, unsigned short quality)
	{
		CString result;
		static BYTE parms[] = VTS_I2 VTS_UI2 VTS_UI2 VTS_UI2 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, nFormat, width, height, quality);
		return result;
	}
	CString SaveSignToBase64(unsigned short width, unsigned short height)
	{
		CString result;
		static BYTE parms[] = VTS_UI2 VTS_UI2 ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, width, height);
		return result;
	}
	BOOL GetScreenRect(long * left, long * top, long * right, long * bottom)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, left, top, right, bottom);
		return result;
	}
	void EnableSystemTouch(BOOL bEnable)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bEnable);
	}
	void SetScreenRotation(long angle)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, angle);
	}
	long GetScreenX()
	{
		long result;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetScreenY()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetScreenWidth()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetScreenHeight()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void EnableSign(BOOL bEnable)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bEnable);
	}
	BOOL IsOperated()
	{
		BOOL result;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetBKPicture(LPCTSTR BKPicFilePath)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, NULL, parms, BKPicFilePath);
	}
	BOOL SaveTrajectory(LPCTSTR strFileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFileName);
		return result;
	}

	BOOL ReshowTrajectory(LPCTSTR strFilePath, long time)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strFilePath, time);
		return result;
	}
// Properties
//

BOOL GetBorderVisible()
{
	BOOL result;
	GetProperty(0x9, VT_BOOL, (void*)&result);
	return result;
}
void SetBorderVisible(BOOL propVal)
{
	SetProperty(0x9, VT_BOOL, propVal);
}
BOOL GetExtendDisplay()
{
	BOOL result;
	GetProperty(0x16, VT_BOOL, (void*)&result);
	return result;
}
void SetExtendDisplay(BOOL propVal)
{
	SetProperty(0x16, VT_BOOL, propVal);
}
long GetDisplayMapMode()
{
	long result;
	GetProperty(0x17, VT_I4, (void*)&result);
	return result;
}
void SetDisplayMapMode(long propVal)
{
	SetProperty(0x17, VT_I4, propVal);
}
long GetSignMode()
{
	long result;
	GetProperty(0x18, VT_I4, (void*)&result);
	return result;
}
void SetSignMode(long propVal)
{
	SetProperty(0x18, VT_I4, propVal);
}
BOOL GetCursorVisible()
{
	BOOL result;
	GetProperty(0x22, VT_BOOL, (void*)&result);
	return result;
}
void SetCursorVisible(BOOL propVal)
{
	SetProperty(0x22, VT_BOOL, propVal);
}
long GetSignDrawingQuality()
{
	long result;
	GetProperty(0x23, VT_I4, (void*)&result);
	return result;
}
void SetSignDrawingQuality(long propVal)
{
	SetProperty(0x23, VT_I4, propVal);
}


};
