#pragma once

#include <iostream>
#include <vector>
#include "Client.h"
#include "Person.h"
#include "FileManager.h"

using namespace std;

class ClientManager
{
public:

    static void printClientMenu();

    static void updatePassword(Person* person);

    static Client* login(int id, string password);

    static bool clientOptions(Client* client);
};