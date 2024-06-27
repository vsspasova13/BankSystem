#pragma once
#include "..\Command.h"

class Client;

class OpenCmd :public Command
{
private:
	MyString bankName;
	Client* c;
public:
	OpenCmd(Client* c,const MyString& bankName);
	void execute()override;

};

