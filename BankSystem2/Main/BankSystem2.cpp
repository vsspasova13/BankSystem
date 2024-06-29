#include <iostream>
#include <fstream>
#include "../Client/Client.h"
#include "../Employee/Employee.h"
#include "../Bank/Bank.h"
#include "../System/System.h"
#include "../Commands/CommandExecutor.h"






int main()
{    
    System& s = System::getInstance();
    CommandFactory commandFactory;
    CommandExecutor invoker;

    while (true) 
    {
        std::cout << "Enter command: ";
        char commandLine[1024];
        std::cin >> commandLine;

        if (strcmp(commandLine,"exit")==0 && (s.getCurrClient()==nullptr && s.getCurrEmployee()==nullptr && s.getCurrTPEmployee()==nullptr))
        {
            break;
        }
        if (strcmp(commandLine, "login") == 0 && s.isSomeoneLogged())
        {
            std::cout << "Two users can't be logged at the same time!" << std::endl;
            continue;
        }
        Command* command = commandFactory.createCmd(commandLine);
        if (command) 
        {
            invoker.addCommand(command);
        }
        else 
        {
            std::cout << "Invalid command: " << commandLine << std::endl;
        }
        invoker.executeCommands();
        std::cout<<std::endl;
    }


}
