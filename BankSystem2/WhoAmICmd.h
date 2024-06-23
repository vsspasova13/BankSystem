#pragma once
#include "User.h"
#include "Command.h"
class WhoAmICmd :Command
{
	//User u;
public:
	WhoAmICmd() = default;
	void execute()override;
};

