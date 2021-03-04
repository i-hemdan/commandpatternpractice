#pragma once
#include <string>
#include "SmartObject.h"

class SmartTv : public SmartObject
{
public:
	SmartTv(std::string name) { this->name = name; }
};

