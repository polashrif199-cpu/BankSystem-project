#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    int id;
    string name;
    string password;

public:
    Person();
    Person(int id, string name, string password);

    void setName(string name);
    void setPassword(string password);

    string getName();
    int getId();
    string getPassword();

    virtual void display();
};