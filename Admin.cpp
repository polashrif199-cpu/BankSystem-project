#include "Admin.h"
#include <string>
Admin ::Admin() : Employee()
{
}

Admin::Admin(int id, string name, string password, double salary)
    : Employee(id, name, password, salary)
{
}

void Admin::display()
{
    cout << "\n===== Admin =====\n";
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Salary: " << salary << endl;
}
