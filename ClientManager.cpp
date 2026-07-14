#include "ClientManager.h"

void ClientManager::printClientMenu()
{
    cout << "\n========== Client Menu ==========\n";
    cout << "1- Check Balance\n";
    cout << "2- Deposit\n";
    cout << "3- Withdraw\n";
    cout << "4- Transfer\n";
    cout << "5- Change Password\n";
    cout << "6- Logout\n";
    cout << "Choose: ";
}

void ClientManager::updatePassword(Person* person)
{
    string pass;

    cout << "Enter New Password: ";
    cin >> pass;

    person->setPassword(pass);

    cout << "\nPassword Updated Successfully.\n";
}

Client* ClientManager::login(int id, string password)
{
    static vector<Client> clients;

    FileManager fm;

    clients = fm.getAllClients();

    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].GetClientId() == id &&
            clients[i].GetClientPassword() == password)
        {
            return &clients[i];
        }
    }

    return nullptr;
}

bool ClientManager::clientOptions(Client* client)
{
    int choice;

    do
    {
        printClientMenu();

        cin >> choice;

        switch (choice)
        {
        case 1:
            client->chickBalance();
            break;

        case 2:
        {
            double amount;

            cout << "Amount: ";
            cin >> amount;

            client->deposit(amount);

            break;
        }

        case 3:
        {
            double amount;

            cout << "Amount: ";
            cin >> amount;

            client->withdraw(amount);

            break;
        }

        case 4:
        {
            int id;
            double amount;

            cout << "Recipient ID: ";
            cin >> id;

            cout << "Amount: ";
            cin >> amount;

            FileManager fm;

            vector<Client> clients = fm.getAllClients();

            bool found = false;

            for (int i = 0; i < clients.size(); i++)
            {
                if (clients[i].GetClientId() == id)
                {
                    client->transferTo(clients[i], amount);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Client Not Found.\n";

            break;
        }

        case 5:
            updatePassword(client);
            break;

        case 6:
            cout << "\nLogged Out Successfully.\n";
            return true;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (true);
}