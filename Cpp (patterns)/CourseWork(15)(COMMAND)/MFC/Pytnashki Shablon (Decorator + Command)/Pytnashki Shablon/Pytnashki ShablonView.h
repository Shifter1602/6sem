
// Pytnashki ShablonView.h : интерфейс класса CPytnashkiShablonView
//

#pragma once


class CPytnashkiShablonView : public CView
{
protected: // создать только из сериализации
	CPytnashkiShablonView();
	DECLARE_DYNCREATE(CPytnashkiShablonView)

// Атрибуты
public:
	CPytnashkiShablonDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	afx_msg void OnPaint(CDC *pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CPytnashkiShablonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	virtual void  ExitButtonClick();
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // отладочная версия в Pytnashki ShablonView.cpp
inline CPytnashkiShablonDoc* CPytnashkiShablonView::GetDocument() const
   { return reinterpret_cast<CPytnashkiShablonDoc*>(m_pDocument); }
#endif

