#include "ListCmd.h"

ListCmd::ListCmd(const MyString& bankName) :bankName(bankName)
{
}

void ListCmd::execute()
{
	c.list(bankName);
}
