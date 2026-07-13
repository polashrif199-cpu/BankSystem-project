#include "AdminManager.h"
#include "FileManager.h"
#include <iostream>
#include <vector>

using namespace std;

void AdminManager::printEmployeeMenu()
{
    cout << "\n========== Admin Menu ==========\n";
    cout << "1. Add Employee\n";
    cout << "2. Search Employee\n";
    cout << "3. List Employees\n";
    cout << "4. Edit Employee\n";
    cout << "5. Logout\n";
    cout << "Enter Choice: ";
}

Admin* AdminManager::login(int id, string password)
{
    static vector<Admin> admins;

    FileManager fm;
    admins = fm.getAllAdmins();

    for (int i = 0; i < admins.size(); i++)
    {
        if (admins[i].GetEmployeeId() == id &&
            admins[i].GetEmployeePassword() == password)
        {
            return &admins[i];
        }
    }

    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin)
{
    int choice;

    while (true)
    {
        printEmployeeMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, password;
            double salary;

            cout << "Enter Employee ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Employee Name: ";
            getline(cin, name);

            cout << "Enter Password: ";
            getline(cin, password);

            cout << "Enter Salary: ";
            cin >> salary;

            Employee employee(id, name, password, salary);

            admin->addEmployee(employee);

            cout << "\nEmployee Added Successfully.\n";
            break;
        }

        case 2:
        {
            int id;

            cout << "Enter Employee ID: ";
            cin >> id;

            Employee* employee = admin->searchEmployee(id);

            if (employee != nullptr)
            {
                employee->display();
            }
            else
            {
                cout << "Employee Not Found.\n";
            }

            break;
        }

        case 3:
        {
            admin->listEmployee();
            break;
        }

        case 4:
        {
            int id;
            string name, password;
            double salary;

            cout << "Enter Employee ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Password: ";
            getline(cin, password);

            cout << "Enter New Salary: ";
            cin >> salary;

            admin->editEmployee(id, name, password, salary);

            cout << "\nEmployee Updated Successfully.\n";
            break;
        }

        case 5:
        {
            cout << "\nLogged Out Successfully.\n";
            return false;
        }

        default:
        {
            cout << "Invalid Choice.\n";
            break;
        }
        }
    }
}