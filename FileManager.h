#pragma once

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    // Add
    void addClient(const Client& c1) override
    {
        FilesHelper::saveClient(c1);
    }

    void addEmployee(const Employee& e1) override
    {
        FilesHelper::saveEmployee(
            "Employees.txt",
            "LastEmployeeId.txt",
            e1
        );
    }

    void addAdmin(const Admin& a1) override
    {
        FilesHelper::saveAdmin(a1);
    }

    // Get
    vector<Client> getAllClients() override
    {
        return FilesHelper::getClients();
    }

    vector<Employee> getAllEmployees() override
    {
        return FilesHelper::getEmployees();
    }

    vector<Admin> getAllAdmins() override
    {
        return FilesHelper::getAdmins();
    }

    // Remove
    void removeAllClients() override
    {
        FilesHelper::clearFile(
            "Clients.txt",
            "LastClientId.txt"
        );
    }

    void removeAllEmploye() override
    {
        FilesHelper::clearFile(
            "Employees.txt",
            "LastEmployeeId.txt"
        );
    }

    void removeAllAdmins() override
    {
        FilesHelper::clearFile(
            "Admins.txt",
            "LastAdminId.txt"
        );
    }
};