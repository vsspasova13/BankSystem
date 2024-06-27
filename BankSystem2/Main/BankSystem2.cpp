#include <iostream>
#include <fstream>
#include "../Client/Client.h"
#include "../Employee/Employee.h"
#include "../Bank/Bank.h"
#include "../System/System.h"
#include "../Commands/CommandExecutor.h"

 const MyString& firstWord()
    {
        MyString word="";
        char ch;
        ch=std::cin.get();
        while (ch != ' ')
        {
            word += ch;
            ch=std::cin.get();
        }
        return word;

    }

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
