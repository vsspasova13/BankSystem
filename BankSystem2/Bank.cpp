#include "Bank.h"

Bank::Bank(const MyString& name)
{
	this->bankName = name;
}

Polymorphic_Ptr<Task> Bank::openTask(const Client& c)
{
	Polymorphic_Ptr<Task> task(new OpenTask(tasks.getSize(), c));
	tasks.pushBack(task);
	return task;
}

Polymorphic_Ptr<Task> Bank::closeTask(const Client& c)
{
	Polymorphic_Ptr<Task> task(new CloseTask(tasks.getSize(), c));
	tasks.pushBack(task);
	return task;
	
}
Polymorphic_Ptr<Task> Bank::changeTask(const Client& c)
{
	Polymorphic_Ptr<Task> task(new ChangeTask(tasks.getSize(), c));
	tasks.pushBack(task);
	return task;
}
void Bank::giveTask(const Polymorphic_Ptr<Task> task)
{
	if (employees.getSize() == 0)throw std::out_of_range("No employees");

	int minInd = 0, minCount = employees[0].tasksCount();
	for (int i = 0; i < employees.getSize(); i++)
	{
		if (employees[i].tasksCount() < minCount)minInd = i;
	}
	employees[minInd].addTask(task);
}

const MyString& Bank::getName()const
{
	return bankName;

}
const Vector<Polymorphic_Ptr<Task>>& Bank::getTasks()const
{
	return tasks;
}

Vector<Employee> Bank::getEmployees() 
{
	return employees;
}

Vector<Client> Bank::getClients() 
{
	return clients;
}

void Bank::addEmployee(const Employee& emp)
{
	employees.pushBack(emp);
}

bool Bank::containsClientByAccountNum(long accountNum) const
{
	for (size_t i = 0; i < clients.getSize(); i++)
	{
		for (size_t j = 0; j < clients[i].getAccount().getSize(); j++)
		{
			if (clients[i].getAccount()[j].acc_number==accountNum)
			{
				return true;
			}

		}
	}
	return false;
}
