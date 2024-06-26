#pragma once
#include "..\Command.h"

class ExitCmd :public Command
{
	//User u;
public:
	ExitCmd() = default;
	void execute()override;
};

