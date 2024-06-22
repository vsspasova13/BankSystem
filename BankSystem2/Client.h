#pragma once
#include "User.h"

class BankAccount;

struct Check
{
	MyString code;
	unsigned long sum=0;
};

struct Account
{
public:
	MyString bank_name;
	long acc_number=0;
	long balance=0;
	Account()=default;
	Account(const MyString& n, long num, long bal) :bank_name(n), acc_number(num), balance(bal) {};
};

struct Message
{
	MyString content;
};

class Client :public User
{
private:
	Vector<Account> accounts;
	Vector<Message> mess;
	Vector<Check> checks;	

public:
	unsigned long check_avl(const MyString& bankName, unsigned long accNumber)const;
	void open(const MyString& bankName);
	void close(const MyString& bankName, unsigned long accNumber)const;
	void redeem(const MyString& bankName, unsigned long accNumber, const MyString& code);
	void change(const MyString& newBankName, const MyString& currBankName, unsigned long accNumber);
	void list(const MyString& bankName)const;
	void messages()const;
	void addAccount(const MyString& bankName, unsigned long accNumber);
	void removeAccount(const MyString& bankName, unsigned long accNumber);	

};


