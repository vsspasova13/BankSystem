#include "CloseTask.h"
void CloseTask::print() const
{
	std::cout << "[" << id << "]" << "Close - " << client.getName() << " wants to close an account." << std::endl;
}

void CloseTask::view() const
{
	std::cout << "Close request from:" << std::endl;
	std::cout<<"Name: "<<client.getName() <<std::endl;
std::cout<<"Egn: "<<client.getEgn() <<std::endl;
std::cout<<"Age: "<<client.getAge() <<std::endl;
}

void CloseTask::execute(const MyString& bankName)
{
	client.removeAccount(bankName, 777);

}

TaskType CloseTask::getType() const
{
	return TaskType::CLOSE_TASK;
}
