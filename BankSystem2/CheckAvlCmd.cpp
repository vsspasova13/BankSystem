#include "CheckAvlCmd.h"

CheckAvlCmd::CheckAvlCmd(const MyString& bankName, long accNum) :bankName(bankName), accNum(accNum)
{
}

void CheckAvlCmd::execute()
{
	cl.check_avl(bankName, accNum);
}