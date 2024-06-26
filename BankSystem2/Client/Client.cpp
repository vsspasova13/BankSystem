#include "Client.h"
#include "../System/System.h"

class System;

Client::Client()
{
	this->accounts.clear();
	this->checks.clear();
	this->mess.clear();
}

unsigned long Client::check_avl(const MyString& bankName, unsigned long accNumber) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].bank_name == bankName && accounts[i].acc_number == accNumber)
		{
			return accounts[i].balance;
		}
	}
	return 0;
}

void Client::open(const MyString& bankName)
{
	System& s = System::getInstance();
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (strcmp(s.getBanks()[i].getName().c_str(), bankName.c_str()) == 0)
		{
			s.getBanks()[i].giveTask(s.getBanks()[i].openTask(*this,bankName));
		}
	}
}

void Client::close(const MyString& bankName, unsigned long accNumber) const
{
	System& s = System::getInstance();
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == bankName)
		{
			s.getBanks()[i].giveTask(s.getBanks()[i].closeTask(*this,bankName,accNumber));
		}
	}
}

void Client::redeem(const MyString& bankName, unsigned long accNumber, const MyString& code)
{
	for (int i = 0; i < checks.getSize(); i++)
	{
		if (code == checks[i].code)
		{
			for (int j = 0; j < accounts.getSize(); j++)
			{
				if (accNumber == accounts[j].acc_number)
				{
					accounts[j].balance += checks[i].sum;
					checks.erase(i);
				}
			}
		}
	}
}

void Client::change(const MyString& newBankName, const MyString& currBankName, unsigned long accNumber)
{
	System& s = System::getInstance();
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == newBankName)
		{
			s.getBanks()[i].giveTask(s.getBanks()[i].changeTask(*this,newBankName,currBankName,accNumber));
		}
	}
}

void Client::list(const MyString& bankName) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].bank_name == bankName)
		{
			std::cout << accounts[i].bank_name.c_str() << " " << accounts[i].acc_number << " " << accounts[i].balance << std::endl;
		}
	}
}

void Client::messages() const
{
	for (int i = 0; i < mess.getSize(); i++)
	{
		std::cout << "[" << mess[i].id << "] " << mess[i].content.c_str() << std::endl;
	}
}

User* Client::clone() const
{
	return new Client(*this);
}

void Client::addAccount(const MyString& bankName, unsigned long accNumber)
{
	Account a(bankName, accNumber, 0);
	accounts.pushBack(a);
	System& s = System::getInstance();
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == bankName)
		{
			s.getBanks()[i].getClients().pushBack((*this));
			this->addMessage("You opened an account in " + bankName + "! Your account id is " + (a.acc_number + "") + ".");
			return;
		}
	}
}

void Client::removeAccount(const MyString& bankName, unsigned long accNumber)
{
	int ind = 0;
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].acc_number == accNumber && accounts[i].bank_name == bankName)
		{
			ind = i;
			break;
		}
	}
	accounts.erase(ind);
}

void Client::addMessage(const MyString& mes)
{
	Message m(this->mess.getSize() + 1, mes);
	this->mess.pushBack(m);
}

void Client::help() const
{
	std::cout << "1.check_avl [bank_name] [account_number]-Displays the balance of the account with number[account_number] in the bank with name[bank_name]" << std::endl;
	std::cout << "2.open[bank_name]-Sends a request to the bank to open a new account." << std::endl;
	std::cout << "3.close[bank_name][account_number]-Sends a request to the bank to close the account with number[account_number].If the data is invalid, an appropriate error message is shown." << std::endl;
	std::cout << "4.redeem[bank_name][account_number][verification_code]-Cashes a check received from a third party through the bank.The money from the check is transferred to the provided account if the code is validated.If such a check does not exist, an appropriate error message is shown." << std::endl;
	std::cout << "5.change[new_bank_name][current_bank_name][account_number]-Sends a request to the bank to move the provided account to another bank." << std::endl;
	std::cout << "6.list[bank_name]-Displays all accounts that the user owns in the bank." << std::endl;
	std::cout << "7.messages- Shows all messages in chronological order." << std::endl;
}

void Client::whoami() const
{
	std::cout << "You are " << this->getName() << std::endl;
}

