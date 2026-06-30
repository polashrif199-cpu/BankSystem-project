#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser
{
public:

    static vector<string> split(const string& line)
    {
        vector<string> data;
        string word;

        stringstream ss(line);

        while (getline(ss, word, '&'))
        {
            data.push_back(word);
        }

        return data;
    }

    static Client parseToClient(const string& line)
    {
        vector<string> data = split(line);

        return Client(
            stoi(data[0]),
            data[1],
            data[2],
            stod(data[3])
        );
    }

    static Employee parseToEmployee(const string& line)
    {
        vector<string> data = split(line);

        return Employee(
            stoi(data[0]),
            data[1],
            data[2],
            stod(data[3])
        );
    }

    static Admin parseToAdmin(const string& line)
    {
        vector<string> data = split(line);

        return Admin(
            stoi(data[0]),
            data[1],
            data[2],
            stod(data[3])
        );
    }
};