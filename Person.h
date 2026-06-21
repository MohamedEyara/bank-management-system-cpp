#pragma once
#include <string>
#include <iostream>
#include "Validation.h"

class Person {
protected:
    int _id;
    std::string _name;
    std::string _password;

public:
    Person() : _id(0), _name(""), _password("") {}
    Person(int id, const std::string& name, const std::string& password)
        : _id(id), _name(name), _password(password) {}

    int getId() const { return _id; }
    std::string getName() const { return _name; }
    std::string getPassword() const { return _password; }

    void setId(int id) { _id = id; }

    bool setName(const std::string& name) {
        if (!Validation::isValidName(name)) {
            std::cout << "  Error: Name must be alphabetic, 5-20 characters.\n";
            return false;
        }
        _name = name;
        return true;
    }

    bool setPassword(const std::string& pass) {
        if (!Validation::isValidPassword(pass)) {
            std::cout << "  Error: Password must be 8-20 characters.\n";
            return false;
        }
        _password = pass;
        return true;
    }

    virtual void display() const {
        std::cout << "  ID      : " << _id   << "\n"
                  << "  Name    : " << _name << "\n";
    }

    virtual ~Person() = default;
};
