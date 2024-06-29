#include "CommandFactory.h"

Command* CommandFactory::createCmd(const MyString& text) const
{
	System& s = System::getInstance();
	Employee* e = s.getCurrEmployee();
	//system:
	if (text == "login")
	{
		char name[1024];
		char passw[1024];
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "Password: ";
		std::cin >> passw;

		return new LoginCmd(name, passw);
	}

	else if (text == "signup")
	{
		char name[1024];
		char passw[1024];
		long egn;
		int age;
		char role[1024];
		char bank[1024] = "";
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "EGN: ";
		std::cin >> egn;
		std::cout << "Age: ";
		std::cin >> age;
		std::cout << "Role: ";
		std::cin >> role;
		if (strcmp(role ,"Employee")==0)
		{
			std::cout << "Bank associated: ";
			std::cin >> bank;
		}
		std::cout << "Password: ";
		std::cin >> passw;

		return new SignUpCmd(name, egn, age, role, bank, passw);
	}
	else if (text == "create_bank")
	{
		char bank[1024];
		std::cin >> bank;
		return new CreateBankCmd(bank);
	}

	//client:
	else if (text == "open")
	{
		
		char bank[1024];
		std::cin >> bank;
		return new OpenCmd(s.getCurrClient(), bank);
	}

	else if (text == "change")
	{
		char newBank[1024];
		char currBank[1024];
		long accNum;
		std::cin >> newBank >> currBank >> accNum;
		return new ChangeCmd(s.getCurrClient(),newBank, currBank, accNum);
	}
	else if (text == "close")
	{
		char bank[1024];
		long accNum;
		std::cin >> bank >> accNum;
		return new CloseCmd(s.getCurrClient(),bank, accNum);
	}
	else if (text == "check_avl")
	{
		char bank[1024];
		long accNum;
		std::cin >> bank >> accNum;
		return new CheckAvlCmd(s.getCurrClient(), bank, accNum);
	}
	else if (text == "messages")
	{
		return new MessagesCmd(s.getCurrClient());
	}
	else if (text == "list")
	{
		char bank[1024];
		std::cin >> bank;
		return new ListCmd(s.getCurrClient(),bank);
	}
	else if (text == "redeem")
	{
		char bank[1024];
		long accNum;
		char code[1024];
		std::cin >> bank >> accNum >> code;
		return new RedeemCmd(s.getCurrClient(),bank, accNum, code);
	}

	//employee::
	
	else if (text == "tasks")
	{
		return new TasksCmd(e);
	}
	else if (text == "approve")
	{
		int id;
		std::cin >> id;
		return new ApproveCmd(e,id);
	}
	else if (text == "disapprove")
	{
		int id; char message[1024];
		std::cin >> id;
		std::cin.ignore();
		std::cin.getline(message,1024);
		return new DisapproveCmd(e,id, message);
	}
	else if (text == "view")
	{
		int id;
		std::cin >> id;
		return new ViewCmd(e,id);
	}
	else if (text == "validate")
	{
		int id;
		std::cin >> id;
		return new ValidateCmd(e,id);
	}

	//thirdParty
	else if (text == "send_check")
	{
		int sum;
		char code[1024];
		long egn;
		std::cin >> sum >> code >> egn;
		return new SednCheckCmd(sum, code, egn);
	}


	//user:
	else if (text == "exit")
	{
		return new ExitCmd();
	}
	else if (text == "whoami")
	{
		//return new WhoAmICmd();
	}
	else if (text == "help")
	{
		//return new HelpCmd();
	}
}
