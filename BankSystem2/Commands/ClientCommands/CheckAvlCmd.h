#pragma once
#include "..\Command.h"

class CheckAvlCmd :public Command
{

private:
	MyString bankName;
	long accNum;
	Client* cl;

public:
	CheckAvlCmd(Client* c,const MyString& bankName, long accNum);
	void execute()override;
};

