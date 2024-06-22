#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Bank.h"
#include "System.h"

int main()
{   
    Employee e;
    System s;
    Client c1;
    
    s.create_bank("ABC");
    c1.open("ABC");
    e.approve(1);
    
    
}
