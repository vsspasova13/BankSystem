#pragma once
#include "../Utils/MyString.h"
#include "../Utils/Vector.hpp"
#include "../Utils/Polymorphic_Ptr.hpp"


enum class UserType
{
	CLIENT,
	EMPLOYEE,
	THIRD_PARTY_EMPLOYEE,
	UNKNOWN
};

class User
{
private:
	MyString name="";
	long egn=0;
	int age=0;
	MyString passw="";
	UserType role = UserType::UNKNOWN;


public:
	void exit()const;
	virtual void help()const= 0;
	virtual User* clone() const = 0;
	virtual void whoami() const = 0;
	User() = default;
	User(const MyString& name, long egn, int age, const MyString& passw) :name(name), 
																							  egn(egn), 
																							  age(age),
																							 
																							  passw(passw) {};
	User(const MyString& name, const MyString& passw) :name(name),	passw(passw) {};

	User(const User& other)
	{
		this->name = other.name;
		this->age = other.age;
		this->egn = other.egn;
		this->passw = other.passw;
	}

	const char* getName()const
	{
		return name.c_str();
	}
	long getEgn()const
	{
		return egn;
	}
	int getAge()const
	{
		return age;
	}
	const char* getPass()const
	{
		return passw.c_str();
	}
	/*UserType setUserType(const MyString& rol)
	{
		if (rol == "Client")
		{
			return UserType::CLIENT;
		}
		else if (rol == "Employee")
		{
			return UserType::EMPLOYEE;
		}
		else if (rol == "ThirdPartyEmployee")
		{
			return UserType::THIRD_PARTY_EMPLOYEE;
		}
		return UserType::UNKNOWN;
	}*/
};

