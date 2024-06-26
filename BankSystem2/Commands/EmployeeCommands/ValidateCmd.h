#pragma once
#include "..\Command.h"

class ValidateCmd :public Command
{
private:
	Employee e;
	int id;
public:
	ValidateCmd(int id);
	void execute()override;
};

