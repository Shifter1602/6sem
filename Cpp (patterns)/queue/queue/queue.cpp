#include <iostream>
#include <conio.h>
using namespace std;
struct Node
	{
	int d;
	Node* p;
	};
Node* first(int d);
void add(Node** pend, int d);
int del(Node** pbeg);

int main()
	{
	Node* pbeg=first(1);
	Node* pend = pbeg;
	for(int i=2;i<=5;i++) add(&pend,i);
	while(pbeg) cout << del(&pbeg) << " ";
	_getch();
	return 0;
	}

Node* first(int d)
	{
	Node* pv =new Node;
	pv->d=d;
	pv->p=0;
	return pv;
	}

void add(Node** pend, int d)
	{
	Node* pv =new Node;
	pv->d=d;
	pv->p=0;
	(*pend)->p=pv;
	*pend=pv;
	}

int del(Node** pbeg)
	{
	int temp= (*pbeg)->d;
	Node* pv=*pbeg;
	*pbeg=(*pbeg)->p;
	delete pv;
	return temp;
	}