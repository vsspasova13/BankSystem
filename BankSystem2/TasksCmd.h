#pragma once
#include "Command.h"
#include "Employee.h"
class TasksCmd :public Command
{
private:
	Employee e;
public:
	TasksCmd() = default;
	void execute()override;
};
