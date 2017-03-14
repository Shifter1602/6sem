#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

enum sex{female,male};
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
int count(Form *pbeg,int age,sex s,edu e,ans *a);
void get_questions(int num);

int main()
	{	
	ans y[]={yes}, n[]={no};
	Form *pbeg = create_list(12,male,start,y);
	Form *pend = pbeg;
	get_questions(10);
	add(&pend,13,female,start,y);
	add(&pend,22,male,high,y);
	add(&pend,24,male,high,y);
	show(pbeg);
	cout << count(pbeg,25,male,high,y) << endl;
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
	(pv -> s) = s;
	(pv -> e) = e;
	(pv -> a) = a;
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
		int i=0;
		cout << "Age: "<< pv-> age << " ";
		cout << "Sex: "<< get_sex(pv->s) << " ";
		cout << "Education: "<< get_edu(pv->e) << endl;
		while((pv->a[i]==1) || (pv->a[i]==0))
		{
			cout  << " " << get_ans(pv->a[i]) << endl;
			i++;
		}
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
int count(Form *pbeg,int age,sex s,edu e,ans *a)
	{
	int num=0;
	Form *pv = pbeg;
	while(pv)
		{
			if( ((pv->age) < age) && (pv->s==s) && (pv->e==e) && (pv->a==a))
				num++;
			pv = pv->next;
		}
	cout << "Found [Age < " << age <<"; Sex " << get_sex(s) << "; Education " << get_edu(e) << "; Answers  " << get_ans(*a) << "]"<< endl;
	return num;
	}

void get_questions(int num)
	{
		char* buff=new char[num];
		ifstream data;
		data.open("questions.txt");
		while(!data.eof())
			{
			data.getline(buff,num);
			cout << buff << endl;
			}
		data.close();
	}