#include "Admin.h"
#include "FilesHelper.h"
#include <iostream>
#include <vector>

void Admin::addClient(Client& client) {
    int lastId = FilesHelper::getLast("data/clients_last_id.txt");
    client.setId(lastId + 1);
    FilesHelper::saveClient(client);
    std::cout << "  Client added with ID: " << client.getId() << "\n";
}

Client* Admin::searchClient(int id) {
    static std::vector<Client> clients;
    clients = FilesHelper::getClients();
    for (auto& c : clients) {
        if (c.getId() == id) return &c;
    }
    return nullptr;
}

void Admin::listClients() {
    auto clients = FilesHelper::getClients();
    if (clients.empty()) { std::cout << "  No clients found.\n"; return; }
    std::cout << "  ---- Client List ----\n";
    for (auto& c : clients) { c.display(); std::cout << "  ----\n"; }
}

void Admin::editClient(int id, const std::string& name, const std::string& password, double balance) {
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

void Admin::addEmployee(Employee& employee) {
    int lastId = FilesHelper::getLast("data/employees_last_id.txt");
    employee.setId(lastId + 1);
    FilesHelper::saveEmployee("data/Employees.txt", "data/employees_last_id.txt", employee);
    std::cout << "  Employee added with ID: " << employee.getId() << "\n";
}

Employee* Admin::searchEmployee(int id) {
    static std::vector<Employee> employees;
    employees = FilesHelper::getEmployees();
    for (auto& e : employees) {
        if (e.getId() == id) return &e;
    }
    return nullptr;
}

void Admin::editEmployee(int id, const std::string& name, const std::string& password, double salary) {
    auto employees = FilesHelper::getEmployees();
    bool found = false;
    for (auto& e : employees) {
        if (e.getId() == id) {
            if (!name.empty())     e.setName(name);
            if (!password.empty()) e.setPassword(password);
            if (salary > 0)        e.setSalary(salary);
            found = true;
            break;
        }
    }
    if (!found) { std::cout << "  Employee not found.\n"; return; }
    FilesHelper::rewriteEmployees(employees);
    std::cout << "  Employee updated.\n";
}

void Admin::listEmployees() {
    auto employees = FilesHelper::getEmployees();
    if (employees.empty()) { std::cout << "  No employees found.\n"; return; }
    std::cout << "  ---- Employee List ----\n";
    for (auto& e : employees) { e.display(); std::cout << "  ----\n"; }
}
