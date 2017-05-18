#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

class Field 
{
public:
	int _size;
	int **_arr;
	Field(){}
	Field(int size);
	void Shake();
	void Print();
	void Swap(int source_x,int source_y);
	void UnSwap();
	bool isSwappable(int source_x,int source_y);
	vector<int> FindZero();
//////////////////////////////////////////////////////////////////////////
	deque<int> _seq;
	int SeqSize(){return _seq.size();}
	void GetSeq();
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
		//Четыре раза начать с каждого из углов
		
		if(g==0)
		{
			i = _size - 1;
			j = _size - 1;
		}
		else if(g==1)
		{
			//Гоню пустой квадрат в левый верхний угол
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
			//Вычисление рандомного числа r с учетом реального времени в секундах диапазон 1-100
			int r = rand() % 100 +1;
			time_t myTimer;
			myTimer = time(NULL);
			myTimer-=1494850400;
			r+=myTimer*10;
			while(r>100)
				r-=100;
			//*********************************************
			//Проверки на нахожение
			if((i == 0) && (j == 0))//угол лево верх
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
			else if(i == 0 && j == _size-1)//угол верх право
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
			else if(i == _size-1 && j == 0)//угол лево низ
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
			else if(i == _size-1 && j == _size-1)//угол право низ
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
			//стороны
			else if(i == 0)//сторона лево
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
			else if(j == 0)//сторона верх
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
			else if(i == _size-1)//сторона низ
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
			else if(j == _size-1)//сторона право
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
			else//центр
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
	//_seq.push_back(v.front());_seq.push_back(v.back());
	//return _arr;
	}

void Field::Print()
	{
	for (int i=0;i<_size;i++)
		{
		for (int j=0;j<_size;j++)
			cout << _arr[i][j] << "  ";
		cout << endl;
		}
	}

void Field::Swap(int source_x,int source_y)
	{
	if(isSwappable(source_x,source_y))
		{
			vector<int> v = FindZero();
			//cout << "---ZERO: " << v.front() <<" " << v.back() << " ---" << endl;
			_arr[v.front()][v.back()]=_arr[source_x][source_y];
			_arr[source_x][source_y]=0;
			//////////////////////////////////////////////////////////////////////////
			//_seq.push_back(source_x);_seq.push_back(source_y);
			_seq.push_back(v.front());_seq.push_back(v.back());
		}
	}


void Field::UnSwap()
	{
		int a=_seq[SeqSize()-2],b=_seq[SeqSize()-1];
		cout << "---UNDO--COORDS-- " << endl;
		cout << a <<" "  << b <<endl;
		Swap(a,b);
		_seq.pop_back();_seq.pop_back();
		_seq.pop_back();_seq.pop_back();
		GetSeq();
	}

bool Field::isSwappable(int source_x,int source_y)
	{
		vector<int> v = FindZero();
		//***********************
		//****Проверка на соседство нуля с найденой(нажатой) ячейкой
		if(((v.front()+1==source_x) & (v.back()==source_y)) || ((v.front()-1==source_x) & (v.back()==source_y)) ||
			((v.back()-1 == source_y) & (v.front()==source_x)) || ((v.back()+1==source_y) & (v.front()==source_x)))
			{
			return true;
			}
		else
			{
			cout << "Illegal Move" << endl;
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

void Field::GetSeq()
	{
		cout << "---SEQ---" << endl;
		for(int i=0;i<_seq.size();i+=2)
			cout << "(" <<	_seq[i] + 1 << "," << _seq[i+1] + 1 << ") ";
		cout << endl << "---SEQ---" << endl;
	}
