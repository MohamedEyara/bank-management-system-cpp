#pragma once
#include <string>
#include <algorithm>

class Validation {
public:
    static bool isAlphaOnly(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), [](char c){ return std::isalpha(c) || c == ' '; });
    }

    static bool isValidName(const std::string& name) {
        return isAlphaOnly(name) && name.size() >= 5 && name.size() <= 20;
    }

    static bool isValidPassword(const std::string& pass) {
        return pass.size() >= 8 && pass.size() <= 20;
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500.0;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000.0;
    }

    static bool isPositiveAmount(double amount) {
        return amount > 0.0;
    }
};
