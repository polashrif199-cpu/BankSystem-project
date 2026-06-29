#include "Employee.h"
#include <string>
#include <fstream>

Employee::Employee() : Person(), salary(5000) {}

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password) {

    this->salary = (salary >= 5000) ? salary : 5000;
}

// Setters
void Employee::SetEmployeeName(string name) {
    setName(name);
}

void Employee::SetEmployeePassword(string password) {
    setPassword(password);
}

void Employee::SetEmployeeSalary(double salary) {
    this->salary = (salary >= 5000) ? salary : 5000;
}

// Getters
int Employee::GetEmployeeId() {
    return id;
}

string Employee::GetEmployeeName() {
    return name;
}

string Employee::GetEmployeePassword() {
    return password;
}

double Employee::GetEmployeeSalary() {
    return salary;
}

// Login
bool Employee::login(int id, string password) {
    return (this->id == id && this->password == password);
}

// Add Client + Save to file
void Employee::addClient(const Client& c) {
    clients.push_back(c);

    ofstream out("clients.txt", ios::app);
    out << c.GetClientId() << "&"
        << c.GetClientName() << "&"
        << c.GetClientPassword() << "&"
        << c.getClientBalance() << endl;

    out.close();
}

// Search Client
Client* Employee::searchClient(int cid) {
    for (auto& c : clients) {
        if (c.GetClientId() == cid) {
            return &c;
        }
    }
    return nullptr;
}

// List Clients from file
void Employee::listClient() {
    ifstream in("clients.txt");
    string line;

    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();
}

// Edit Client + Rewrite file
void Employee::editClient(int cid, string name, string password, double balance) {
    Client* c = searchClient(cid);

    if (c) {
        c->SetClientName(name);
        c->SetClientPassword(password);
        c->SetClientBalance(balance);

        ofstream out("clients.txt");

        for (auto& client : clients) {
            out << client.GetClientId() << "&"
                << client.GetClientName() << "&"
                << client.GetClientPassword() << "&"
                << client.getClientBalance() << endl;
        }

        out.close();
    }
}

// Raise Salary
void Employee::raiseSalary(double percent) {
    if (percent > 0) {
        salary += salary * (percent / 100.0);
    }
}

// Display Employee Data
void Employee::display() {
    cout << "Employee ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Clients managed: " << clients.size() << endl << endl;
}