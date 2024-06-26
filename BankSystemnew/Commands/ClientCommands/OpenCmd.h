#pragma once
#include "..\Command.h"

class OpenCmd :public Command
{
private:
	MyString bankName;
	Client c;
public:
	OpenCmd(const MyString& bankName);
	void execute()override;

};

