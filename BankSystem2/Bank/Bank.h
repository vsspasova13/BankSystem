#pragma once
#include "..\Utils\Polymorphic_Ptr.hpp"
#include "..\Utils\MyString.h"
#include "..\Utils\Vector.hpp"
#include "..\Client\Client.h"
#include "..\Employee\Employee.h"
#include "../Task/Task.h"

class Client;
class Employee;
class Task;
static int id = 1;
class Bank
{
private:

	MyString bankName;
	Vector<Client*> clients;
	Vector<Employee*> employees;
	Vector<Polymorphic_Ptr<Task>> tasks;

public:
	Bank()=default;
	Bank(const MyString& name);
	Polymorphic_Ptr<Task> openTask(Client* c, const MyString& bankName);
	Polymorphic_Ptr<Task> closeTask(Client* c, const MyString& bankName, unsigned long accNumber);
	Polymorphic_Ptr<Task> changeTask(Client* c, const MyString& newBankName, const MyString& currBankName, unsigned long accNumber);
	void giveTask(const Polymorphic_Ptr<Task> task);

	const MyString& getName()const;
	const Vector<Polymorphic_Ptr<Task>>& getTasks()const;
	Vector<Employee*>& getEmployees();
	Vector<Client*>& getClients();
	
	void addEmployee(Employee* emp);
	void addClient(Client* cl);
	void removeClient(Client* cl);
	size_t findClientIndex(Client* cl)const;
	bool containsClientByAccountNum(long accountNum)const;

};

