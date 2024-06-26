#pragma once
#include "..\Command.h"

class ViewCmd :public Command
{
private:
	Employee e;
	int id;
public:
	ViewCmd(int id);
	void execute()override;
};


