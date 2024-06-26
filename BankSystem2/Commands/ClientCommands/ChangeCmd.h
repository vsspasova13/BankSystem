#pragma once
#include "..\Command.h"

class ChangeCmd :public Command
{
private:
	MyString currBank;
	MyString newBank;
	long accNum;
	Client c;

public:
	ChangeCmd(const MyString& newBank, const MyString& currBank, long accNum);
	void execute()override;

};
