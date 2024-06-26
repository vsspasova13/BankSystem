#include "SignUpCmd.h"

SignUpCmd::SignUpCmd(const MyString& name, long egn, int age, const MyString& userType, const MyString& bankName, const MyString& password)
{
	this->name = name;
	this->age = age;
	this->egn = egn;
	this->role = userType;
	this->bank = bankName;
	this->passw = password;
}

void SignUpCmd::execute()
{
	s.signUp(name,egn,age,role,bank,passw);
}
