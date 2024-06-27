#pragma once
#include "..\Command.h"

class CloseCmd :public Command
{
private:
	MyString bankName;
	Client* c;
	long accNum;
public:
	CloseCmd(Client* c,const MyString& bankName, long accNum);
	void execute()override;
};


