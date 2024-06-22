#pragma once
#include "Command.h"
#include "System.h"
class CreateBankCmd :Command
{
private:
	System s;
public:
	CreateBankCmd() = default;
	void execute()override;
};


