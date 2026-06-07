#include"Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

int main()
{
    Client c1(1, "Mohammed", "password123", 5000);
    Client c2(2, "Abdelrahman", "mypassword", 3000);

    c1.display();
    c2.display();

    c1.deposit(1000);
    c1.withdraw(500);
    c1.transferTo( c2 ,1000);

    c1.chickBalance();
    c2.chickBalance();

    Employee e1(101, "Abdallah", "employee123", 7000);
    e1.display();
    Employee e2(102, "Rana", "employee456", 7000);
    e2.display();

    Admin a1(201, "pola", "admin12345", 15000);
    a1.display();


}
