#include "Command.h"
int main()
	{
	Reciever r = Reciever(4);
	char s = '1';
	int a,b;
	//////////////////////////////////////////////////////////////////////////
	cout << "-------------------------------------------------------------"<<endl;
	cout << "1. Move\n2. Seq\n 3. Print\n4. Unmove\n5. Redo Move" << endl;
	cout << "-------------------------------------------------------------"<<endl<<endl;
	//////////////////////////////////////////////////////////////////////////
	while(s != 'e')
		{
			cin >> s;
			switch(s)
				{
					case '1':
						r.Show();
						cout << "Type Coord: ";
						cin >> a >> b;
						cout << endl;
						r.Move(a-1,b-1);
						break;
					case '2':
						r.ShowSeq();
						break;
					case '3':
						r.Show();
						break;
					case '4':
						r.Undo();
						r.Show();
						break;
					case '5':
						r.Redo();
						r.Show();
						break;
				}
			
		}
	return 0;
	}
