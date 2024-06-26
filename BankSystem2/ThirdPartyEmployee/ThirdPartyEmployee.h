#pragma once
#include "../User/User.h"
//#include "../System/System.h"

class ThirdPartyEmployee:public User
{
public:
	ThirdPartyEmployee() = default;
	ThirdPartyEmployee(const MyString& name, long egn, int age, const MyString& passw) :User(name, egn, age, passw) {};
	void send_check(unsigned long sum, const MyString& verification_code, unsigned long egn)const;
	 User* clone() const override;
	 virtual void help()const override;
	 virtual void whoami() const override;
};

