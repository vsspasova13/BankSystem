#include "ChangeCmd.h"

ChangeCmd::ChangeCmd(Client* c,const MyString& newBank, const MyString& currBank, long accNum)
{
	this->c = c;
	this->newBank = newBank;
	this->currBank = currBank;
	this->accNum = accNum;
}

void ChangeCmd::execute()
{
	c->change(newBank, currBank, accNum);
}
