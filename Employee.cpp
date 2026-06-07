#include "Employee.h"
#include<string>

Employee::Employee() : Person(), salary(5000) {}

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password) {

    this->salary = (salary >= 5000) ? salary : 5000;
}


void Employee::SetEmployeeName(string name) {
    setName(name) ;
}
void Employee::SetEmployeePassword(string password) {
    setPassword( password ) ;
}
void Employee::SetEmployeeSalary(double salary) {
    this->salary = (salary >= 5000) ? salary : 5000;
}


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

bool Employee::login(int id, string password) {
    return (this->id == id && this->password == password);
}


void Employee::addClient(const Client& c) {
    clients.push_back(c);
}


Client* Employee::searchClient(int cid) {
    for (auto& c : clients) {
        if (c.GetClientId() == cid) return &c;
    }

    return nullptr;
}


void Employee::listClients() {
    for (auto& c : clients) {
        c.display();
        cout << "-------------------\n";
    }
}


void Employee::editClient(int cid, string name, string password, double balance) {
    Client* c = searchClient(cid);
    if (c) {
        c->SetClientName(name);
        c->SetClientPassword(password);
        c->SetClientBalance(balance);
    }
}


void Employee::raiseSalary(double percent) {
    if (percent > 0) salary += salary * (percent / 100.0);
}


void Employee::display() {
    cout << "Employee ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Clients managed: " << clients.size() << endl << endl;
}
