#pragma once
#include "Vector.hpp"
#include "Bank.h"
#include "Polymorphic_Ptr.hpp"
#include "User.h"

class Bank;

class System
{
private:
	Vector<Bank> banks;
	Vector<Polymorphic_Ptr<User>> users;

public:
	Vector<Bank> getBanks()
	{
		return banks;
	}
	System() = default;
	void login()const;
	void signUp()const;
	void create_bank(const MyString& name);
};

