#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"

class Client;

class Employee : public Person {
protected:
    double _salary;

public:
    Employee() : Person(), _salary(0.0) {}
    Employee(int id, const std::string& name, const std::string& password, double salary)
        : Person(id, name, password), _salary(salary) {}

    double getSalary() const { return _salary; }

    bool setSalary(double salary) {
        if (!Validation::isValidSalary(salary)) {
            std::cout << "  Error: Minimum salary is 5000.\n";
            return false;
        }
        _salary = salary;
        return true;
    }

    void display() const override {
        Person::display();
        std::cout << "  Salary  : " << _salary << "\n";
    }

    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients();
    void editClient(int id, const std::string& name, const std::string& password, double balance);
};
