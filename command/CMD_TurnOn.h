#pragma once
#include "Command.h"
class CMD_TurnOn: public Command {
public:
	CMD_TurnOn(SmartObject* target);
	
	virtual bool Execute() override;
	virtual bool Undo() override;
};