#pragma once
#include <iostream>
#include "../Client/Client.h"

class Client;

enum class TaskType
{
	OPEN_TASK,
	CLOSE_TASK,
	CHANGE_TASK
};

class Task
{
protected:
	int id;
	Client client;
	bool validated = false;
	MyString bankName = "";
	long acc_Num = 0;

public:
	Task(int id, const Client& cl) :id(id), client(cl) {};
	Task(int id, const Client& cl, const MyString& bankName,long accNum) :
		id(id), client(cl),
		bankName(bankName),
		acc_Num(accNum) {};
	Task(int id, const Client& cl, const MyString& bankName) :
		id(id), client(cl),
		bankName(bankName){};
	virtual Task* clone() const = 0;
	virtual void execute(const MyString& bankName) = 0;
	virtual void view()const = 0;
	virtual void print()const = 0;
	virtual TaskType getType()const = 0;
	virtual ~Task() = default;
	void setValidated(bool value)
	{
		validated = value;
	}
	bool getValidated()const
	{
			return validated;
	}
	Client getClient()const
	{
		return client;
	}
	const MyString& getBankName()const
	{
		return bankName;
	}
	long getAccNum()const
	{
		return acc_Num;
	}

};



