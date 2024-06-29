#include "CheckAvlCmd.h"

CheckAvlCmd::CheckAvlCmd(Client* c,const MyString& bankName, long accNum) :cl(c),bankName(bankName), accNum(accNum)
{
}

void CheckAvlCmd::execute()
{
	cl->check_avl(bankName, accNum);
}