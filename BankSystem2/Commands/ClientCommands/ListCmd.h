#pragma once
#include "..\Command.h"

class ListCmd :public Command
{
private:
	Client* c;
	MyString bankName;
public:
	ListCmd(Client* c,const MyString& bankName);
	void execute()override;
};

