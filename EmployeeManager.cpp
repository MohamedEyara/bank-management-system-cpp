#include "EmployeeManager.h"
#include "Validation.h"
#include <iostream>
#include <vector>
using namespace std;

void EmployeeManager::printEmployeeMenu() {
    cout << "\n  ===== Employee Menu =====\n"
         << "  1. Add New Client\n"
         << "  2. List All Clients\n"
         << "  3. Search Client by ID\n"
         << "  4. Edit Client Info\n"
         << "  5. Display My Info\n"
         << "  6. Change Password\n"
         << "  0. Logout\n"
         << "  =========================\n"
         << "  Choice: ";
}

void EmployeeManager::newClient(Employee* employee) {
    string name, pass;
    double balance;
    cout << "  Client name: "; cin.ignore(); getline(cin, name);
    cout << "  Client password: "; cin >> pass;
    cout << "  Initial balance: "; cin >> balance;
    if (!Validation::isValidName(name))       { cout << "  Invalid name.\n";              return; }
    if (!Validation::isValidPassword(pass))   { cout << "  Invalid password.\n";          return; }
    if (!Validation::isValidBalance(balance)) { cout << "  Invalid balance (min 1500).\n"; return; }
    Client c(0, name, pass, balance);
    employee->addClient(c);
}

void EmployeeManager::listAllClients(Employee* employee) {
    employee->listClients();
}

void EmployeeManager::searchForClient(Employee* employee) {
    int id;
    cout << "  Enter client ID: "; cin >> id;
    Client* c = employee->searchClient(id);
    if (c) c->display();
    else   cout << "  Client not found.\n";
}

void EmployeeManager::editClientInfo(Employee* employee) {
    int id;
    cout << "  Enter client ID to edit: "; cin >> id;
    string name, pass;
    double balance;
    cout << "  New name (blank to skip): ";     cin.ignore(); getline(cin, name);
    cout << "  New password (blank to skip): ";              getline(cin, pass);
    cout << "  New balance (0 to skip): ";       cin >> balance;
    employee->editClient(id, name, pass, balance);
}

Employee* EmployeeManager::login(int id, const string& password) {
    static vector<Employee> employees;
    employees = FilesHelper::getEmployees();
    for (auto& e : employees)
        if (e.getId() == id && e.getPassword() == password) return &e;
    return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
    int choice;
    printEmployeeMenu();
    cin >> choice;

    switch (choice) {
        case 1: newClient(employee);        break;
        case 2: listAllClients(employee);   break;
        case 3: searchForClient(employee);  break;
        case 4: editClientInfo(employee);   break;
        case 5: employee->display();        break;
        case 6: {
            string newPass;
            cout << "  New password: "; cin >> newPass;
            if (employee->setPassword(newPass)) {
                vector<Employee> employees = FilesHelper::getEmployees();
                for (auto& e : employees)
                    if (e.getId() == employee->getId()) { e.setPassword(newPass); break; }
                FilesHelper::rewriteEmployees(employees);
                cout << "  Password updated.\n";
            }
            break;
        }
        case 0: cout << "  Logging out...\n"; return false;
        default: cout << "  Invalid option.\n";
    }
    return true;
}
