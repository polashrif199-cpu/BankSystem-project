
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"
#include "Employee.h"
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
    }

    static void saveEmployee(const string& fileName, const string& lastIdFile, const Employee& e) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.toString() << endl;
            file.close();
        }
        saveLast(lastIdFile, e.getId());
    }

    static void getClients() {
        ifstream file("Clients.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    static void getEmployees() {
        ifstream file("Employees.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    static void getAdmins() {
        ifstream file("Admins.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
