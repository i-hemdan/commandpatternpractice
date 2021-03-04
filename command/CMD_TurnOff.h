#pragma once
#include "Command.h"
class CMD_TurnOff: public Command
{
public:
	CMD_TurnOff(SmartObject* target);

	virtual bool Execute() override;
	virtual bool Undo() override;
};

