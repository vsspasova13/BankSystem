#pragma once
#include "..\Utils\MyString.h"
#include "..\Utils\Vector.hpp"
#include "..\Client\Client.h"
#include "..\Employee\Employee.h"
#include "..\Utils\Polymorphic_Ptr.hpp"
#include "..\Task\Task.h"
#include "..\Task\OpenTask.h"
#include "..\Task\ChangeTask.h"
#include "..\Task\CloseTask.h"

class Client;
class Employee;

class Bank
{
private:
	MyString bankName;
	Vector<Client> clients;
	Vector<Employee> employees;
	Vector<Polymorphic_Ptr<Task>> tasks;

public:
	Bank()=default;
	Bank(const MyString& name);
	Polymorphic_Ptr<Task> openTask(const Client& c);
	Polymorphic_Ptr<Task> closeTask(const Client& c);
	Polymorphic_Ptr<Task> changeTask(const Client& c, );
	void giveTask(const Polymorphic_Ptr<Task> task);

	const MyString& getName()const;
	const Vector<Polymorphic_Ptr<Task>>& getTasks()const;
	Vector<Employee> getEmployees();
	Vector<Client> getClients();
	
	void addEmployee(const Employee& emp);
	bool containsClientByAccountNum(long accountNum)const;

};

