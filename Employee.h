#pragma once
#include "Person.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Employee : public Person
{
protected:
    double salary;
    vector<Client> clients;

public:
    Employee();
    Employee(int id, string name, string password, double salary);

    void SetEmployeeName(string name);
    void SetEmployeePassword(string password);
    void SetEmployeeSalary(double salary);

    int GetEmployeeId();
    string GetEmployeeName();
    string GetEmployeePassword();
    double GetEmployeeSalary();

    bool login(int id, string password);

    void addClient(const Client& c);
    Client* searchClient(int cid);
    void listClients();
    void editClient(int cid, string name, string password, double balance);

    void raiseSalary(double percent);

    void display() override;
};