#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class Parser {
public:
    static std::vector<std::string> split(const std::string& line, char delim = ',') {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(const std::string& line) {
        auto parts = split(line);
        if (parts.size() < 4) return Client();
        int id       = std::stoi(parts[0]);
        std::string name = parts[1];
        std::string pass = parts[2];
        double bal   = std::stod(parts[3]);
        return Client(id, name, pass, bal);
    }

    static Employee parseToEmployee(const std::string& line) {
        auto parts = split(line);
        if (parts.size() < 4) return Employee();
        int id       = std::stoi(parts[0]);
        std::string name = parts[1];
        std::string pass = parts[2];
        double sal   = std::stod(parts[3]);
        return Employee(id, name, pass, sal);
    }

    static Admin parseToAdmin(const std::string& line) {
        auto parts = split(line);
        if (parts.size() < 4) return Admin();
        int id       = std::stoi(parts[0]);
        std::string name = parts[1];
        std::string pass = parts[2];
        double sal   = std::stod(parts[3]);
        return Admin(id, name, pass, sal);
    }

    static std::string clientToLine(const Client& c) {
        return std::to_string(c.getId()) + "," + c.getName() + "," +
               c.getPassword() + "," + std::to_string(c.getBalance());
    }

    static std::string employeeToLine(const Employee& e) {
        return std::to_string(e.getId()) + "," + e.getName() + "," +
               e.getPassword() + "," + std::to_string(e.getSalary());
    }

    static std::string adminToLine(const Admin& a) {
        return std::to_string(a.getId()) + "," + a.getName() + "," +
               a.getPassword() + "," + std::to_string(a.getSalary());
    }
};
