#pragma once
#include "..\Command.h"

class WhoAmICmd :Command
{
	//User u;
public:
	WhoAmICmd() = default;
	void execute()override;
};

