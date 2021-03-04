#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "SmartObject.h"
#include "Command.h"
#include "CMD_TurnOn.h"
#include "CMD_TurnOn.h"
#include "CMD_TurnOff.h"
#include "Invoker.h"

using namespace std;

class Input
{
public:
	string InputText = "";
	Invoker invoker;

	void run(map<string, SmartObject*> &NameObjectMap) {
		cout << "commands: turnon <objectname>, turnoff <objectname>, undo, status, quit" << endl;
		cout << "Objects in room:" << endl;
		status(NameObjectMap);
		while (1) {

			getline(cin, InputText);
			if (InputText == "quit") {
				cout << "Quitting.." << endl;
				return;
			}
			else if (InputText.find("turnon") != string::npos) {
				string arg = splitArg(InputText);
				if (NameObjectMap.find(arg) != NameObjectMap.end()) {
					invoker.Invoke(new CMD_TurnOn(NameObjectMap[arg]));
				}
			}
			else if (InputText.find("turnoff") != string::npos) {
				string arg = splitArg(InputText);
				if (NameObjectMap.find(arg) != NameObjectMap.end()) {
					invoker.Invoke(new CMD_TurnOff(NameObjectMap[arg]));
				}
			}
			else if (InputText == "status") {
				status(NameObjectMap);
			}
			else if (InputText == "undo") {
				invoker.Undo();
			}
			InputText = "";
		}
	}

	string splitArg(string str) {
		size_t pos = str.find(" ");
		if (pos != string::npos) {
			return str.substr(pos + 1);
		}
		return "";
	}

	void status(map<string, SmartObject*> &NameObjectMap) {
		for (const auto& pair : NameObjectMap) {
			auto p = pair.second;
			cout << p->name << (p->IsOn ? " Is On" : " Is Off") << endl;
		}
	}
};

