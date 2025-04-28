
// Sample01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSample01App:
// See Sample01.cpp for the implementation of this class
//
enum WMLanguage
{
	WMLanguage_english=1,
	WMLanguage_chinese	
};

class CSample01App : public CWinApp
{
public:
	CSample01App();
private:
	int GetSystemVersion();
	bool SetWndLanguage();
// Overrides
public:
	virtual BOOL InitInstance();
	WMLanguage language;
// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSample01App theApp;