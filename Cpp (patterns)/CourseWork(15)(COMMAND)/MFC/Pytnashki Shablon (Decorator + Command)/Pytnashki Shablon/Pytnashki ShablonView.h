
// Pytnashki ShablonView.h : ��������� ������ CPytnashkiShablonView
//

#pragma once


class CPytnashkiShablonView : public CView
{
protected: // ������� ������ �� ������������
	CPytnashkiShablonView();
	DECLARE_DYNCREATE(CPytnashkiShablonView)

// ��������
public:
	CPytnashkiShablonDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	afx_msg void OnPaint(CDC *pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CPytnashkiShablonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	virtual void  ExitButtonClick();
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � Pytnashki ShablonView.cpp
inline CPytnashkiShablonDoc* CPytnashkiShablonView::GetDocument() const
   { return reinterpret_cast<CPytnashkiShablonDoc*>(m_pDocument); }
#endif

