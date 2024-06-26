#include "OpenCmd.h"

OpenCmd::OpenCmd(const MyString& bankName) :bankName(bankName)
{
}

void OpenCmd::execute()
{
	c.open(bankName);
}
