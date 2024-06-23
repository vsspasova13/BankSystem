#pragma once
#include "Task.h"
class ChangeTask :public Task
{
public:
	void print()const override;
	void view()const override;
	ChangeTask(int id, const Client& cl) :Task(id, cl) {};
	void execute(const MyString& bankName) override;
	Task* clone() const override { return new ChangeTask(*this); }
};

