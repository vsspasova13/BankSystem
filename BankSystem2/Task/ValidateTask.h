#pragma once
#include "Task.h"
#include "../System/System.h"


class ValidateTask
{
	Client client;
	MyString bankName = "";
	long acc_Num = 0;
	const MyString& currBankName;

public:
	ValidateTask(const Client& cl, const MyString& currBankName,long accNum) :
		client(cl), currBankName(currBankName), acc_Num(accNum){};

	bool validate()const;

};

