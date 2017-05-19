
// MainFrm.h : интерфейс класса CMainFrame
//

#pragma once

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected: // создать только из сериализации
	
	//afx_msg void OnLButtonClick();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_DYNCREATE(CMainFrame)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


