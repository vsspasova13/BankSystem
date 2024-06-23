#pragma once
#include "System.h"
#include "Command.h"
class LoginCmd :public Command
{
private:
	System& s = System::getInstance();
	MyString name;
	MyString pass;
public:
	LoginCmd() = default;
	LoginCmd(const MyString& name, const MyString& pass):name(name), pass(pass){};
	void execute()override;
};

