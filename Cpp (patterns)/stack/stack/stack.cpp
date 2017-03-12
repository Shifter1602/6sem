#include <iostream>
#include <conio.h>
using namespace std;
struct Node
	{
	int d;
	Node* p;
	};
Node* first(int d);
void push(Node** top,int d);
int pop(Node** top);

int main()
	{
	Node* top=first(1);
	for(int i=2;i<=5;i++) push(&top,i);
	while(top) cout << pop(&top) << " ";
	_getch();
	return 0;
	}

Node* first(int d)
	{
	Node* pv = new Node;
	pv->d=d;
	pv->p=0;
	return pv;
	}

void push(Node** top,int d)
	{
		Node* pv = new Node;
		pv->d=d;
		pv->p=*top;
		*top=pv;
	}

int pop(Node** top)
	{
	int temp = (*top)->d;
	Node* pv = *top;
	*top=(*top)->p;
	delete pv;
	return temp;
	}
