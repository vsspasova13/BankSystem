#pragma once
#include "Task.h"
#include <iostream>

class Task;

class CloseTask :public Task
{
public:
	void print()const override;
	void view()const override;
	CloseTask(int id,const const Client& cl, const MyString& bankName, long accNum) :Task(id, cl, bankName, accNum) {};
	void execute(const MyString& bankName) override;
	TaskType getType()const override;
	Task* clone() const override { return new CloseTask(*this); }
};

