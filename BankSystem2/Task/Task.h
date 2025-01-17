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
	Client* client;
	bool validated = false;
	MyString bankName = "";
	long acc_Num = 0;

public:
	//Task(int id, const Client& cl) :id(id), client(cl) {};
	Task(int id, Client* cl, const MyString& bankName,long accNum) :
		id(id), client(cl),
		bankName(bankName),
		acc_Num(accNum) {};
	Task(int id,  Client* cl, const MyString& bankName) :
		id(id), client(cl),
		bankName(bankName){};

	virtual Task* clone() const = 0;
	virtual void execute(const MyString& bankName) = 0;
	virtual void view()const = 0;
	virtual void print()const = 0;
	virtual TaskType getType()const = 0;
	virtual ~Task() = default;
	void setValidated(bool value);
	bool getValidated()const;
	Client* getClient()const;
	const MyString& getBankName()const;
	long getAccNum()const;

};



