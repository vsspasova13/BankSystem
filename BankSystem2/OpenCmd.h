#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"

class OpenCmd :public Command
{
private:
	MyString bankName;
	Client c;
public:
	OpenCmd(const MyString& bankName);
	void execute()override;

};

