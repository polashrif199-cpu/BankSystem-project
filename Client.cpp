#include "Client.h"
#include<iostream>
#include<string>
using namespace std;

Client:: Client()
{
	balance = 1500 ;
}

Client::Client(int id, string name, string password, double balance) : Person(id, name, password)
{
	SetClientBalance(balance);
}

//setters
void Client::SetClientName(string name)
{
	setName(name);
}

void Client::SetClientPassword(string password)
{
	setPassword(password);
}

void Client::SetClientBalance(double balance)
{
	if (balance >= 1500)
	{
		this->balance = balance;
	}
	else
	{
		this->balance = 1500;
	}

}

//getters
int Client::GetClientId()const 
{
	return id;
}

string Client::GetClientName()
{
	return getName();
}

string Client::GetClientPassword()
{
	return getPassword();
}

double Client::getClientBalance()
{
	return balance; 
}
//deposet
void Client::deposit(double amount)
{
	if (amount > 0)
	{
		balance += amount;
		cout << "Deposit successful.\n New balance: " << balance <<"\t\n" << endl;
	}
}

//withdraw
void Client::withdraw(double amount)
{
	if (amount > 0 && balance >= amount)
	{
		balance -= amount;
		cout << "Withdrawal successful.\n New balance: " << balance << "\t\n" << endl;
	}
	else
	{
		cout << "Withdrawal failed." << endl;
	}
} 

//transfer
void Client::transferTo(Client& recipient, double amount)
{
	if (amount > 0 && balance >= amount)
	{
		balance -= amount;
		recipient.balance += amount;
		cout << "Transfer successful.\n New balance: " << balance << "\t\n"<< endl;
	}
	else
	{
		cout << "Transfer failed." << endl;
	}
}

//check balance
void Client::chickBalance()
{
	cout << "Current balance: " << balance <<"\t\n"<< endl;
}

//display
void Client::display()
{
	
	cout << "Client Information:" << endl;
	cout << "Client ID: " << id << endl;
	cout << "Client Name: " << name << endl;
	cout << "Client Balance: " << balance << endl;
	cout << "==================================" << endl;
}