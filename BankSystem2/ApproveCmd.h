#pragma once
#include "Command.h"
#include "Employee.h"
class ApproveCmd : public Command
{
private:
	Employee e;
	int id;
public:
	ApproveCmd(int id);
	void execute()override;
};


