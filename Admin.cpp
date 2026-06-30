#include "Admin.h"
#include "FileManager.h"
#include <vector>
#include <iostream>

using namespace std;

Admin::Admin() : Employee()
{
}

Admin::Admin(int id, string name, string password, double salary)
    : Employee(id, name, password, salary)
{
}

void Admin::addEmployee(Employee& employee)
{
    FileManager fm;
    fm.addEmployee(employee);
}

Employee* Admin::searchEmployee(int id)
{
    static vector<Employee> employees;

    FileManager fm;
    employees = fm.getAllEmployees();

    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].GetEmployeeId() == id)
        {
            return &employees[i];
        }
    }

    return nullptr;
}

void Admin::editEmployee(int id, string name, string password, double salary)
{
    FileManager fm;

    vector<Employee> employees = fm.getAllEmployees();

    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].GetEmployeeId() == id)
        {
            employees[i].SetEmployeeName(name);
            employees[i].SetEmployeePassword(password);
            employees[i].SetEmployeeSalary(salary);
            break;
        }
    }

    fm.removeAllEmploye();

    for (int i = 0; i < employees.size(); i++)
    {
        fm.addEmployee(employees[i]);
    }
}

void Admin::listEmployee()
{
    FileManager fm;

    vector<Employee> employees = fm.getAllEmployees();

    for (int i = 0; i < employees.size(); i++)
    {
        employees[i].display();
    }
}

void Admin::display()
{
    cout << "\n===== Admin =====\n";
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Salary: " << salary << endl;
}