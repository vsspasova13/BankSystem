#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Polymorphic_Ptr.hpp"

class User
{
private:
	MyString name="";
	long egn=0;
	int age=0;
	MyString passw="";

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
};

