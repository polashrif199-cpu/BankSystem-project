#pragma once
#include"Person.h"
#include <string>

class Client : public Person
{
private:
	double balance;

public:
	Client() ;

	Client(int id, string name, string password, double balance) ;

	
	//setters
	void SetClientName(string name);
	
	void SetClientPassword(string password);
	
	void SetClientBalance(double balance);

	//getters
	int GetClientId()const;
	
	string GetClientName();
	
	string GetClientPassword();
	
	double getClientBalance();
	
	//tostring
	string toString() const
	{
		return to_string(id) + "&" +
			name + "&" +
			password + "&" +
			to_string(balance);
	}

	//deposit, withdraw, transfer, check balance
	void deposit(double amount);

	void withdraw(double amount);

	void transferTo(Client& recipient, double amount);

	void chickBalance();

	//display
	void display() override;
};

