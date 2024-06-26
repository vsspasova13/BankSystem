#pragma once
#include "..\Command.h"

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


