#pragma once
#include "Task.h"
#include <iostream>
class CloseTask :public Task
{
public:
	void print()const override;
	CloseTask(int id, const Client& cl) :Task(id, cl) {};
	void execute(const MyString& bankName) override;
	Task* clone() const override { return new CloseTask(*this); }
};

