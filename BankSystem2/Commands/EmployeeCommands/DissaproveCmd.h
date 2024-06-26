#pragma once
#include "..\Command.h"

class DisapproveCmd :public Command
{
private:
	Employee e;
	int id;
	MyString message;
public:
	DisapproveCmd(int id, const MyString& mes);
	void execute()override;
};



