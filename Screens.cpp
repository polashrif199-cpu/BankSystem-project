#include "Screens.h"
#include "Screens.h"

void Screens::bankName()
{
	cout << "\n";
	cout << "=========================================\n";
	cout << "            BANK MANAGEMENT SYSTEM\n";
	cout << "=========================================\n";
}

void Screens::welcome()
{
	bankName();

	cout << "\n";
	cout << "Welcome To Our Bank.\n";
	cout << "Please Login To Continue.\n\n";
}

void Screens::loginOptions()
{
	cout << "============== LOGIN MENU ==============\n";
	cout << "1 - Client\n";
	cout << "2 - Employee\n";
	cout << "3 - Admin\n";
	cout << "4 - Exit\n";
	cout << "========================================\n";
}

int Screens::loginAs()
{
	int choice;

	cout << "\nEnter Your Choice : ";
	cin >> choice;

	return choice;
}

void Screens::invalid(int choice)
{
	cout << "\n----------------------------------------\n";
	cout << "Invalid Choice (" << choice << ")\n";
	cout << "Please Try Again.\n";
	cout << "----------------------------------------\n";
}

void Screens::logout()
{
	cout << "\n";
	cout << "========================================\n";
	cout << "Logged Out Successfully.\n";
	cout << "========================================\n";
}
void Screens::loginScreen(int choice)
{
	int id;
	string password;

	cout << "\nEnter ID : ";
	cin >> id;

	cout << "Enter Password : ";
	cin >> password;

	switch (choice)
	{
	case 1:
	{
		Client* client = ClientManager::login(id, password);

		if (client != nullptr)
		{
			cout << "\nLogin Successfully.\n";

			while (ClientManager::clientOptions(client));

			logout();
		}
		else
		{
			cout << "\nWrong ID Or Password.\n";
		}

		break;
	}

	case 2:
	{
		Employee* employee = EmployeeManager::login(id, password);

		if (employee != nullptr)
		{
			cout << "\nLogin Successfully.\n";

			while (EmployeeManager::employeeOptions(employee));

			logout();
		}
		else
		{
			cout << "\nWrong ID Or Password.\n";
		}

		break;
	}

	case 3:
	{
		Admin* admin = AdminManager::login(id, password);

		if (admin != nullptr)
		{
			cout << "\nLogin Successfully.\n";

			while (AdminManager::AdminOptions(admin));

			logout();
		}
		else
		{
			cout << "\nWrong ID Or Password.\n";
		}

		break;
	}

	default:
		invalid(choice);
	}
}
void Screens::runApp()
{
	while (true)
	{
		welcome();

		loginOptions();

		int choice = loginAs();

		if (choice == 4)
		{
			cout << "\n========================================\n";
			cout << "Thank You For Using Bank System.\n";
			cout << "Good Bye.\n";
			cout << "========================================\n";
			break;
		}

		if (choice >= 1 && choice <= 3)
		{
			loginScreen(choice);
		}
		else
		{
			invalid(choice);
		}

		cout << "\nPress Enter To Continue...";
		cin.ignore();
		cin.get();

		system("cls");
	}
}