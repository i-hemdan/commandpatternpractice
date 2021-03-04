#include "CMD_TurnOn.h"


CMD_TurnOn::CMD_TurnOn(SmartObject* target)
{
    this->target = target;
    this->Undoable = true;
}

bool CMD_TurnOn::Execute()
{
    if (target->IsOn) {
        std::cout << target->name << " is already on" << std::endl;
        return false;
    }
    target->IsOn = true;
    std::cout << "Turned " << target->name << " on" << std::endl;
    return true;
}
bool CMD_TurnOn::Undo() {
    target->IsOn = false;
    std::cout << "Undid: Turned " << target->name << " on" << std::endl;
    return true;
}