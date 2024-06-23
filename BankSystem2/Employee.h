#pragma once
#include "User.h"
#include "Task.h"
#include "Client.h"

class Employee:public User
{
private:
	MyString bankName="";
	Vector<Polymorphic_Ptr<Task>> empTasks;

public:
	Employee() = default;
	Employee(const MyString& name, long egn, int age, const MyString& passw, const MyString& bankName) :User(name, egn, age, passw), bankName(bankName) {};
	
	void addTask(const Polymorphic_Ptr<Task>  task);
	void tasks()const;
	void view(int taskId)const;
	void approve(int taskId);
	void disapprove(int taskId, const MyString& message)const;
	void validate(int taskId)const;
	
	int tasksCount()const;
	User* clone() const override;
	virtual void help()const override;
	virtual void whoami() const override;
};

