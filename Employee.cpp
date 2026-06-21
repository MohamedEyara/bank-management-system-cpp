#include "Employee.h"
#include "Client.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>

void Employee::addClient(Client& client) {
    auto clients = FilesHelper::getClients();
    int lastId = FilesHelper::getLast("data/clients_last_id.txt");
    client.setId(lastId + 1);
    FilesHelper::saveClient(client);
    std::cout << "  Client added with ID: " << client.getId() << "\n";
}

Client* Employee::searchClient(int id) {
    static std::vector<Client> clients;
    clients = FilesHelper::getClients();
    for (auto& c : clients) {
        if (c.getId() == id) return &c;
    }
    return nullptr;
}

void Employee::listClients() {
    auto clients = FilesHelper::getClients();
    if (clients.empty()) { std::cout << "  No clients found.\n"; return; }
    std::cout << "  ---- Client List ----\n";
    for (auto& c : clients) { c.display(); std::cout << "  ----\n"; }
}

void Employee::editClient(int id, const std::string& name, const std::string& password, double balance) {
    auto clients = FilesHelper::getClients();
    bool found = false;
    for (auto& c : clients) {
        if (c.getId() == id) {
            if (!name.empty())     c.setName(name);
            if (!password.empty()) c.setPassword(password);
            if (balance > 0)       c.setBalance(balance);
            found = true;
            break;
        }
    }
    if (!found) { std::cout << "  Client not found.\n"; return; }
    FilesHelper::rewriteClients(clients);
    std::cout << "  Client updated.\n";
}
