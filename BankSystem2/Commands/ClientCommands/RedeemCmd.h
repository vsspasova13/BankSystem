#pragma once
#include "..\Command.h"

class RedeemCmd :public Command
{
private:
	MyString bankName;
	Client* c;
	long accNum;
	MyString code;
public:
	RedeemCmd(Client* c,const MyString& name, long accNum, const MyString& code);
	void execute()override;
};

