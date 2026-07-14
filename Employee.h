#pragma once
#include "Person.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Employee : public Person
{
protected:
    double salary;
    vector<Client> clients;

public:
    // Constructors
    Employee();
    Employee(int id, string name, string password, double salary);

    // Setters
    void SetEmployeeName(string name);
    void SetEmployeePassword(string password);
    void SetEmployeeSalary(double salary);

    // Getters
    int GetEmployeeId();
    string GetEmployeeName();
    string GetEmployeePassword();
    double GetEmployeeSalary();

    // Login
    bool login(int id, string password);

    // Employee Functions (Phase 2)
    void addClient(const Client& c);
    Client* searchClient(int cid);
    void listClient();
    void editClient(int cid, string name, string password, double balance);

    // Salary
    void raiseSalary(double percent);

    // Display
    void display() override;
};