#pragma once
#include "User.h"
#include "Command.h"
class HelpCmd :Command
{
	User u;
public:
	HelpCmd() = default;
	void execute()override;
};


