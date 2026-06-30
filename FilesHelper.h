
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;

class FilesHelper {
public:
    static void saveLast(const string& fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(const string& fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(const Client& c) {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << c.toString() << endl;
            file.close();
        }
        saveLast("lastClientID.txt", c.GetClientId());
    }

    static void saveEmployee(const string& fileName, const string& lastIdFile, const Employee& e) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.toString() << endl;
            file.close();
        }
        saveLast(lastIdFile, e.GetEmployeeId());
    }

    static void saveAdmin(const Admin& a)
    {
        ofstream file("Admins.txt", ios::app);

        if (file.is_open())
        {
            file << a.toString() << endl;
            file.close();
        }

        saveLast("LastAdminId.txt", a.GetEmployeeId());
    }

    static vector<Client> getClients() {
        vector<Client> clients;
        ifstream file("Clients.txt");
        string line;
        while (getline(file, line)) {
           clients.push_back(Parser::parseToClient(line));
        }
        file.close();
        return clients;
    }

    static vector<Employee> getEmployees() {
        vector<Employee> employees;
        ifstream file("Employees.txt");
        string line;
        while (getline(file, line)) {
            employees.push_back(Parser::parseToEmployee(line));
        }
        file.close();
        return employees;
    }

    static vector<Admin> getAdmins() {
        vector<Admin> admins;
        ifstream file("Admins.txt");
        string line;
        while (getline(file, line)) {
            admins. push_back(Parser::parseToAdmin(line));
        }
        file.close();
        return admins;
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};