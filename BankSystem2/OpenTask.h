#pragma once
#include <iostream>
#include "Task.h"

class OpenTask : public Task
{
public:
	OpenTask(int id, const Client& cl) :Task(id, cl) {};
	void print()const override;
	void view()const override;
	void execute(const MyString& bankName) override;
	Task* clone() const override { return new OpenTask(*this); }
};

