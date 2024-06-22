#include "ChangeCmd.h"

ChangeCmd::ChangeCmd(const MyString& newBank, const MyString& currBank, long accNum)
{
	this->newBank = newBank;
	this->currBank = currBank;
	this->accNum = accNum;
}

void ChangeCmd::execute()
{
	c.change(newBank, currBank, accNum);
}
