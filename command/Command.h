#pragma once
#include "SmartObject.h"
#include <iostream>
using namespace std;
class Command
{
public:
	bool Undoable;
	SmartObject* target;
	virtual bool Execute() = 0;
	virtual bool Undo() = 0;
};

