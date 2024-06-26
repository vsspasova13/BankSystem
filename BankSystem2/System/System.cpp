#include "System.h"

void System::writeInFile(const MyString& fileName, const User& u)const
{
	std::ofstream ofs(fileName.c_str(), std::ios::out);

	ofs << u.getName() << " " << u.getPass() << std::endl;

	ofs.close();
}

void System::writeInFileEmployees(const MyString& fileName, const Employee& e)const
{
	std::ofstream ofs(fileName.c_str(), std::ios::out);

	ofs << e.getName() << " " << e.getPass() << std::endl;

	ofs.close();
}


bool searchInFile(const MyString& name, const MyString& pass, const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
	char currName[1024];
	char currPass[1024];
	ifs.getline(currName,1024,' ');
	ifs.getline(currPass,1024,'\n');
	if (name == currName && pass == currPass)
	{
		return true;
	}
	while (!ifs.eof())
	{
		ifs.getline(currName, ' ');
		ifs.getline(currPass, '\n');
		if (name == currName && pass == currPass)
		{
			return true;
		}
	}
	return false;

}
void System::login(const MyString& name, const MyString& password)
{
	if ((searchInFile(name, password, "Clients.txt")==false) && (searchInFile(name, password, "Employees.txt")==false) && (searchInFile(name, password, "ThirdPartyEmployees.txt")==false))
	{	
		throw std::invalid_argument("Invalid username or password");
	}
}

void System::signUp(const MyString& name, long egn, int age, const MyString& userType, const MyString& bankName, const MyString& password)
{
	UserFactory u;
	if (userType == "Client") 
	{
		Polymorphic_Ptr<User> userr(u.createClient(name, egn, age, password));
		users.pushBack(userr);
		writeInFile("Clients.txt", *userr);
		std::cout << "Client " << name.c_str() << " signed up." << std::endl;
	}
	else if (userType == "Employee")
	{
		if (bankName.getSize() == 0)
		{
			std::cout << "Bank name is required for Employee sign up." << std::endl;
			return;
		}
		Employee* emp(u.createEmployee(name, egn, age, bankName,password));
		users.pushBack(Polymorphic_Ptr<User>(emp));
		writeInFileEmployees("Employees.txt", *emp);
		for (size_t i = 0; i < banks.getSize(); ++i)
		{
			if (strcmp(banks[i].getName().c_str(),bankName.c_str())==0)
			{
				banks[i].addEmployee(*emp);
				std::cout << "Employee " << name.c_str() << " signed up for bank "<<i << banks[i].getName().c_str() << std::endl;
				return;
			}
		}
	}
	else if (userType == "Third-party employee")
	{
		Polymorphic_Ptr<User> userr(u.createThirdPartyEmployee(name, egn, age, password));
		users.pushBack(userr);
		writeInFile("ThirdPartyEmployees.txt", *userr);
		std::cout << "Third-party employeer " << name.c_str() << " signed up." << std::endl;
	}
}

void System::create_bank(const MyString& name)
{
	Bank b(name);
	banks.pushBack(b);
}

