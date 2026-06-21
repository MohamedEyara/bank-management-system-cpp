#pragma once
#include <iostream>
#include <string>
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;

class Screens {
public:
    static void bankName() {
        cout << "\n"
            << "  ==========================================\n"
            << "  ||       NATIONAL BANK SYSTEM           ||\n"
            << "  ==========================================\n";
    }

    static void welcome() {
        bankName();
        cout << "  Welcome! Please choose how to log in.\n\n";
    }

    static void loginOptions() {
        cout << "  1. Client\n"
            << "  2. Employee\n"
            << "  3. Admin\n"
            << "  0. Exit\n"
            << "  Choice: ";
    }

    static int loginAs() {
        int choice;
        loginOptions();
        cin >> choice;
        return choice;
    }

    static void invalid(int c) {
        cout << "  Invalid choice: " << c << "\n";
    }

    static void logout() {
        cout << "  You have been logged out. Goodbye!\n\n";
    }

    static void loginScreen(int c) {
        int id;
        string password;
        cout << "  ID: ";
        cin >> id;
        cout << "  Password: ";
        cin >> password;

        switch (c) {
        case 1: {
            Client* client = ClientManager::login(id, password);
            if (!client) { cout << "  Login failed. Check ID and password.\n"; return; }
            cout << "  Welcome, " << client->getName() << "!\n";
            while (ClientManager::clientOptions(client));
            logout();
            break;
        }
        case 2: {
            Employee* emp = EmployeeManager::login(id, password);
            if (!emp) { cout << "  Login failed. Check ID and password.\n"; return; }
            cout << "  Welcome, " << emp->getName() << "!\n";
            while (EmployeeManager::employeeOptions(emp));
            logout();
            break;
        }
        case 3: {
            Admin* admin = AdminManager::login(id, password);
            if (!admin) { cout << "  Login failed. Check ID and password.\n"; return; }
            cout << "  Welcome, " << admin->getName() << "!\n";
            while (AdminManager::adminOptions(admin));
            logout();
            break;
        }
        default:
            invalid(c);
        }
    }

    static void runApp() {
        welcome();
        int choice;
        do {
            choice = loginAs();
            if (choice == 0) {
                cout << "  Thank you for using National Bank System. Goodbye!\n";
                break;
            }
            if (choice < 1 || choice > 3) {
                invalid(choice);
                continue;
            }
            loginScreen(choice);
            bankName();
        } while (true);
    }
};