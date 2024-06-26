#pragma once
#include "Task.h"
#include "../Bank/Bank.h"
#include "../System/System.h"

class Task;

class ChangeTask :public Task
{
	const MyString& newBankName;

public:
	ChangeTask(int id, const Client& cl, const MyString& newBankName, const MyString& currBankName,
	long accNum) :
		Task(id, cl,currBankName,accNum), 
		newBankName(newBankName){};
	
	void print()const override;
	void view()const override;
	
	void execute(const MyString& newBankName) override;
	TaskType getType()const override;
	Task* clone() const override { return new ChangeTask(*this); }
};

