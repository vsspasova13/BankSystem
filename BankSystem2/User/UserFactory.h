#pragma once
#include "../Client/Client.h"
#include "../Employee/Employee.h"
#include "../ThirdPartyEmployee/ThirdPartyEmployee.h"
class UserFactory
{
public:
     Client* createClient(const MyString& name, long egn, int age, const MyString& passw) {
        return new Client(name, egn, age, passw);
    }

     Employee* createEmployee(const MyString& name, long egn, int age, const MyString& bankName, const MyString& passw) {
        return new Employee(name,egn, age, passw, bankName);
    }
     ThirdPartyEmployee* createThirdPartyEmployee(const MyString& name, long egn, int age, const MyString& passw)
     {
         return new ThirdPartyEmployee(name, egn, age, passw);
     }
};

