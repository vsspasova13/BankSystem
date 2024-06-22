#pragma once
#include "User.h"

class ThirdPartyEmployee:public User
{
public:
	void send_check(unsigned long sum, const MyString& verification_code, unsigned long egn)const;

};

