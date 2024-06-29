#pragma once
#include "CommandFactory.h"
#include "../Utils/Vector.hpp"

class CommandExecutor
{
private:
    Vector<Command*> commands;

public:
    void addCommand(Command* cmd);

    void executeCommands();
};

