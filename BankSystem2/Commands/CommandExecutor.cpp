#include "CommandExecutor.h"

void CommandExecutor::addCommand(Command* cmd)
{
    
        commands.pushBack(cmd);
}

void CommandExecutor::executeCommands()
{
    
        for (size_t i = 0; i < commands.getSize(); ++i) {
            commands[i]->execute();
        }

        for (size_t i = 0; i < commands.getSize(); ++i) {
            delete commands[i];
        }
        commands.clear();
    
}
