#pragma once
#include "User.h"
#include "Task.h"
#include "Client.h"

class Employee:public User
{
private:
	MyString bankName;
	Vector<Polymorphic_Ptr<Task>> empTasks;

public:
	int tasksCount()const;
	void addTask(const Polymorphic_Ptr<Task>  task);
	void tasks()const;//
	void view(int taskId)const;
	void approve(int taskId);
	void disapprove(int taskId, const MyString& message)const;
	void validate(int taskId)const;

};

