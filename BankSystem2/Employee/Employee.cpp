#include "Employee.h"
#include "../Task/ValidateTask.h"

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
	if((empTasks[taskId]->getType()!=TaskType::CHANGE_TASK)||
	(empTasks[taskId]->getType()==TaskType::CHANGE_TASK &&
	empTasks[taskId]->getValidated()==true))
	{
		empTasks[taskId]->execute(bankName);
		std::cout << "approved";
	}
	else std::cout << "Cannot proceed - please make sure"<< empTasks[taskId]->getClient().getName() <<"is real user by asking the bank!";
}

void Employee::disapprove(int taskId, const MyString& message) const
{
	if ((empTasks[taskId]->getType() != TaskType::CHANGE_TASK) ||
		(empTasks[taskId]->getType() == TaskType::CHANGE_TASK &&
			empTasks[taskId]->getValidated() == true))
	{
		empTasks[taskId]->getClient().addMessage(message);
	}
	else std::cout << "Cannot proceed - please make sure" << empTasks[taskId]->getClient().getName() << "is real user by asking the bank!";

}

bool Employee::validate(int taskId) 
{
	
	Client cl=empTasks[taskId]->getClient();
	ValidateTask val(cl,empTasks[taskId]->getBankName(),empTasks[taskId]->getAccNum());
	bool isItValidated=val.validate();
	empTasks[taskId]->setValidated(isItValidated);
	return true;
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
