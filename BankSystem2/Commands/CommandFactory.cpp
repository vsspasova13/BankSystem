#include "CommandFactory.h"

Command* CommandFactory::createCmd(const MyString& text) const
{
	//system:
	if (text == "login")
	{
		char name[1024];
		char passw[1024];
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << std::endl;
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
		return new OpenCmd(bank);
	}

	else if (text == "change")
	{
		char newBank[1024];
		char currBank[1024];
		long accNum;
		std::cin >> newBank >> currBank >> accNum;
		return new ChangeCmd(newBank, currBank, accNum);
	}
	else if (text == "close")
	{
		char bank[1024];
		long accNum;
		std::cin >> bank >> accNum;
		return new CloseCmd(bank, accNum);
	}
	else if (text == "messages")
	{
		return new MessagesCmd();
	}
	else if (text == "list")
	{
		char bank[1024];
		std::cin >> bank;
		return new ListCmd(bank);
	}
	else if (text == "redeem")
	{
		char bank[1024];
		long accNum;
		char code[1024];
		std::cin >> bank >> accNum >> code;
		return new RedeemCmd(bank, accNum, code);
	}

	//employee::
	else if (text == "tasks")
	{
		return new TasksCmd();
	}
	else if (text == "approve")
	{
		int id;
		std::cin >> id;
		return new ApproveCmd(id);
	}
	else if (text == "disapprove")
	{
		int id; char message[1024];
		std::cin >> id >> message;
		return new DisapproveCmd(id, message);
	}
	else if (text == "view")
	{
		int id;
		std::cin >> id;
		return new ViewCmd(id);
	}
	else if (text == "validate")
	{
		int id;
		std::cin >> id;
		return new ValidateCmd(id);
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
