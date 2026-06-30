#include <iostream>
#include "FileManager.h"
#include "Admin.h"
#include "Employee.h"
#include "Client.h"

using namespace std;

int main()
{
    FileManager fm;

    // تنظيف الملفات
    fm.removeAllClients();
    fm.removeAllEmploye();
    fm.removeAllAdmins();

    // إنشاء Objects
    Client c1(1, "Ali", "1111", 5000);
    Client c2(2, "Ahmed", "2222", 7000);

    Employee e1(101, "Mona", "1234", 6000);
    Employee e2(102, "Sara", "5678", 6500);

    Admin a1(201, "Boss", "9999", 15000);

    // حفظ البيانات
    fm.addClient(c1);
    fm.addClient(c2);

    fm.addEmployee(e1);
    fm.addEmployee(e2);

    fm.addAdmin(a1);

    cout << "========== Clients ==========\n";

    vector<Client> clients = fm.getAllClients();

    for (int i = 0; i < clients.size(); i++)
    {
        clients[i].display();
    }

    cout << "\n========== Employees ==========\n";

    vector<Employee> employees = fm.getAllEmployees();

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i].display();
    }

    cout << "\n========== Admins ==========\n";

    vector<Admin> admins = fm.getAllAdmins();

    for (int i = 0; i < admins.size(); i++)
    {
        admins[i].display();
    }

    cout << "\n========== Admin Functions ==========\n";

    Admin admin(500, "SystemAdmin", "0000", 20000);

    Employee e3(103, "Omar", "3333", 8000);

    admin.addEmployee(e3);

    cout << "\nAfter addEmployee():\n";
    admin.listEmployee();

    Employee* emp = admin.searchEmployee(103);

    if (emp)
    {
        cout << "\nEmployee Found:\n";
        emp->display();
    }
    else
    {
        cout << "\nEmployee Not Found\n";
    }

    admin.editEmployee(103, "Omar Ali", "8888", 9000);

    cout << "\nAfter editEmployee():\n";
    admin.listEmployee();

    return 0;
}