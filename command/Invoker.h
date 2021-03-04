#pragma once
#include <stack>
#include "Command.h"

class Invoker
{
	std::stack<Command*> UndoStack;
public:
	void Invoke(Command* command);
	void Undo();
};

