
// Sample01.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Sample01.h"
#include "Sample01Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample01App

BEGIN_MESSAGE_MAP(CSample01App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSample01App construction
int CSample01App::GetSystemVersion()
{
	int a = 0, b = 0, i = 0, j = 0;
	_asm
	{
		pushad
		mov ebx, fs:[0x18]; get self pointer from TEB
		mov eax, fs:[0x30]; get pointer to PEB / database
		mov ebx, [eax + 0A8h]; get OSMinorVersion
		mov eax, [eax + 0A4h]; get OSMajorVersion
		mov j, ebx
		mov i, eax
		popad
	}
	if ((i == 5) && (j == 0))
	{
		//Windows 2000
		return 1;
	}
	else if ((i == 5) && (j == 1))
	{
		//Windows XP
		return 1;
	}
	else if ((i == 5) && (j == 2))
	{
		//Windows 2003
		return 1;
	}
	else if ((i == 6) && (j == 0))
	{
		//Windows Vista
		return 3;
	}
	else if ((i == 6) && (j == 1))
	{
		//Win7
		return 3;
	}
	else
	{
		return 3;
	}

}

bool CSample01App::SetWndLanguage()
{
	CString strValue, strCpyFile, strtemp, strLanguage;

	CString itemVal;
	int len;
	GetModuleFileName(NULL, strValue.GetBuffer(MAX_PATH), MAX_PATH);
	strValue.ReleaseBuffer();
	len = strValue.ReverseFind('\\');
	strValue = strValue.Left(len);
	strtemp = strValue;
	strtemp += "\\Languageconfig.ini";
	::GetPrivateProfileString(_T("Config"), _T("Language"), _T(""), itemVal.GetBuffer(MAX_PATH), 256, strtemp);
	strtemp = itemVal;
	strLanguage = strtemp;

	if (strLanguage == _T(""))
	{
		LCID lcid = GetSystemDefaultLCID();
		if (lcid == 0x404 || lcid == 0x0404 || lcid == 0x1004 || lcid == 0x0804 || lcid == 0x1404 || lcid == 0x0c04)
		{
			strLanguage = _T("Chinese");
		}
	}
	try
	{
		if (_T("Chinese") == strLanguage)
		{
			if (3 == GetSystemVersion())
			{
				SetThreadUILanguage(MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT));
			}
			else
			{
				SetThreadLocale(MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT));
			}
			language = WMLanguage_chinese;
		}
		else
		{
			if (3 == GetSystemVersion())
			{
				SetThreadUILanguage(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));
			}
			else
			{
				SetThreadLocale(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_UK), SORT_DEFAULT));
			}
			language = WMLanguage_english;
		}
		return true;
	}
	catch (char *str)
	{
		return false;
	}
	
}

CSample01App::CSample01App()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	SetWndLanguage();

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CSample01App object

CSample01App theApp;


// CSample01App initialization

BOOL CSample01App::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CSample01Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

