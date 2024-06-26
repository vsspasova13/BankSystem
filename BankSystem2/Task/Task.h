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

public:
	Task(int id, const Client& cl) :id(id), client(cl) {};
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

};



