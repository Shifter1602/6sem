
// Pytnashki Shablon.h : ������� ���� ��������� ��� ���������� Pytnashki Shablon
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CPytnashkiShablonApp:
// � ���������� ������� ������ ��. Pytnashki Shablon.cpp
//

class CPytnashkiShablonApp : public CWinApp
{
public:
	CPytnashkiShablonApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPytnashkiShablonApp theApp;
