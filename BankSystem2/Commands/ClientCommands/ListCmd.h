#pragma once
#include "..\Command.h"

class ListCmd :public Command
{
private:
	Client c;
	MyString bankName;
public:
	ListCmd(const MyString& bankName);
	void execute()override;
};

