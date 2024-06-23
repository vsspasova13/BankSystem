#include "OpenTask.h"
#include <iostream>

void OpenTask::print() const
{
	std::cout << "[" << id << "]" << "Open - " <<client.getName()<< " wants to create an account." << std::endl;
}

void OpenTask::view() const
{
	std::cout << "Open request from:" << std::endl;
	std::cout << "Name: " << client.getName() << std::endl;
	std::cout << "Egn: " << client.getEgn() << std::endl;
	std::cout << "Age: " << client.getAge() << std::endl;
}

void OpenTask::execute(const MyString& bankName)
{
	
	client.addAccount(bankName, 777);

}
