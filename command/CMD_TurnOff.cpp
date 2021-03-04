#include "CMD_TurnOff.h"
CMD_TurnOff::CMD_TurnOff(SmartObject* target)
{
    this->target = target;
    this->Undoable = true;
}

bool CMD_TurnOff::Execute()
{
    if (!target->IsOn) {
        std::cout << target->name << " is already off" << std::endl;
        return false;
    }
    target->IsOn = false;
    std::cout << "Turned " << target->name << " off" << std::endl;
    return true;
}
bool CMD_TurnOff::Undo() {
    target->IsOn = true;
    std::cout << "Undid: Turned " << target->name << " off" << std::endl;
    return true;
}