#pragma once
#include "User.h"
#include "Command.h"
class ExitCmd :Command
{
	User u;
public:
	ExitCmd() = default;
	void execute()override;
};

