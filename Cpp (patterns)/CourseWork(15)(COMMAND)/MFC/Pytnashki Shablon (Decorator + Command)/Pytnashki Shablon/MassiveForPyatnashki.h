#include <string>
#include <cmath>
#include <math.h>
#include <random>
#include <ctime>

using namespace std;
/*
class Pole
{
public:
	int razmer;
	Pole(int razmer);
	~
*/

int ** CreateFullMassive(int razmer)
{
	int count = 1;
	int ** mas = new int*[razmer];
	for(int i=0; i<razmer; i++)
	{
		mas[i] = new int[razmer];
	}
	for(int i=0; i<razmer; i++)
		for(int j=0; j<razmer; j++)
		{
			mas[i][j] = count++;
		}
	mas[razmer-1][razmer-1] = 0;
	return mas;
}

int ** PeremeshatMassive(int ** massive, int razmer)
{
	int i;
	int j;
	for(int g=0; g<2; g++)
	{
		//*******************************************
		//������ ���� ������ � ������� �� �����
		
		if(g==0)
		{
			i = razmer - 1;
			j = razmer - 1;
		}
		else if(g==1)
		{
			//���� ������ ������� � ����� ������� ����
			while(1)
			{
				if(i!=0)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				if(j!=0)
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
				if(i==0 & j==0)
					break;
			}
		}
		//************************************
		for(int k=0; k<pow((double)5, (double)razmer); k++)
		{
			//*********************************************
			//���������� ���������� ����� r � ������ ��������� ������� � �������� �������� 1-100
			int r = rand() % 100 +1;
			time_t myTimer;
			myTimer = time(NULL);
			myTimer-=1494850400;
			r+=myTimer*10;
			while(r>100)
				r-=100;
			//*********************************************
			//�������� �� ���������
			if(i == 0 && j == 0)//���� ���� ����
			{
				if(r>50)
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
				else
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
			}
			else if(i == 0 && j == razmer-1)//���� ���� �����
			{
				if(r>50)
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
				else
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
			}
			else if(i == razmer-1 && j == 0)//���� ���� ���
			{
				if(r>50)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				else
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
			}
			else if(i == razmer-1 && j == razmer-1)//���� ����� ���
			{
				if(r>50)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				else
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
			}
			//�������
			else if(i == 0)//������� ����
			{
				if(r>33)
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
				else if(r>66)
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
				else
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
			}
			else if(j == 0)//������� ����
			{
				if(r>33)
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
				else if(r>66)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				else
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
			}
			else if(i == razmer-1)//������� ���
			{
				if(r>33)
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
				else if(r>66)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				else
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
			}
			else if(j == razmer-1)//������� �����
			{
				if(r>33)
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
				else if(r>66)
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
				else
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
			}
			else//�����
			{
				if(r>25)
				{
					massive[i][j] = massive[i][j-1];
					massive[i][j-1]=0;
					j--;
				}
				else if(r>50)
				{
					massive[i][j] = massive[i-1][j];
					massive[i-1][j]=0;
					i--;
				}
				else if(r>75)
				{
					massive[i][j] = massive[i][j+1];
					massive[i][j+1]=0;
					j++;
				}
				else
				{
					massive[i][j] = massive[i+1][j];
					massive[i+1][j]=0;
					i++;
				}
			}
		}
	}
	return massive;
}

void DeleteMassive(int ** massive, int razmer)
{
	for(int i=0; i<razmer; i++)
		delete []massive[i];
}

bool SwapQuadro(int ** massive, int razmer, int x, int y)
{
	//****����� ������ ������******
	int g, l;
	for(int i=0; i<razmer;i++)
		for(int j=0; j<razmer; j++)
			if(massive[i][j] == 0)
			{
				g=i;
				l=j;
			}
	//***********************
	//****�������� �� ��������� ���� � ��������(�������) �������
	if((g+1==x & l==y) || (g-1==x & l==y) ||
		(l-1 == y & g==x) || (l+1==y & g==x))
		return true;
	else
		return false;
	//***********************
}

bool Win_niPuh(int ** massive, int razmer)
{
	if(massive[razmer-1][razmer-1] == 0)
	{
		int val=1;
		for(int i=0; i<razmer; i++)
			for(int j=0; j<razmer;j++)
			{
				if(massive[i][j]==0)
				{
					return true;
				}
				else if(massive[i][j]!=val)
					return false;
				val++;
			}
	}
	else
	{
		return false;
	}
}
