#include "RedeemCmd.h"

RedeemCmd::RedeemCmd(const MyString& name, long accNum, const MyString& code)
{
	bankName = name;
	this->accNum = accNum;
	this->code = code;
}

void RedeemCmd::execute()
{
	c.redeem(bankName, accNum, code);
}
