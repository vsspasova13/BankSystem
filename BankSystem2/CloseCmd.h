#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"
class CloseCmd :public Command
{
private:
	MyString bankName;
	Client c;
	long accNum;
public:
	CloseCmd(const MyString& bankName, long accNum);
	void execute()override;
};


