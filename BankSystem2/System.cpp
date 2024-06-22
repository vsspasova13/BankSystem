#include "System.h"

void System::login() const
{
}

void System::signUp() const
{
}

void System::create_bank(const MyString& name) 
{
	Bank b(name);
	banks.pushBack(b);
}
