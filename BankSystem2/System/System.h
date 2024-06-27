#pragma once
#include "..\Utils\Vector.hpp"
#include "..\Bank\Bank.h"
#include "..\Utils\Polymorphic_Ptr.hpp"
//#include "..\User\User.h"
#include "..\User\UserFactory.h"
#include <fstream>

class Bank;

class System
{
private:

	Vector<Client*> clients;
	Vector<Employee*> employees;
	Vector<ThirdPartyEmployee*> ThirdPEmp;
	Vector<Bank> banks;
	Vector<Polymorphic_Ptr<User>> users;
	System() {}
	Client* currClient = nullptr;
	Employee* currEmp = nullptr;
	ThirdPartyEmployee* currThirdPartyEmp = nullptr;
public:
	
	System(const System&) = delete;
	void operator=(const System&) = delete;

	static System& getInstance() 
	{
		static System instance;
		return instance;
	}
	Vector<Bank> getBanks()const
	{
		return banks;
	}
	Vector<Polymorphic_Ptr<User>> getUsers()const
	{
		return users;
	}
	
	Bank& findBankByName(const MyString& name)const
	{
		for (size_t i = 0; i < banks.getSize(); i++)
		{
			if (strcmp(this->getBanks()[i].getName().c_str(), name.c_str()) == 0)
			{
				return this->getBanks()[i];
			}
		}
	}
	int findBankIndByName(const MyString& name)const
	{
		for (size_t i = 0; i < banks.getSize(); i++)
		{
			if (strcmp(this->getBanks()[i].getName().c_str(), name.c_str()) == 0)
			{
				return i;
			}
		}
	}

	Client* getCurrClient()const
	{
		return currClient;
	}
	Employee* getCurrEmployee()const
	{
		return currEmp;
	}
	ThirdPartyEmployee* getCurrTPEmployee()const
	{
		return currThirdPartyEmp;
	}
	void exitCmd();

	bool isSomeoneLogged()const;

	void login(const MyString& name, const MyString& password);
	void signUp(const MyString& name, long egn, int age,const MyString& userType, const MyString& bankName, const MyString& password);
	void create_bank(const MyString& name);
	void writeInFile(const MyString& fileName, const User& u)const;
	bool ValidateUser(const MyString& name, const MyString& pass, const MyString& role, int& index);
	MyString getUserType(const MyString& name, const MyString& password) const;
};


