#pragma once
#include "Command.h"
#include "Client.h"
class MessagesCmd :public Command
{
private:
	Client c;
public:
	void execute()override;
};

