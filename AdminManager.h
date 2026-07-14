#pragma once

#include "Admin.h"

class AdminManager
{
public:
    static void printEmployeeMenu();
    static Admin* login(int id, string password);
    static bool AdminOptions(Admin* admin);
};