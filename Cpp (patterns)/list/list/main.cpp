#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

struct Node
{
	int d;
	Node *prev;
	Node *next;
};

Node* first (int d);
void add (Node **pend, int d);
Node* find (Node *const pbeg, int i,bool dir=true);
bool remove (Node **pbeg, Node **pend, int key);
Node* insert (Node ** pbeg, Node **pend, int key, int d, bool dir=true);
void add_sort(Node ** pbeg, Node ** pend, int d);
int count(Node **pbeg, Node **pend);
void show(Node *pbeg);
void node_swap(Node * const a, Node *const b);
Node* min_d(Node * const pbeg);
void choice_sort(Node * const pbeg);
void del_repeat(Node ** pbeg, Node ** pend);

int main()
{
	Node *pbeg = first(1);
	Node *pend = pbeg;
	for (int i=2; i<=10; i++)
		add (&pend, i);
	/*for (int j=0; j<=10; j+=2)
		add_sort(&pbeg,&pend,j);
	insert (pbeg, &pend, 2, 200);
	if (!remove (&pbeg, &pend, 5))
	cout << "Error!";  */

	show(pbeg);

	Node *pv = pbeg->next;
	int i=1;
	while (pv)  
	{
		insert(&pbeg,&pend,i,pow(2.0,i),false);
		pv=pv->next;
		i++;
	}
	insert(&pbeg,&pend,i,pow(2.0,i),false);


	//cout << min_d(pbeg)->d <<endl;
	show(pbeg);
	choice_sort(pbeg);
	show(pbeg);
	del_repeat(&pbeg,&pend);
	show(pbeg);
	_getch();
	return 0;
}


void node_swap(Node *a, Node *b)
	{
	int temp;
	temp=a->d;
	a->d=b->d;
	b->d=temp;
	}

Node *min_d(Node * const pbeg)
	{
	   Node *pv=pbeg,*pmin=new Node;
	   pmin->d=pv->d;
	   while(pv)
		   {
			if(pmin->d > pv->d)
				pmin=pv;
			pv=pv->next;
		   }
	   return pmin;
	}

void choice_sort(Node * const pbeg)
	{
	  Node *pv = pbeg,*a;
	  while(pv)
		  {
		  a=min_d(pv);
		  //cout <<"min = " << a->d << "\t"	<< "pv = " << pv->d << endl;
		  if(a->d != pv->d)
			  node_swap(pv,a);
		  pv=pv->next;
		  //show(pbeg);
		  }
	}

void show(Node *pbeg)
	{
	Node *pv = pbeg;
	while (pv)
		{
		cout << pv-> d << " ";
		pv = pv->next;
		}
	cout << endl;
	}

int count(Node **pbeg, Node **pend)
{
	Node *pv = new Node;
	pv=*pbeg;
	int num=0;
	while (pv)
	{
		pv=pv->next;
		num++;
	}
	return num;
}

Node *first (int d)
{
	Node *pv = new Node;
	pv -> d = d;
	pv -> next = 0;
	pv -> prev = 0;
	return pv;
}

void add (Node **pend, int d)
{
	Node *pv = new Node;
	pv -> d = d;
	pv -> next = 0;
	pv -> prev = *pend;
	(*pend) -> next = pv;
	(*pend) = pv;
}

Node* find (Node *const pstart, int i, bool dir)
	{
	Node *pv = pstart;
	while (pv)
		{
		if (pv -> d == i)
			break;
		dir ?  pv = pv -> next : pv = pv -> prev;
		}
	return pv;
	}

void del_repeat(Node ** pbeg, Node ** pend)
	{
	   Node *pv=(*pbeg)->next;
	   while(pv)
		   {
		   if ((pv->prev)->d == pv->d)
			   remove(pbeg,pend,pv->d);
		   pv=pv->next;
		   }

	}

bool remove (Node **pbeg, Node **pend, int key)
{
	if (Node *pkey = find (*pbeg, key))
	{
		if (pkey == *pbeg)
		{
			*pbeg = (*pbeg) -> next;
			(*pbeg) -> prev = 0;
		}
		else if (pkey == *pend)
		{
			*pend = (*pend) -> prev;
			(*pend) -> next = 0;
		}
		else
		{
			(pkey -> prev) -> next = (pkey -> next);
			(pkey -> next) -> prev = (pkey -> prev);
		}
		delete pkey;
		return true;
	}
	return false;
}

Node* insert (Node ** pbeg, Node **pend, int key, int d, bool dir)
{
	Node *pstart=new Node;
	dir ? pstart=*pbeg : pstart=*pend;
	if (Node *pkey = find(pstart, key,dir))
	{
		Node *pv = new Node;
		pv -> d = d;
		pv -> next = pkey -> next;
		pv -> prev = pkey;
		pkey -> next = pv;
		if (pkey != *pend)
			(pv -> next) -> prev = pv;
		else
			*pend = pv;
		return pv;
	}
	return 0;
}


void add_sort(Node ** pbeg, Node **pend, int d)
{
	Node *pv = new Node;
	pv -> d = d;
	Node *pt = *pbeg;
	while (pt)
	{
		if(d < pt -> d)
		{
			pv -> next = pt;
			if(pt == *pbeg)
		{
			pv -> prev = 0;
			*pbeg = pv;
		}
		else //Вставка внутрь списка
		{
			(pt -> prev) -> next = pv;
			pv -> prev = pt -> prev;
		}
		pt -> prev = pv;
		return;
		}
		pt = pt -> next;
	}
	pv -> next = 0;
	pv -> prev = *pend;
	(*pend) -> next = pv;
	*pend = pv;
}
