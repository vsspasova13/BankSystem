#include "OpenCmd.h"

OpenCmd::OpenCmd(Client* c,const MyString& bankName) :c(c),bankName(bankName)
{
}

void OpenCmd::execute()
{
	c->open(bankName);
}
