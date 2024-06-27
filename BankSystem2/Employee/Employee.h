#pragma once
#include "../User/User.h"
#include "../Task/Task.h"
#include "../Client/Client.h"
#include "../Utils/Queue.hpp"

class Task;

class Employee:public User
{
private:
	MyString bankName="";
	MyQueue<Polymorphic_Ptr<Task>> taskss;
	Vector<Polymorphic_Ptr<Task>> empTasks;
	

public:
	Employee() = default;
	Employee(const MyString& name, long egn, int age, const MyString& passw, const MyString& bankName) :User(name, egn, age, passw), bankName(bankName) {};
	
	void addTask(const Polymorphic_Ptr<Task>  task);
	void removeTask(int ind);
	void tasks()const;
	void view(int taskId)const;
	void approve(int taskId);
	void disapprove(int taskId, const MyString& message);
	bool validate(int taskId);
	
	int tasksCount()const;
	User* clone() const override;
	virtual void help()const override;
	virtual void whoami() const override;
};

