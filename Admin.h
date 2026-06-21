#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    Admin() : Employee() {}
    Admin(int id, const std::string& name, const std::string& password, double salary)
        : Employee(id, name, password, salary) {}

    void display() const override {
        std::cout << "  [Admin]\n";
        Employee::display();
    }

    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients();
    void editClient(int id, const std::string& name, const std::string& password, double balance);

    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, const std::string& name, const std::string& password, double salary);
    void listEmployees();
};
