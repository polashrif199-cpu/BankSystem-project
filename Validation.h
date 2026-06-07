#pragma once
#include <string>

using namespace std;

class Validation
{
public:
    static bool isValidName(string name);
    static bool isValidPassword(string password);
};