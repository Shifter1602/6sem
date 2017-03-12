#include <iostream>
#include <conio.h>
using namespace std;

struct Node
	{
	int d;
	Node *left;
	Node *right;
	};
Node *first(int d);
Node *searchInsert(Node *root, int d);
void print_tree(Node *root, int i);
// _-
int main(){
	/*int b[] = {10, 25, 20, 6, 21, 8, 1, 30};
	Node *root = first(b[0]);
	for (int i = 1; i<8; i++)	
		searchInsert(root, b[i]);*/
	Node *root=first(20);
	for (int i = 1; i<=40; i+=3)	
		searchInsert(root,i);
	for (int i = 2; i<=40; i+=4)	
		searchInsert(root,i);
	print_tree(root, 3);
	_getch();
	return 0;
	}
//
// ������������ ������� �������� ������
Node * first(int d)
	{
	Node *pv = new Node;
	pv->d = d;
	pv->left=0;
	pv->right=0;
	return pv;
	}
// II
// ����� � ����������

Node *searchInsert(Node *root, int d)
	{
	Node *pv = root, *prev;
	bool found = false;
	while (pv && !found)
		{
		prev = pv;
		if (d == pv->d) found = true;
		else if (d < pv->d) pv=pv->left;
		else pv	= pv->right;
		}

	if (found) return pv;
	// �������� ������ ����:
	Node *pnew = new Node;
	pnew->d = d;
	pnew->left = 0;
	pnew->right = 0;
	if (d < prev->d)// ������������� � ������ ��������� ������:
		prev->left = pnew;
	else// ������������� � ������� ��������� ������:
		prev->right = pnew;
	return pnew;
	}
// ----
// ����� ������ 
void print_tree(Node *p, int level)
	{
	if(p){
		print_tree(p->right, level -1); // ����� ������ ���������
		//for (int i = 0; i<level; i++)cout << "\t";
		cout << p->d << endl; // ����� ����� ���������
		print_tree(p->left, level -1); // ����� ������� ���������
		} 
	}