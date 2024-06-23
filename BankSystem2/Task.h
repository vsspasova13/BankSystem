#pragma once
#include <iostream>
#include "Client.h"

class Client;

class Task
{
protected:
	int id;
	Client client;

public:
	Task(int id, const Client& cl) :id(id), client(cl) {};
	virtual Task* clone() const = 0;
	virtual void execute(const MyString& bankName) = 0;
	virtual void view()const = 0;
	virtual void print()const = 0;
	virtual ~Task() = default;
	Client getClient()const
	{
		return client;
	}

};



