#pragma once
#include "Task.h"
#include "../Client/Client.h"

void Task::setValidated(bool value)
{
	validated = value;
}
bool Task::getValidated()const
{
	return validated;
}
Client* Task::getClient()const
{
	return client;
}
const MyString& Task::getBankName()const
{
	return bankName;
}
long Task::getAccNum()const
{
	return acc_Num;
}