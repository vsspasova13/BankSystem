#pragma once
#include "Command.h"
#include "ThirdPartyEmployee.h"

class SednCheckCmd :public Command
{
private:
	long sum;
	MyString code;
	long egn;
	ThirdPartyEmployee t;

public:
	SednCheckCmd(long sum, const MyString& code, long egn);
	void execute()override;
};
