#pragma once
#include "Command.h"
#include "MyString.h"
#include "Client.h"

class ChangeCmd :Command
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

