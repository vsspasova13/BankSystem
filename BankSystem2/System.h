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
	System() {}
	
public:
	
	System(const System&) = delete;
	void operator=(const System&) = delete;
	static System& getInstance() 
	{
		static System instance;
		return instance;
	}
	Vector<Bank> getBanks()
	{
		return banks;
	}
	Vector<Polymorphic_Ptr<User>> getUsers()
	{
		return users;
	}
	
	void login(const MyString& name, const MyString& password);
	void signUp(const MyString& name, long egn, int age,const MyString& userType, const MyString& bankName, const MyString& password);
	void create_bank(const MyString& name);
	void writeInFile(const MyString& fileName, const User& u)const;
	void writeInFileEmployees(const MyString& fileName, const Employee& e)const;

};

