#pragma once
#include <string>
#include <iostream>
#include "Person.h"

class Client : public Person {
private:
    double _balance;

public:
    Client() : Person(), _balance(0.0) {}
    Client(int id, const std::string& name, const std::string& password, double balance)
        : Person(id, name, password), _balance(balance) {}

    double getBalance() const { return _balance; }

    bool setBalance(double balance) {
        if (!Validation::isValidBalance(balance)) {
            std::cout << "  Error: Minimum balance is 1500.\n";
            return false;
        }
        _balance = balance;
        return true;
    }

    void deposit(double amount) {
        if (!Validation::isPositiveAmount(amount)) {
            std::cout << "  Error: Deposit amount must be positive.\n";
            return;
        }
        _balance += amount;
        std::cout << "  Deposited " << amount << ". New balance: " << _balance << "\n";
    }

    void withdraw(double amount) {
        if (!Validation::isPositiveAmount(amount)) {
            std::cout << "  Error: Withdrawal amount must be positive.\n";
            return;
        }
        if (_balance - amount < 1500.0) {
            std::cout << "  Error: Insufficient funds (minimum balance 1500 must be maintained).\n";
            return;
        }
        _balance -= amount;
        std::cout << "  Withdrew " << amount << ". New balance: " << _balance << "\n";
    }

    void transferTo(double amount, Client& recipient) {
        if (!Validation::isPositiveAmount(amount)) {
            std::cout << "  Error: Transfer amount must be positive.\n";
            return;
        }
        if (_balance - amount < 1500.0) {
            std::cout << "  Error: Insufficient funds for transfer.\n";
            return;
        }
        _balance -= amount;
        recipient._balance += amount;
        std::cout << "  Transferred " << amount << " to " << recipient.getName()
                  << ". Your new balance: " << _balance << "\n";
    }

    void checkBalance() const {
        std::cout << "  Balance: " << _balance << "\n";
    }

    void display() const override {
        Person::display();
        std::cout << "  Balance : " << _balance << "\n";
    }
};
