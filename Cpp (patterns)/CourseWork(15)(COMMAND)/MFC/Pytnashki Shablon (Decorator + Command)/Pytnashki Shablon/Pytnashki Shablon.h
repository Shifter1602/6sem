
// Pytnashki Shablon.h : главный файл заголовка для приложения Pytnashki Shablon
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CPytnashkiShablonApp:
// О реализации данного класса см. Pytnashki Shablon.cpp
//

class CPytnashkiShablonApp : public CWinApp
{
public:
	CPytnashkiShablonApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPytnashkiShablonApp theApp;
