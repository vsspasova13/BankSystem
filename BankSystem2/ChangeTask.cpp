#include "ChangeTask.h"

void ChangeTask::print() const
{
	std::cout << "[" << id << "]" << "Change - " << client.getName() << " wants to change an account." << std::endl;
}

void ChangeTask::view() const
{
	std::cout << "Change request from:" << std::endl;
	std::cout << "Name: " << client.getName() << std::endl;
	std::cout << "Egn: " << client.getEgn() << std::endl;
	std::cout << "Age: " << client.getAge() << std::endl;
}

void ChangeTask::execute(const MyString& bankName)
{

}
