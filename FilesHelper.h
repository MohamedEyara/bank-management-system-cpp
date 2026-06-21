#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

class FilesHelper {
public:
    static void saveLast(const std::string& fileName, int id) {
        std::ofstream f(fileName);
        if (f.is_open()) f << id;
    }

    static int getLast(const std::string& fileName) {
        std::ifstream f(fileName);
        int id = 0;
        if (f.is_open()) f >> id;
        return id;
    }

    static void saveClient(Client c) {
        std::ofstream f("data/Clients.txt", std::ios::app);
        if (f.is_open()) f << Parser::clientToLine(c) << "\n";
        saveLast("data/clients_last_id.txt", c.getId());
    }

    static void saveEmployee(const std::string& fileName, const std::string& lastIdFile, Employee e) {
        std::ofstream f(fileName, std::ios::app);
        if (f.is_open()) f << Parser::employeeToLine(e) << "\n";
        saveLast(lastIdFile, e.getId());
    }

    static void saveAdmin(Admin a) {
        std::ofstream f("data/Admins.txt", std::ios::app);
        if (f.is_open()) f << Parser::adminToLine(a) << "\n";
        saveLast("data/admins_last_id.txt", a.getId());
    }

    static std::vector<Client> getClients() {
        std::vector<Client> clients;
        std::ifstream f("data/Clients.txt");
        std::string line;
        while (std::getline(f, line)) {
            if (!line.empty()) clients.push_back(Parser::parseToClient(line));
        }
        return clients;
    }

    static std::vector<Employee> getEmployees() {
        std::vector<Employee> employees;
        std::ifstream f("data/Employees.txt");
        std::string line;
        while (std::getline(f, line)) {
            if (!line.empty()) employees.push_back(Parser::parseToEmployee(line));
        }
        return employees;
    }

    static std::vector<Admin> getAdmins() {
        std::vector<Admin> admins;
        std::ifstream f("data/Admins.txt");
        std::string line;
        while (std::getline(f, line)) {
            if (!line.empty()) admins.push_back(Parser::parseToAdmin(line));
        }
        return admins;
    }

    static void clearFile(const std::string& fileName, const std::string& lastIdFile) {
        std::ofstream f(fileName, std::ios::trunc);
        std::ofstream lf(lastIdFile, std::ios::trunc);
    }

    static void rewriteClients(const std::vector<Client>& clients) {
        std::ofstream f("data/Clients.txt", std::ios::trunc);
        for (const auto& c : clients) f << Parser::clientToLine(c) << "\n";
    }

    static void rewriteEmployees(const std::vector<Employee>& employees) {
        std::ofstream f("data/Employees.txt", std::ios::trunc);
        for (const auto& e : employees) f << Parser::employeeToLine(e) << "\n";
    }

    static void rewriteAdmins(const std::vector<Admin>& admins) {
        std::ofstream f("data/Admins.txt", std::ios::trunc);
        for (const auto& a : admins) f << Parser::adminToLine(a) << "\n";
    }
};
