#include "Client.h"
#include "System.h"

unsigned long Client::check_avl(const MyString& bankName, unsigned long accNumber) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].bank_name == bankName && accounts[i].acc_number == accNumber)
		{
			return accounts[i].balance;
		}
	}
	return 0;//ex
}

void Client::open(const MyString& bankName)
{
	System s; 
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == bankName)
		{
			 s.getBanks()[i].giveTask(s.getBanks()[i].openTask(*this));
		}
	}
	
}

void Client::close(const MyString& bankName, unsigned long accNumber) const
{
	System s;
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == bankName)
		{
			s.getBanks()[i].giveTask(s.getBanks()[i].closeTask(*this));
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
				}
			}
		}
	}
}

void Client::change(const MyString& newBankName, const MyString& currBankName, unsigned long accNumber)
{
	System s;
	for (size_t i = 0; i < s.getBanks().getSize(); i++)
	{
		if (s.getBanks()[i].getName() == currBankName)
		{
			s.getBanks()[i].giveTask(s.getBanks()[i].openTask(*this));

		}
	}

}

void Client::list(const MyString& bankName) const
{
}

void Client::messages() const
{
}

void Client::addAccount(const MyString& bankName, unsigned long accNumber)
{
	Account a(bankName, accNumber, 0);
	accounts.pushBack(a);
}

void Client::removeAccount(const MyString& bankName, unsigned long accNumber)
{
	int ind = 0;
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].acc_number == accNumber && accounts[i].bank_name==bankName) 
		{ ind = i; 
		  break; }
	}
	accounts.erase(ind);
}
