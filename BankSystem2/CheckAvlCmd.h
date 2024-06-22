#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"

class CheckAvlCmd :public Command
{

private:
	MyString bankName;
	long accNum;
	Client cl;

public:
	CheckAvlCmd(const MyString& bankName, long accNum);
	void execute()override;
};

