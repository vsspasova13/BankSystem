#pragma once
#include "Command.h"
#include "Employee.h"
class DisapproveCmd :Command
{
private:
	Employee e;
	int id;
	MyString message;
public:
	DisapproveCmd(int id, const MyString& mes);
	void execute()override;
};



