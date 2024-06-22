#include "CloseTask.h"
void CloseTask::print() const
{
	std::cout << "[" << id << "]" << "Open - " << client.getName() << " wants to create an account." << std::endl;
}

void CloseTask::execute(const MyString& bankName)
{
	client.removeAccount(bankName, 777);

}