#include <iostream>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Bank.h"
#include "System.h"
#include "CommandExecutor.h"

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
    MyString clName = "vili";
    MyString clRole = "Client";
    MyString pass = "vili02";
    long egn = 990009;
    int age = 18; 
    MyString eName = "Petq";
    MyString eRole = "Employee";
    MyString epass = "petya05";
    long egne = 880008;
    int eage = 19;
    MyString bank = "OBB";

    System& s = System::getInstance();
   /* s.create_bank(bank);
    s.signUp(clName, egn, age, clRole, "", pass);
    s.signUp(eName, egne, eage, eRole, bank, epass);*/



    CommandFactory commandFactory;
    CommandExecutor invoker;

   
   
    while (true) 
    {
        std::cout << "Enter command: ";
        char commandLine[1024];
        std::cin >> commandLine;
      
        if (strcmp(commandLine,"exit")==0)
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
    }


}
