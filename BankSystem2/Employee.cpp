#include "Employee.h"

int Employee::tasksCount()const
{
	return empTasks.getSize();
}
void Employee::addTask(const Polymorphic_Ptr<Task>  task)
{
	empTasks.pushBack(task);
}

void Employee::tasks() const
{
	for (int i = 0; i < empTasks.getSize(); i++)
	{
		empTasks[i]->print();
	}
}

void Employee::view(int taskId) const
{
	empTasks[taskId]->view();
}

void Employee::approve(int taskId) 
{
	empTasks[taskId]->execute(bankName);
	std::cout << "approved";
}

void Employee::disapprove(int taskId, const MyString& message) const
{
	empTasks[taskId]->getClient().addMessage(message);
}

void Employee::validate(int taskId) const
{
	
}

User* Employee::clone() const
{
	return new Employee(*this);
}

void Employee::help() const
{
}

void Employee::whoami() const
{
}
