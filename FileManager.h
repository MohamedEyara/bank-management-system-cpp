#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include <iostream>

class FileManager : public DataSourceInterface {
public:
    void addClient(Client c) override {
        int lastId = FilesHelper::getLast("data/clients_last_id.txt");
        c.setId(lastId + 1);
        FilesHelper::saveClient(c);
        std::cout << "  Client added with ID: " << c.getId() << "\n";
    }

    void addEmployee(Employee e) override {
        int lastId = FilesHelper::getLast("data/employees_last_id.txt");
        e.setId(lastId + 1);
        FilesHelper::saveEmployee("data/Employees.txt", "data/employees_last_id.txt", e);
        std::cout << "  Employee added with ID: " << e.getId() << "\n";
    }

    void addAdmin(Admin a) override {
        int lastId = FilesHelper::getLast("data/admins_last_id.txt");
        a.setId(lastId + 1);
        FilesHelper::saveAdmin(a);
        std::cout << "  Admin added with ID: " << a.getId() << "\n";
    }

    void getAllClients() override {
        auto clients = FilesHelper::getClients();
        if (clients.empty()) { std::cout << "  No clients found.\n"; return; }
        for (auto& c : clients) { c.display(); std::cout << "  ----\n"; }
    }

    void getAllEmployees() override {
        auto employees = FilesHelper::getEmployees();
        if (employees.empty()) { std::cout << "  No employees found.\n"; return; }
        for (auto& e : employees) { e.display(); std::cout << "  ----\n"; }
    }

    void getAllAdmins() override {
        auto admins = FilesHelper::getAdmins();
        if (admins.empty()) { std::cout << "  No admins found.\n"; return; }
        for (auto& a : admins) { a.display(); std::cout << "  ----\n"; }
    }

    void removeAllClients() override {
        FilesHelper::clearFile("data/Clients.txt", "data/clients_last_id.txt");
        std::cout << "  All clients removed.\n";
    }

    void removeAllEmployees() override {
        FilesHelper::clearFile("data/Employees.txt", "data/employees_last_id.txt");
        std::cout << "  All employees removed.\n";
    }

    void removeAllAdmins() override {
        FilesHelper::clearFile("data/Admins.txt", "data/admins_last_id.txt");
        std::cout << "  All admins removed.\n";
    }
};
