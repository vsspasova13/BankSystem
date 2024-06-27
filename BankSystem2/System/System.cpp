#include "System.h"
System& s = System::getInstance();

void System::writeInFile(const MyString& fileName, const User& u)const
{
	std::ofstream ofs(fileName.c_str(), std::ios::out | std::ios::app);
	if (!ofs.is_open())
		throw std::exception("Error while opening the file.");
	ofs << u.getName() << " " << u.getPass() << std::endl;

	ofs.close();
}

bool System::ValidateUser(const MyString& name, const MyString& pass,const MyString& role, int& index)
{
	index = -1;
	if (strcmp(role.c_str(),"Client")==0)
	{
		for (size_t i = 0; i < clients.getSize(); i++)
		{
			if (strcmp(clients[i]->getName(), name.c_str())==0 && strcmp(clients[i]->getPass(), pass.c_str())==0)
			{
				index = i;
				return true;
			}
		}
	}
	if (role == "Employee")
	{
		for (size_t i = 0; i < employees.getSize(); i++)
		{
			if (strcmp(employees[i]->getName(), name.c_str())==0 && strcmp(employees[i]->getPass(), pass.c_str())==0)
			{
				index = i;
				return true;
				
			}
		}
	}
	if (role == "ThirdPartyEmployee")
	{
		for (size_t i = 0; i < ThirdPEmp.getSize(); i++)
		{
			if (strcmp(ThirdPEmp[i]->getName(), name.c_str())==0 && strcmp(ThirdPEmp[i]->getPass(), pass.c_str())==0)
			{
				index = i;
				return true;
			}
		}
	}
	return false;
	/*for (size_t i = 0; i < users.getSize(); i++)
	{

		if (strcmp(users[i]->getName(), name.c_str()) && strcmp(users[i]->getPass(), pass.c_str()))
		{
			index = i;
			break;
		}
	}*/
}
bool searchInFile(const MyString& name, const MyString& pass, const MyString& fileName)
{
	std::ifstream ifs(fileName.c_str());
		if (!ifs.is_open())
			throw std::exception("Error while opening the file.");
		if (ifs.eof())
			return false;
	char currName[1024];
	char currPass[1024];

	do
	{
		ifs >> currName >> currPass;
		if (strcmp(name.c_str(), currName) == 0 && strcmp(pass.c_str(), currPass) == 0)
		{
			return true;
		}
	} while (!ifs.eof());

	return false;

}
//const MyString& System::getUserType(const Polymorphic_Ptr<User> u) const
//{
//	if ((searchInFile(u->getName(), u->getPass(), "Clients.txt") == true))
//	{
//		return "Client";
//	}
//	if ((searchInFile(u->getName(), u->getPass(), "Employees.txt") == true))
//	{
//		return "Employee";
//	}
//	if ((searchInFile(u->getName(), u->getPass(), "ThirdPartyEmployees.txt") == true))
//	{
//		return "ThirdPartyEmployee";
//	}
//}
MyString System::getUserType(const MyString& name, const MyString& password) const
{
	
	if ((searchInFile(name, password, "Clients.txt") == true))
	{
		return MyString("Client");
	}
	if ((searchInFile(name, password, "Employees.txt") == true))
	{
		return MyString("Employee");
	}
	if ((searchInFile(name, password, "ThirdPartyEmployees.txt") == true))
	{
		return MyString("ThirdPartyEmployee");
	}
	return MyString("Unknown");
}


void System::exitCmd()
{
	currClient = nullptr;
	currEmp = nullptr;
	currThirdPartyEmp = nullptr;
}

bool System::isSomeoneLogged() const
{
	return (currClient != nullptr || currEmp != nullptr || currThirdPartyEmp != nullptr);
}

void System::login(const MyString& name, const MyString& password)
{
	
	int ind;
	
	MyString role = s.getUserType(name,password);
	if(strcmp(role.c_str(),"Unknown")==0) std::cout << "No such User!";
	//if (!ValidateUser(name, password,role,ind))
	ValidateUser(name, password, role, ind);
	if (strcmp(role.c_str(), "Client") == 0)
	{
		currClient = clients[ind];
	}
		
	else if (strcmp(role.c_str(), "Employee") == 0)
	{
		 currEmp = employees[ind];
	}
		
	else if (strcmp(role.c_str(), "ThirdPartyEmployee") == 0)
	{
		currThirdPartyEmp = ThirdPEmp[ind];
	}

}

void System::signUp(const MyString& name, long egn, int age, const MyString& userType, const MyString& bankName, const MyString& password)
{

	UserFactory u;

	if (userType == "Client")
	{
		Client* cl(u.createClient(name, egn, age, password));
		Polymorphic_Ptr<User> userr(u.createClient(name, egn, age, password));
		users.pushBack(userr);
		clients.pushBack(cl);
		writeInFile("Clients.txt", *cl);
		//writeInFile("Clients.txt", *userr);
		std::cout << "Client " << name.c_str() << " signed up." << std::endl;
	}
	else if (userType == "Employee")
	{
		if (bankName.getSize() == 0)
		{
			std::cout << "Bank name is required for Employee sign up." << std::endl;
			return;
		}

		Employee* emp(u.createEmployee(name, egn, age, bankName, password));
		employees.pushBack(emp);
		users.pushBack(Polymorphic_Ptr<User>(emp));
		writeInFile("Employees.txt", *emp);
		int i = s.findBankIndByName(bankName);
		banks[i].addEmployee(emp);
		std::cout << "Employee " << name.c_str() << " signed up for bank "<<i << banks[i].getName().c_str() << std::endl;
		/*for (size_t i = 0; i < s.banks.getSize(); ++i)
		{
			if (strcmp(s.banks[i].getName().c_str(), bankName.c_str()) == 0)
			{
				s.banks[i].addEmployee(emp);
				
				return;
			}
		}*/
	}
	else if (userType == "Third-party employee")
	{
		ThirdPartyEmployee* t(u.createThirdPartyEmployee(name, egn, age, password));
		ThirdPEmp.pushBack(t);
		Polymorphic_Ptr<User> userr(u.createThirdPartyEmployee(name, egn, age, password));
		users.pushBack(userr);
		writeInFile("ThirdPartyEmployees.txt", *t);
		std::cout << "Third-party employeer " << name.c_str() << " signed up." << std::endl;
	}
}

void System::create_bank(const MyString& name)
{
	Bank b(name);
	s.banks.pushBack(b);
}

