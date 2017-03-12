#include <iostream>
#include <conio.h>
using namespace std;

enum sex{male,female};
enum edu{start,middle,high};
enum ans{no,yes};
struct Form
	{
	int age;
	sex s;
	edu e;
	ans *a;
	Form* prev;
	Form* next;
	};

Form* create_list(int age, sex s, edu e, ans *a);
void add(Form **pend,int age, sex s, edu e, ans *a);
void show(Form *pbeg);
char* get_sex(sex s);
char* get_edu(edu e);
char* get_ans(ans a);

int main()
	{
	ans a1[] = {yes,no,yes,no};
	ans a2[] = {no,yes,yes,no};
	Form *pbeg = create_list(12,male,start,a1);
	Form *pend = pbeg;
	add(&pend,13,female,start,a2);
	add(&pend,22,female,high,a1);
	show(pbeg);
	_getch();
	return 0;
	}

Form* create_list(int age, sex s, edu e, ans *a)
	{
	Form* pv=new Form;
	pv->age=age;
	pv->s=s;
	pv->e=e;
	pv->a=a;
	pv->next=0;
	pv->prev=0;
	return pv;
	}

void add(Form **pend,int age, sex s, edu e, ans *a)
	{
	Form *pv = new Form;
	pv -> age = age;
	pv->s=s;
	pv->e=e;
	pv->a=a;
	pv -> next = 0;
	pv -> prev = *pend;
	(*pend) -> next = pv;
	(*pend) = pv;
	}

void show(Form *pbeg)
	{
	Form *pv = pbeg;
	while (pv)
		{
		cout << "Age: "<< pv-> age << " ";
		cout << "Sex: "<< get_sex(pv->s) << " ";
		cout << "Education: "<< get_edu(pv->e) << endl;
		for(int i=0;i<4;i++) cout  << " " << get_ans(pv->a[i]) << endl;
		pv = pv->next;
		cout << endl;
		}
	cout << endl;
	}

char* get_sex(sex s)
	{
	char* str = new char[];
	s ?  strcpy(str,"male") : strcpy(str,"female");
	return str;
	}

char* get_edu(edu e)
	{
	char* str = new char[];
	(!e) ?  strcpy(str,"start") : ((e==1) ?  strcpy(str,"middle") : strcpy(str,"high"));
	return str;
	}

char* get_ans(ans a)
	{
	char* str = new char[];
	a ?  strcpy(str,"yes") : strcpy(str,"no");
	return str;
	}




