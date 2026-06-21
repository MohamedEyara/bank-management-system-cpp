#include "ClientManager.h"
#include <iostream>
#include <vector>
using namespace std;

void ClientManager::printClientMenu() {
    cout << "\n  ===== Client Menu =====\n"
         << "  1. Deposit\n"
         << "  2. Withdraw\n"
         << "  3. Transfer\n"
         << "  4. Check Balance\n"
         << "  5. Change Password\n"
         << "  6. Display Info\n"
         << "  0. Logout\n"
         << "  ========================\n"
         << "  Choice: ";
}

void ClientManager::updatePassword(Client* client) {
    string newPass;
    cout << "  New password: ";
    cin >> newPass;
    if (client->setPassword(newPass)) {
        vector<Client> clients = FilesHelper::getClients();
        for (auto& c : clients)
            if (c.getId() == client->getId()) { c.setPassword(newPass); break; }
        FilesHelper::rewriteClients(clients);
        cout << "  Password updated.\n";
    }
}

Client* ClientManager::login(int id, const string& password) {
    static vector<Client> clients;
    clients = FilesHelper::getClients();
    for (auto& c : clients)
        if (c.getId() == id && c.getPassword() == password) return &c;
    return nullptr;
}

bool ClientManager::clientOptions(Client* client) {
    int choice;
    printClientMenu();
    cin >> choice;

    switch (choice) {
        case 1: {
            double amount;
            cout << "  Deposit amount: "; cin >> amount;
            client->deposit(amount);
            updateClientFile(client); break;
        }
        case 2: {
            double amount;
            cout << "  Withdraw amount: "; cin >> amount;
            client->withdraw(amount);
            updateClientFile(client); break;
        }
        case 3: {
            int recipientId; double amount;
            cout << "  Recipient ID: "; cin >> recipientId;
            vector<Client> clients = FilesHelper::getClients();
            Client* recipient = nullptr;
            for (auto& c : clients)
                if (c.getId() == recipientId) { recipient = &c; break; }
            if (!recipient) { cout << "  Recipient not found.\n"; break; }
            cout << "  Transfer amount: "; cin >> amount;
            client->transferTo(amount, *recipient);
            FilesHelper::rewriteClients(clients); break;
        }
        case 4: client->checkBalance(); break;
        case 5: updatePassword(client); break;
        case 6: client->display();      break;
        case 0:
            cout << "  Logging out...\n";
            return false;
        default:
            cout << "  Invalid option.\n";
    }
    return true;
}

void ClientManager::updateClientFile(Client* client) {
    vector<Client> clients = FilesHelper::getClients();
    for (auto& c : clients)
        if (c.getId() == client->getId()) { c = *client; break; }
    FilesHelper::rewriteClients(clients);
}
