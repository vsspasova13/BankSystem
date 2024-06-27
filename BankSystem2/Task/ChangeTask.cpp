#include "ChangeTask.h"

void ChangeTask::print() const
{
	std::cout << "[" << id << "]" << "Change - " << client->getName() << " wants to change an account." << std::endl;
}

void ChangeTask::view() const
{
	std::cout << "Change request from:" << std::endl;
	std::cout << "Name: " << client->getName() << std::endl;
	std::cout << "Egn: " << client->getEgn() << std::endl;
	std::cout << "Age: " << client->getAge() << std::endl;
}

void ChangeTask::execute(const MyString& newBankName)
{
	System& s = System::getInstance();
	//bool b=s.findBankByName(newBankName).containsClientByAccountNum(acc_Num);
	Bank& newB = s.findBankByName(newBankName);
	Bank& oldB = s.findBankByName(bankName);

	newB.addClient(client);
	client->addAccount(newBankName, 99);

	oldB.removeClient(client);
	client->removeAccount(bankName, acc_Num);

}

TaskType ChangeTask::getType() const
{
	return TaskType::CHANGE_TASK;
}
