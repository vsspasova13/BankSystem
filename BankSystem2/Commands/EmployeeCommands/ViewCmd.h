#pragma once
#include "..\Command.h"

class ViewCmd :public Command
{
private:
	Employee* e;
	int id;
public:
	ViewCmd(Employee* e,int id);
	void execute()override;
};


