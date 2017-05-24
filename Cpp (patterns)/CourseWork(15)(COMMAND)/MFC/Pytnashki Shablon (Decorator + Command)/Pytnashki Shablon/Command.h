#include "Field.h"
class Command
	{
	protected:
		Field * _field;
	public:
		virtual void Execute()=0;
		virtual void UnExecute()=0;
		void SetField(Field* field){_field=field;}
	};

class MoveCommand : public Command
	{
	int _x,_y;
public:
	MoveCommand(int x,int y) : _x(x) , _y(y) {}
	void Execute(){_field->Swap(_x,_y);}
	void UnExecute(){_field->UnSwap();}
	};

class Reciever
	{
	public:
	vector<Command*> DoneCommands; 
	vector<Command*> UndoCommands; 
	Field field; 
	Command* command;
	Reciever(){}
	Reciever(int size);
	int ** GetArr(){return field.GetArr();};
	int GetArrSize(){return field.GetSize();};
	void Move(int x, int y)
			{
				command = new MoveCommand(x,y);
				command->SetField(&field);
				command->Execute();
				DoneCommands.push_back( command );
			}
	bool Undo()
			{
			if( DoneCommands.size() == 0 )
				{
				return false;
				}
			else
				{
				command = DoneCommands.back(); 
				DoneCommands.pop_back();
				UndoCommands.push_back(command);
				command->UnExecute();
				return true;
				}
			}
	bool Redo()
			{
			if( UndoCommands.size() == 0 )
				{
				return false;
				}
			else
				{
				command = UndoCommands.back();
				DoneCommands.push_back(command); 
				UndoCommands.pop_back();
				command->Execute();
				return true;
				}
			}
	bool Finish()
		{
			if(field.isFinished())
				{
				return true;
				}
			return false;
		}
	};								  

Reciever::Reciever(int size)
	{
		field = Field(size);
		field.Shake();
	}
