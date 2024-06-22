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
}

void Employee::view(int taskId) const
{
}

void Employee::approve(int taskId) 
{
	empTasks[taskId]->execute(bankName);
	std::cout << "gtv";
}

void Employee::disapprove(int taskId, const MyString& message) const
{

}

void Employee::validate(int taskId) const
{
}
