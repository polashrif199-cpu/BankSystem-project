#include "Person.h"
#include "Validation.h"
#include <iostream>
#include<string>

Person::Person()
{
    id = 0;
    name = "";
    password = "";
}

Person::Person(int id, string name, string password)
{
    this->id = id;
    setName(name);
    setPassword(password);
}

void Person::setName(string name)
{
    if (Validation::isValidName(name))
        this->name = name;
    else
        this->name = "Unknown";
}

void Person::setPassword(string password)
{
    if (Validation::isValidPassword(password))
        this->password = password;
    else
        this->password = "00000000";
}

string Person::getName()
{
    return name;
}

int Person::getId()
{
    return id;
}

string Person::getPassword()
{
    return password;
}

void Person::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}