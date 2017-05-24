

// Pytnashki ShablonView.cpp : реализация класса CPytnashkiShablonView
//

#include "stdafx.h"
#include <afxwin.h>
#include "Command.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Pytnashki Shablon.h"
#endif

#include "Pytnashki ShablonDoc.h"
#include "Pytnashki ShablonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString menuMode;
bool wasStartGame = false;
int moveCount = 0;
int style=0;

//////////////////////////////////////////////////////////////////////////
Reciever r;
int size;
int ** arr;
//////////////////////////////////////////////////////////////////////////



//Шаблон Декоратор:

class IComponent 
{
public:
        virtual void operation() = 0;
        virtual ~IComponent(){}
};

class Component : public IComponent 
{
public:
	virtual void operation() {}
        virtual void operation(CDC * pDC) 
		{
			CBrush myBrush2 = CBrush(RGB(255, 255, 255));
			RECT rect2;
			rect2.top = 0;
			rect2.left = 0;
			rect2.bottom= 1100;
			rect2.right = 2000;
			pDC->FillRect(&rect2, &myBrush2);
        }
};

class DecoratorOne : public IComponent 
{
        std::shared_ptr<IComponent> m_component;
 
public:
        DecoratorOne(std::shared_ptr<IComponent> component): m_component(component) {}
	virtual void operation() {}
        virtual void operation(CDC * pDC) 
		{
			m_component->operation();
			pDC->Rectangle(1100, 100, 1200, 150);
			pDC->TextOutA(1110, 110, "Меню");
			pDC->Rectangle(1100, 200, 1250, 250);	
			pDC->TextOutA(1110, 210, "Новая игра");
			pDC->Rectangle(1100, 300, 1300, 350);
			pDC->TextOutA(1110, 310, "Выбор стиля");
			pDC->Rectangle(1100, 400, 1350, 450);
			pDC->TextOutA(1110, 410, "Выход");
        }
};
 
class DecoratorTwo : public IComponent 
{
        std::shared_ptr<IComponent> m_component;
 
public:
        DecoratorTwo(std::shared_ptr<IComponent> component): m_component(component) {}
 virtual void operation() {}
        virtual void operation(CDC * pDC) 
		{
				m_component->operation();	
		pDC->Rectangle(200, 100, 400, 150);
		pDC->TextOutA(210, 110, "Игровое поле 2х2");
		pDC->Rectangle(200, 200, 500, 250);
		pDC->TextOutA(210, 210, "Игровое поле 3х3");
		pDC->Rectangle(200, 300, 600, 350);
		pDC->TextOutA(210, 310, "Игровое поле 4х4");
		pDC->Rectangle(200, 400, 700, 450);
		pDC->TextOutA(210, 410, "Игровое поле 5х5");
		pDC->Rectangle(200, 500, 800, 550);
		pDC->TextOutA(210, 510, "Игровое поле 6х6");
        }
};

class DecoratorThree : public IComponent 
{
        std::shared_ptr<IComponent> m_component;
 
public:
        DecoratorThree(std::shared_ptr<IComponent> component): m_component(component) {}
		 virtual void operation() {}
        virtual void operation(CDC *pDC) 
		{
                m_component->operation();
				pDC->Rectangle(1200, 100, 1300, 150);
				pDC->TextOutA(1210, 110, "Меню");

				pDC->Rectangle(1000, 200, 1100, 250);
				pDC->TextOutA(1010, 210, "<----------");
				pDC->Rectangle(1200, 200, 1300, 250);
				pDC->TextOutA(1210, 210, "---------->");

				CString s;
				s.Format("%i", moveCount);
				pDC->Rectangle(1200, 300, 1380, 370);
				pDC->TextOutA(1210, 310, "Количество ходов:");
				pDC->TextOutA(1240, 340, s);

				CBrush myBrush(RGB(55, 155, 255));
				RECT rect;
				rect.top = 0;
				rect.left = 0;
				rect.bottom=10+110*r.GetArrSize();
				rect.right = 10+110*r.GetArrSize();
				pDC->FillRect(&rect, &myBrush);
				//**********Рисование массива******************
				for(int i=0;i<r.GetArrSize(); i++)
				{
					for(int j=0;j<r.GetArrSize();j++)
					{
						if(r.GetArr()[j][i]!=0)
						{
							pDC->Rectangle(110*i+10, 110*j+10, 110*i+110, 110*j+110);
							CString s;
							s.Format("%i", r.GetArr()[j][i]);
							pDC->TextOutA(110*i+50, 110*j+50, s);
						}
					}
				}
        }
};


