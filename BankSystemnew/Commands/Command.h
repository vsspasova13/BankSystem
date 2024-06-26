#pragma once
#include "..\..\Utils\MyString.h"
#include "..\..\Client\Client.h"
#include "..\Employee\Employee.h"
#include "..\System\System.h"
#include "..\User\User.h"
#include "..\ThirdPartyEmployee\ThirdPartyEmployee.h"

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() = default;
};

