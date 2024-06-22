#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Polymorphic_Ptr.hpp"

class User
{
private:
	MyString name;
	long egn;
	int age;
	MyString passw;

public:
	void exit()const;
	void whoami()const;
	void help()const;

	const char* getName()const
	{
		return name.c_str();
	}
};

