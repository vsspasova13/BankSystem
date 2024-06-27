#include "Employee.h"
#include "../Task/ValidateTask.h"

int Employee::tasksCount()const
{
	return empTasks.getSize();
	return taskss.getSize();
}
void Employee::addTask(const Polymorphic_Ptr<Task>  task)
{
	empTasks.pushBack(task);
	taskss.push(task);
}

void Employee::removeTask(int ind)
{

	empTasks.erase(ind);
	taskss.pop();
}

void Employee::tasks() const
{
	/*for (int i = 0; i < empTasks.getSize(); i++)
	{
		empTasks[i]->print();

	}*/
	MyQueue<Polymorphic_Ptr<Task>> temp = taskss;
		while (!temp.isEmpty())
		{
			temp.peek()->print();
			temp.pop();
		}
}

void Employee::view(int taskId) const
{
	//empTasks[taskId]->view();
	taskss.peek()->view();
}

void Employee::approve(int taskId) 
{
	if((empTasks[taskId]->getType()!=TaskType::CHANGE_TASK)||
	(empTasks[taskId]->getType()==TaskType::CHANGE_TASK &&
	empTasks[taskId]->getValidated()==true))
	{
		empTasks[taskId]->execute(bankName);
		std::cout << "approved";
		removeTask(taskId);
	}
	else std::cout << "Cannot proceed - please make sure"<< empTasks[taskId]->getClient()->getName() <<"is real user by asking the bank!";

	/*if ((taskss.peek()->getType() != TaskType::CHANGE_TASK) ||
		(taskss.peek()->getType() == TaskType::CHANGE_TASK &&
			taskss.peek()->getValidated() == true))
	{
		taskss.peek()->execute(bankName);
		
		std::cout << "approved";
		taskss.pop();
	}*/

}

void Employee::disapprove(int taskId, const MyString& message) 
{
	if ((empTasks[taskId]->getType() != TaskType::CHANGE_TASK) ||
		(empTasks[taskId]->getType() == TaskType::CHANGE_TASK &&
			empTasks[taskId]->getValidated() == true))
	{
		MyString mes = "Your Close request was not approved. Reason: ";
		mes += message;
		empTasks[taskId]->getClient()->addMessage(mes);
		taskss.pop();
	}
	else std::cout << "Cannot proceed - please make sure" << empTasks[taskId]->getClient()->getName() << "is real user by asking the bank!";

}

bool Employee::validate(int taskId) 
{
	
	Client* cl= empTasks[taskId]->getClient();
	ValidateTask val(cl,empTasks[taskId]->getBankName(),empTasks[taskId]->getAccNum());
	bool isItValidated=val.validate();
	empTasks[taskId]->setValidated(isItValidated);
	taskss.pop();
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
