#include "Bank.h"
#include "..\Task\OpenTask.h"
#include "..\Task\ChangeTask.h"
#include "..\Task\CloseTask.h"

Bank::Bank(const MyString& name)
{
	this->bankName = name;
}

Polymorphic_Ptr<Task> Bank::openTask(Client* c, const MyString& bankName)
{
	Polymorphic_Ptr<Task> task(new OpenTask(tasks.getSize(), c, bankName));
	tasks.pushBack(task);
	return task;
}

Polymorphic_Ptr<Task> Bank::closeTask(Client* c, const MyString& currBankName, unsigned long accNumber)
{
	Polymorphic_Ptr<Task> task(new CloseTask(tasks.getSize(), c,currBankName,accNumber));
	tasks.pushBack(task);
	return task;
	
}
Polymorphic_Ptr<Task> Bank::changeTask(Client* c, const MyString& newBankName, const MyString& currBankName, unsigned long accNumber)
{
	Polymorphic_Ptr<Task> task(new ChangeTask(tasks.getSize(), c,newBankName,currBankName,accNumber));
	tasks.pushBack(task);
	return task;
}
void Bank::giveTask(const Polymorphic_Ptr<Task> task)
{
	if (employees.getSize() == 0)throw std::out_of_range("No employees");

	int minInd = 0, minCount = employees[0]->tasksCount();
	for (int i = 0; i < employees.getSize(); i++)
	{
		if (employees[i]->tasksCount() < minCount)minInd = i;
	}
	employees[minInd]->addTask(task);
	std::cout << "added clname:" << task->getClient()->getName() << " task: ";
	task->view();
	std::cout << "Emp: " << employees[minInd]->getName() << std::endl;
}

const MyString& Bank::getName()const
{
	return bankName;

}
const Vector<Polymorphic_Ptr<Task>>& Bank::getTasks()const
{
	return tasks;
}

Vector<Employee*>& Bank::getEmployees() 
{
	return employees;
}

Vector<Client*>& Bank::getClients() 
{
	return clients;
}

void Bank::addEmployee(Employee* emp)
{
	employees.pushBack(emp);
}

void Bank::addClient(Client* cl)
{
	clients.pushBack(cl);
}

size_t Bank::findClientIndex(Client* cl)const
{
	for (size_t i = 0; i < clients.getSize(); i++)
	{
		if (clients[i]->getEgn() == cl->getAge())
			return i;
	}
	return -1;
}

void Bank::removeClient(Client* cl)
{
	//ex
	int ind = findClientIndex(cl);
	clients.erase(ind);
}

bool Bank::containsClientByAccountNum(long accountNum) const
{
	for (size_t i = 0; i < clients.getSize(); i++)
	{
		for (size_t j = 0; j < clients[i]->getAccount().getSize(); j++)
		{
			if (clients[i]->getAccount()[j].acc_number==accountNum)
			{
				return true;
			}

		}
	}
	return false;
}
