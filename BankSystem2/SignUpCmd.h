#pragma once
#include "Command.h"
#include "System.h"
class SignUpCmd :public Command
{
private:
	System& s=System::getInstance();
	MyString name;
	MyString passw;
	long egn;
	int age;
	MyString role;
	MyString bank = "";
public:
	SignUpCmd(const MyString& name, long egn, int age, const MyString& userType, const MyString& bankName, const MyString& password);
	SignUpCmd() = default;
	void execute()override;
};

