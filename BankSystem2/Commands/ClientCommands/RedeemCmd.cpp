#include "RedeemCmd.h"

RedeemCmd::RedeemCmd(Client* c,const MyString& name, long accNum, const MyString& code)
{
	this->c = c;
	bankName = name;
	this->accNum = accNum;
	this->code = code;
}

void RedeemCmd::execute()
{
	c->redeem(bankName, accNum, code);
}
