#pragma once
#include "Task.h"
class ChangeTask :public Task
{
	const MyString& newBankName;
	const MyString& currBankName;
	long accNum;

public:
	ChangeTask(int id, const Client& cl, const MyString& newBankName, const MyString& currBankName,
	long accNum) :Task(id, cl), 
		newBankName(newBankName), 
		currBankName(currBankName), 
		accNum(accNum) {};
	
	void print()const override;
	void view()const override;
	
	void execute(const MyString& newBankName) override;
	TaskType getType()const override;
	Task* clone() const override { return new ChangeTask(*this); }
};

