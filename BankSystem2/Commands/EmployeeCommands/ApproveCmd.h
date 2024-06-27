#pragma once
#include "..\Command.h"

class ApproveCmd : public Command
{
private:
	Employee* e;
	int id;
public:
	ApproveCmd(Employee* e,int id);
	void execute()override;
};


