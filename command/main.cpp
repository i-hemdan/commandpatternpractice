// command.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include "SmartObject.h"
#include "SmartTv.h"
#include "SmartLight.h"
#include "Input.h"

using namespace std;

string split(string str, string spliton);

int main()
{
    map<string, SmartObject*> NameObjectMap = {
        {"tv1",new SmartTv("tv1")},
        {"tv2",new SmartTv("tv2")},
        {"light1",new SmartLight("light1")},
        {"light2",new SmartLight("light2")},
        {"light3",new SmartLight("light3")},
        {"light4",new SmartLight("light4")}
    };

    Input().run(NameObjectMap);
}