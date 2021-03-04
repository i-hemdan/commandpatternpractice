#pragma once
#include <string>
#include "SmartObject.h"
class SmartLight : public SmartObject
{
public:
	SmartLight(std::string name) { this->name = name; }
};

