#pragma once
#include "..\Command.h"

class ExitCmd :public Command
{
	System& s = System::getInstance();
public:
	ExitCmd() = default;
	void execute()override;
};