class DecoratorFour : public IComponent 
{
        std::shared_ptr<IComponent> m_component;
 
public:
        DecoratorFour(std::shared_ptr<IComponent> component): m_component(component) {}
		 virtual void operation() {}
        virtual void operation(CDC *pDC) 
		{
                m_component->operation();
				pDC->Rectangle(200, 100, 600, 150);
				pDC->TextOutA(210, 110, "Просто белые квадратики");
				pDC->Rectangle(200, 200, 700, 250);
				pDC->TextOutA(210, 210, "Обычные белые кружочки");
        }
};

class DecoratorFive : public IComponent 
{
        std::shared_ptr<IComponent> m_component;
 
public:
        DecoratorFive(std::shared_ptr<IComponent> component): m_component(component) {}
		 virtual void operation() {}
        virtual void operation(CDC *pDC) 
		{
                m_component->operation();
				pDC->Rectangle(1200, 100, 1300, 150);
				pDC->TextOutA(1210, 110, "Меню");

				pDC->Rectangle(1000, 200, 1100, 250);
				pDC->TextOutA(1010, 210, "<----------");
				pDC->Rectangle(1200, 200, 1300, 250);
				pDC->TextOutA(1210, 210, "---------->");

				CString s;
				s.Format("%i", moveCount);
				pDC->Rectangle(1200, 300, 1380, 370);
				pDC->TextOutA(1210, 310, "Количество ходов:");
				pDC->TextOutA(1240, 340, s);

				CBrush myBrush(RGB(55, 155, 255));
				RECT rect;
				rect.top = 0;
				rect.left = 0;
				rect.bottom=10+110*r.GetArrSize();
				rect.right = 10+110*r.GetArrSize();
				pDC->FillRect(&rect, &myBrush);
				//**********Рисование массива******************
				for(int i=0;i<r.GetArrSize(); i++)
				{
					for(int j=0;j<r.GetArrSize();j++)
					{
						if(r.GetArr()[j][i]!=0)
						{
							pDC->Ellipse(110*i+10, 110*j+10, 110*i+110, 110*j+110);
							//pDC->Rectangle(110*i+10, 110*j+10, 110*i+110, 110*j+110);
							CString s;
							s.Format("%i", r.GetArr()[j][i]);
							pDC->TextOutA(110*i+50, 110*j+50, s);
						}
					}
				}
        }
};



// CPytnashkiShablonView

IMPLEMENT_DYNCREATE(CPytnashkiShablonView, CView)

BEGIN_MESSAGE_MAP(CPytnashkiShablonView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CPytnashkiShablonView

CPytnashkiShablonView::CPytnashkiShablonView()
{
	// TODO: добавьте код создания

}


CPytnashkiShablonView::~CPytnashkiShablonView()
{
}

BOOL CPytnashkiShablonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs
	r=Reciever(3);
	menuMode = "Menu Open";
	return CView::PreCreateWindow(cs);
}

void MenuFunction(CDC *pDC)
{
	if(menuMode == "Menu Open")
	{
		Component* pCompObj = new Component();
		DecoratorOne* pDecOne = new DecoratorOne((std::shared_ptr<IComponent>)pCompObj); 
		pDecOne->operation(pDC);
	}

	//*****Restart****
	//-------------
	//*****Выбор поля(размер)**
	//Пять кнопок: поля на 2, 3, 4, 5, 6 клеток
	else if(menuMode == "Menu NG")
	{
		Component* pCompObj = new Component();
		DecoratorTwo* pDecTwo = new DecoratorTwo((std::shared_ptr<IComponent>) pCompObj);
		pDecTwo->operation(pDC);
	}
	//---------------
	//---Кнопки вперед и назад
	//--------
	//*************Кнопка "выход"*********
	else if(menuMode == "Menu Hide")
	{
		if(style == 0)
		{
			Component* pCompObj = new Component();
			DecoratorThree* pDecThree= new DecoratorThree((std::shared_ptr<IComponent>) pCompObj);
			pDecThree->operation(pDC);
		}
		else if(style == 1)
		{
			Component* pCompObj = new Component();
			DecoratorFive* pDecFive= new DecoratorFive((std::shared_ptr<IComponent>) pCompObj);
			pDecFive->operation(pDC);
		}
	}
	//*************************************
	//*************Выбор стиля"*********
	else if(menuMode == "Menu Style")
	{
		Component* pCompObj = new Component();
		DecoratorFour* pDecFour= new DecoratorFour((std::shared_ptr<IComponent>) pCompObj);
		pDecFour->operation(pDC);
	}
	//*

}

