#pragma once
#include "..\Command.h"

class MessagesCmd :public Command
{
private:
	Client* c;
public:
	MessagesCmd(Client* c) :c(c) {};
	void execute()override;
};

