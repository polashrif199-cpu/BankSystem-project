#include "EmployeeManager.h"

void EmployeeManager::printEmployeeMenu() {
    cout << "\n===== Employee Menu =====\n";
    cout << "1. Add New Client\n";
    cout << "2. List All Clients\n";
    cout << "3. Search for Client\n";
    cout << "4. Edit Client Info\n";
    cout << "5. Logout\n";
}

void EmployeeManager::newClient(Employee* employee) {
    cout << "Adding new client for employee: " << employee->name << endl;
}

void EmployeeManager::listAllClients(Employee* employee) {
    cout << "Listing all clients for employee: " << employee->name << endl;
}

void EmployeeManager::searchForClient(Employee* employee) {
    cout << "Searching for client under employee: " << employee->name << endl;
}

void EmployeeManager::editClientInfo(Employee* employee) {
    cout << "Editing client info for employee: " << employee->name << endl;
}

Employee* EmployeeManager::login(int id, string password) {
    cout << "Attempting login for ID: " << id << endl;

    Employee* emp = new Employee();
    emp->id = id;
    emp->password = password;
    emp->name = "John Doe";
    cout << "Login successful!\n";
    return emp;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
    printEmployeeMenu();

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: newClient(employee); break;
    case 2: listAllClients(employee); break;
    case 3: searchForClient(employee); break;
    case 4: editClientInfo(employee); break;
    case 5: cout << "Logging out...\n"; return false;
    default: cout << "Invalid choice!\n"; break;
    }

    return true;
}