// рисование CPytnashkiShablonView

void CPytnashkiShablonView::OnDraw(CDC* pDC)
{
	CPytnashkiShablonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Мой код:
	
	//*****Menu******
	MenuFunction(pDC);
	//****End Menu*****
}



// печать CPytnashkiShablonView

BOOL CPytnashkiShablonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CPytnashkiShablonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CPytnashkiShablonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CPytnashkiShablonView

#ifdef _DEBUG
void CPytnashkiShablonView::AssertValid() const
{
	CView::AssertValid();
}

void CPytnashkiShablonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPytnashkiShablonDoc* CPytnashkiShablonView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPytnashkiShablonDoc)));
	return (CPytnashkiShablonDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CPytnashkiShablonView

void  CPytnashkiShablonView::ExitButtonClick()
{
	MessageBox("Good Bye My Friend!!");
	//this->GetAncestor(this)->CloseWindow();
}

void CPytnashkiShablonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CView::OnLButtonDown(nFlags, point);
	if(menuMode == "Menu Open")
	{
		if(point.x>1100 && point.x<1200 && point.y>100 && point.y<150 && !wasStartGame)
			MessageBox("Я хочу сыграть с тобой в одну игру!");
		else if(point.x>1100 && point.x<1200 && point.y>100 && point.y<150)
			menuMode = "Menu Hide";
		else if(point.x>1100 && point.x<1250 && point.y>200 && point.y<250)
		{
			menuMode = "Menu NG";
			moveCount = 0;
		}
		else if(point.x>1100 && point.x<1300 && point.y>300 && point.y<350)
		{
			menuMode = "Menu Style";
		}
		else if(point.x>1100 && point.x<1350 && point.y>400 && point.y<450)
			ExitButtonClick();
	}
	else if(menuMode == "Menu NG")
	{
		wasStartGame = true;
		if(point.x>200 && point.x<400 && point.y>100 && point.y<150)
		{
			menuMode = "Menu Hide";
			r=Reciever(2);
		}
		else if(point.x>200 && point.x<500 && point.y>200 && point.y<250)
		{
			menuMode = "Menu Hide";
			r=Reciever(3);
		}
		else if(point.x>200 && point.x<600 && point.y>300 && point.y<350)
		{
			menuMode = "Menu Hide";
			r=Reciever(4);
		}
		else if(point.x>200 && point.x<700 && point.y>400 && point.y<450)
		{
			menuMode = "Menu Hide";
			r=Reciever(5);
		}
		else if(point.x>200 && point.x<800 && point.y>500 && point.y<550)
		{
			menuMode = "Menu Hide";
			r=Reciever(6);
		}
	}
	else if(menuMode == "Menu Style")
	{
		if(point.x>200 && point.x<600 && point.y>100 && point.y<150)
		{
			menuMode = "Menu Open";
			style = 0;
		}
		else if(point.x>200 && point.x<700 && point.y>200 && point.y<250)
		{
			menuMode = "Menu Open";
			style = 1;
		}
	}
	else if(menuMode == "Menu Hide")
	{
		if(point.x>1200 && point.x<1300 && point.y>100 && point.y<150)
			menuMode = "Menu Open";
		for(int i=0; i<r.GetArrSize(); i++)
		{
			for(int j=0; j<r.GetArrSize(); j++)
			{
				if((point.x>110*j+10) && (point.x<110*j+110) && (point.y>110*i+10) && (point.y<110*i+110))
				{
					r.Move(i,j);
					moveCount++;
				}
			}
		}
	}
	Invalidate();
	if(wasStartGame && (r.Finish()) )
	{
		wasStartGame = false;
		CString s;
		s.Format("%i", moveCount);
		MessageBox("Вы победили!!\nКоличество ходов для победы: "+s);
		menuMode = "Menu Open";
	}

	if(menuMode == "Menu Hide" && point.x>1000 && point.x<1100 && point.y>200 && point.y<250)
		{
			if(!r.DoneCommands.size())
			  MessageBox("Nothing to undo!!!");
			else
				{
					r.Undo();Invalidate();
					moveCount++;
				}	
		}
		
	if(menuMode == "Menu Hide" &&  point.x>1200 && point.x<1300 && point.y>200 && point.y<250)
		{
			if(!r.UndoCommands.size())
				MessageBox("Nothing to redo!!!");
			else
				{
					r.Redo();Invalidate();
					moveCount++;
				}
		}
		
}
