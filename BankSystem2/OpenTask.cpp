#include "OpenTask.h"
#include <iostream>

void OpenTask::print() const
{
	std::cout << "[" << id << "]" << "Open - " <<client.getName()<< " wants to create an account." << std::endl;
}

void OpenTask::execute(const MyString& bankName)
{
	
	client.addAccount(bankName, 777);

}
