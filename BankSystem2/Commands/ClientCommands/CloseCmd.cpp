#include "CloseCmd.h"

CloseCmd::CloseCmd(Client* c,const MyString& bankName, long accNum) :c(c),bankName(bankName), accNum(accNum)
{
}

void CloseCmd::execute()
{
	c->close(bankName, accNum);
}