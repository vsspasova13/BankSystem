#pragma once
#include "..\User\User.h"
//#include "..\System\System.h"
#include "../Utils/MyString.h"
#include "../Utils/Polymorphic_Ptr.hpp"
#include "../Utils/Vector.hpp"

class User;

struct Check
{
	MyString code="";
	unsigned long sum=0;
};

struct Account
{
public:
	MyString bank_name="";
	long acc_number=0;
	long balance=0;
	Account()=default;
	Account(const MyString& n, long num, long bal) :bank_name(n), acc_number(num), balance(bal) {};
	long getAccNum()const
	{
		return acc_number;
	}
};

struct Message
{
	int id;
	MyString content="";
	Message()=default;
	Message(int id, const MyString& cnt) :id(id), content(cnt) {};
};

class Client :public User
{
	
private:
	Vector<Account> accounts;
	Vector<Message> mess;
	Vector<Check> checks;	

public:
	Client();
	Client(const MyString& name, long egn, int age, const MyString& passw) :User(name, egn, age, passw){};
	unsigned long check_avl(const MyString& bankName, unsigned long accNumber)const;

	Client(const Client& other)
	{
		this->accounts = other.accounts;
		this->checks = other.checks;
		this->mess = other.mess;
	}
	void open(const MyString& bankName);
	void close(const MyString& bankName, unsigned long accNumber)const;
	void redeem(const MyString& bankName, unsigned long accNumber, const MyString& code);
	void change(const MyString& newBankName, const MyString& currBankName, unsigned long accNumber);
	void list(const MyString& bankName)const;
	void messages()const;

	virtual User* clone() const override;
	void addAccount(const MyString& bankName, unsigned long accNumber);
	void removeAccount(const MyString& bankName, unsigned long accNumber);	
	void addMessage(const MyString& mes);
	Vector<Account> getAccount()const
	{
		return accounts;
	}
	virtual void help()const override;
	virtual void whoami() const override;

};


