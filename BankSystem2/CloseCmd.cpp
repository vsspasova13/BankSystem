#include "CloseCmd.h"

CloseCmd::CloseCmd(const MyString& bankName, long accNum) :bankName(bankName), accNum(accNum)
{
}

void CloseCmd::execute()
{
	c.close(bankName, accNum);
}