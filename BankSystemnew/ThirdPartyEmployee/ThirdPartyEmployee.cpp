#include "ThirdPartyEmployee.h"

void ThirdPartyEmployee::send_check(unsigned long sum, const MyString& verification_code, unsigned long egn) const
{
	System& s = System::getInstance();
	for (int i = 0; i < s.getUsers().getSize(); i++)
	{
		if (s.getUsers()[i]->getEgn() == egn)
		{
			//s.getUsers()[i]
		}
	}
}

User* ThirdPartyEmployee::clone() const
{
	return new ThirdPartyEmployee(*this);
}

void ThirdPartyEmployee::help() const
{
}

void ThirdPartyEmployee::whoami() const
{
}
