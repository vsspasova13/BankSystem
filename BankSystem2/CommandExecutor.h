#pragma once
#include "CommandFactory.h"
#include "Vector.hpp"

class CommandExecutor
{
private:
    Vector<Command*> commands;

public:
    void addCommand(Command* cmd) {
        commands.pushBack(cmd);
    }

    void executeCommands() {
        for (size_t i = 0; i < commands.getSize(); ++i) {
            commands[i]->execute();
        }
       
        for (size_t i = 0; i < commands.getSize(); ++i) {
            delete commands[i];
        }
        commands.clear();
    }
};

