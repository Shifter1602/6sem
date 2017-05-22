#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

class Field 
{
	int _size;
	int **_arr;
	public:
	Field(){}
	Field(int size);
	int GetSize(){return _size;};
	int ** GetArr(){return _arr;};
	void Shake();
	void Swap(int source_x,int source_y);
	void UnSwap();
	bool isSwappable(int source_x,int source_y);
	vector<int> FindZero();
	bool isFinished();
//////////////////////////////////////////////////////////////////////////
	vector<int> _seq;
	int SeqSize(){return _seq.size();}
//////////////////////////////////////////////////////////////////////////
};

Field::Field(int size)
	{
		_size=size;
		//////////////////////////////////////////////////////////////////////////
		int count = 1;
		_arr = new int *[_size];
		for(int i=0; i<_size; i++)
			{
			_arr[i] = new int[_size];
			}
		for(int i=0; i<_size; i++)
			for(int j=0; j<_size; j++)
				{
				_arr[i][j] = count++;
				}
			_arr[_size-1][_size-1] = 0;
	}

void Field::Shake()
	{
	int i;
	int j;
	for(int g=0; g<2; g++)
	{
		//*******************************************
		//������ ���� ������ � ������� �� �����
		
		if(g==0)
		{
			i = _size - 1;
			j = _size - 1;
		}
		else if(g==1)
		{
			//���� ������ ������� � ����� ������� ����
			while(1)
			{
				if(i!=0)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				if(j!=0)
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
				if((i==0) & (j==0))
					break;
			}
		}
		//************************************
		for(int k=0; k<pow((double)5, (double)_size); k++)
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
			if((i == 0) && (j == 0))//���� ���� ����
			{
				if(r>50)
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
				else
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
			}
			else if(i == 0 && j == _size-1)//���� ���� �����
			{
				if(r>50)
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
				else
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
			}
			else if(i == _size-1 && j == 0)//���� ���� ���
			{
				if(r>50)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				else
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
			}
			else if(i == _size-1 && j == _size-1)//���� ����� ���
			{
				if(r>50)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				else
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
			}
			//�������
			else if(i == 0)//������� ����
			{
				if(r>33)
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
				else if(r>66)
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
				else
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
			}
			else if(j == 0)//������� ����
			{
				if(r>33)
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
				else if(r>66)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				else
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
			}
			else if(i == _size-1)//������� ���
			{
				if(r>33)
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
				else if(r>66)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				else
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
			}
			else if(j == _size-1)//������� �����
			{
				if(r>33)
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
				else if(r>66)
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
				else
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
			}
			else//�����
			{
				if(r>25)
				{
					_arr[i][j] = _arr[i][j-1];
					_arr[i][j-1]=0;
					j--;
				}
				else if(r>50)
				{
					_arr[i][j] = _arr[i-1][j];
					_arr[i-1][j]=0;
					i--;
				}
				else if(r>75)
				{
					_arr[i][j] = _arr[i][j+1];
					_arr[i][j+1]=0;
					j++;
				}
				else
				{
					_arr[i][j] = _arr[i+1][j];
					_arr[i+1][j]=0;
					i++;
				}
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////
	vector<int> v = FindZero();
	}


void Field::Swap(int source_x,int source_y)
	{
	if(isSwappable(source_x,source_y))
		{
			vector<int> v = FindZero();
			_arr[v.front()][v.back()]=_arr[source_x][source_y];
			_arr[source_x][source_y]=0;
			_seq.push_back(v.front());_seq.push_back(v.back());
		}
	}


void Field::UnSwap()
	{
		int a=_seq[SeqSize()-2],b=_seq[SeqSize()-1];
		Swap(a,b);
		_seq.pop_back();_seq.pop_back();
		_seq.pop_back();_seq.pop_back();
	}

bool Field::isSwappable(int source_x,int source_y)
	{
		vector<int> v = FindZero();
		//***********************
		//****�������� �� ��������� ���� � ��������(�������) �������
		if(((v.front()+1==source_x) & (v.back()==source_y)) || ((v.front()-1==source_x) & (v.back()==source_y)) ||
			((v.back()-1 == source_y) & (v.front()==source_x)) || ((v.back()+1==source_y) & (v.front()==source_x)))
			{
			return true;
			}
		else
			{
			return false;
			}
			
	}

std::vector<int> Field::FindZero()
	{
		int g, l;
		for(int i=0; i<_size;i++)
			for(int j=0; j<_size; j++)
				if(_arr[i][j] == 0)
					{
					g=i;
					l=j;
					}
		vector<int> v;// v.resize(2);
		v.push_back(g);	v.push_back(l);
		return v;
	}

bool Field::isFinished()
	{
		if(_arr[_size-1][_size-1] == 0)
			{
			int val=1;
			for(int i=0; i<_size; i++)
				for(int j=0; j<_size;j++)
					{
					if(_arr[i][j]==0)
						{
						return true;
						}
					else if(_arr[i][j]!=val)
						return false;
					val++;
					}
			}
		else
			{
			return false;
			}
	}
