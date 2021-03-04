#include <iostream>
#include "Invoker.h"

void Invoker::Invoke(Command* command) {
	if (command->Execute() && command->Undoable) UndoStack.push(command);
}

void Invoker::Undo() {
	if (UndoStack.size() > 0) {
		UndoStack.top()->Undo();
		UndoStack.pop();
	}
	else {
		std::cout << "nothing to undo" << endl;
	}
}