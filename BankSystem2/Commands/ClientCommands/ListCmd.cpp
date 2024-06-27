#include "ListCmd.h"

ListCmd::ListCmd(Client* c,const MyString& bankName) :c(c),bankName(bankName)
{
}

void ListCmd::execute()
{
	c->list(bankName);
}
