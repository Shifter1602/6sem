#include "Field.h"
class Command
	{
	protected:
		Field * _field;
	public:
		virtual void Execute()=0;
		virtual void UnExecute()=0;
		void SetField(Field* field)
			{
			_field=field;
			}
	};

class MoveCommand : public Command
	{
	int _x,_y;
public:
	MoveCommand(int x,int y) : _x(x) , _y(y) {}
	void Execute()
		{
			_field->Swap(_x,_y);
		}
	void UnExecute()
		{
			_field->UnSwap();
		}

	};

class Reciever
	{
	vector<Command*> DoneCommands; 
	vector<Command*> UndoCommands; 
	Field field; 
	Command* command;
public:
	Reciever(int size);
	void Move(int x, int y)
			{
				command = new MoveCommand(x,y);
				command->SetField(&field);
				command->Execute();
				DoneCommands.push_back( command );
			}
	void Undo()
			{
			if( DoneCommands.size() == 0 )
				{
				cout << "There is nothing to undo!" << endl; 
				}
			else
				{
				command = DoneCommands.back(); 
				DoneCommands.pop_back();
				UndoCommands.push_back(command);
				command->UnExecute();
				}
			}
	void Redo()
			{
			if( UndoCommands.size() == 0 )
				{
				cout << "There is nothing to redo!" << endl; 
				}
			else
				{
				command = UndoCommands.back();
				DoneCommands.push_back(command); 
				UndoCommands.pop_back();
				command->Execute();
				}
			}
	void Show()     
			{
			field.Print(); 
			}
	void ShowSeq()     
			{
			field.GetSeq(); 
			}
	};								  

Reciever::Reciever(int size)
	{
		field = Field(size);
		field.Shake();
	}
