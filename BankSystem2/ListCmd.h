#pragma once
#include "Command.h"
#include "Client.h"
class ListCmd :Command
{
private:
	Client c;
	MyString bankName;
public:
	ListCmd(const MyString& bankName);
	void execute()override;
};

