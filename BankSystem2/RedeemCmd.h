#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"
class RedeemCmd :public Command
{
private:
	MyString bankName;
	Client c;
	long accNum;
	MyString code;
public:
	RedeemCmd(const MyString& name, long accNum, const MyString& code);
	void execute()override;
};

