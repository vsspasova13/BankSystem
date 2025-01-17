#pragma once
#include "..\Command.h"

class CreateBankCmd :public Command
{
private:
	System& s=System::getInstance();
	MyString bank;
public:
	CreateBankCmd(const MyString& bank) :bank(bank) {};
	CreateBankCmd() = default;
	void execute()override;
};


