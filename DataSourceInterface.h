#pragma once

#include<vector>
#include"Admin.h"
#include"Employee.h"
#include"Client.h"

class DataSourceInterface
{
public:
	virtual void addClient(const Client& c1) = 0;
	virtual void addEmployee(const Employee& e1) = 0;
	virtual void addAdmin(const Admin& a1) = 0;

	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployees() = 0;
	virtual vector<Admin> getAllAdmins() = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmploye() = 0;
	virtual void removeAllAdmins() = 0;
};