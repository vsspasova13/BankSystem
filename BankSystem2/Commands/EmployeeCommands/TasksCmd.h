#pragma once
#include "..\Command.h"

class TasksCmd :public Command
{
private:
	Employee* e;
public:
	TasksCmd(Employee* e) :e(e) {};
	void execute()override;
};
