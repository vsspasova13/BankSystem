#pragma once
#include "..\Command.h"

class MessagesCmd :public Command
{
private:
	Client c;
public:
	void execute()override;
};

