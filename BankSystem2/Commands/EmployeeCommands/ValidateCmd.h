#pragma once
#include "..\Command.h"

class ValidateCmd :public Command
{
private:
	Employee* e;
	int id;
public:
	ValidateCmd(Employee* e,int id);
	void execute()override;
};

