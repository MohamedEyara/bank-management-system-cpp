#include "AdminManager.h"
#include "Validation.h"
#include <iostream>
#include <vector>
using namespace std;

void AdminManager::printAdminMenu() {
    cout << "\n  ===== Admin Menu =====\n"
         << "  --- Client Operations ---\n"
         << "  1. Add New Client\n"
         << "  2. List All Clients\n"
         << "  3. Search Client by ID\n"
         << "  4. Edit Client Info\n"
         << "  --- Employee Operations ---\n"
         << "  5. Add New Employee\n"
         << "  6. List All Employees\n"
         << "  7. Search Employee by ID\n"
         << "  8. Edit Employee Info\n"
         << "  --- Admin ---\n"
         << "  9. Display My Info\n"
         << " 10. Change Password\n"
         << "  0. Logout\n"
         << "  ======================\n"
         << "  Choice: ";
}

Admin* AdminManager::login(int id, const string& password) {
    static vector<Admin> admins;
    admins = FilesHelper::getAdmins();
    for (auto& a : admins)
        if (a.getId() == id && a.getPassword() == password) return &a;
    return nullptr;
}

bool AdminManager::adminOptions(Admin* admin) {
    int choice;
    printAdminMenu();
    cin >> choice;

    switch (choice) {
        case 1: {
            string name, pass; double bal;
            cout << "  Client name: "; cin.ignore(); getline(cin, name);
            cout << "  Password: ";    cin >> pass;
            cout << "  Balance: ";     cin >> bal;
            if (!Validation::isValidName(name) ||
                !Validation::isValidPassword(pass) ||
                !Validation::isValidBalance(bal)) {
                cout << "  Invalid input.\n"; break;
            }
            Client c(0, name, pass, bal);
            admin->addClient(c); break;
        }
        case 2: admin->listClients(); break;
        case 3: {
            int id; cout << "  Client ID: "; cin >> id;
            Client* c = admin->searchClient(id);
            if (c) c->display(); else cout << "  Not found.\n"; break;
        }
        case 4: {
            int id; string name, pass; double bal;
            cout << "  Client ID: "; cin >> id;
            cout << "  New name (blank to skip): ";     cin.ignore(); getline(cin, name);
            cout << "  New password (blank to skip): ";              getline(cin, pass);
            cout << "  New balance (0 to skip): ";       cin >> bal;
            admin->editClient(id, name, pass, bal); break;
        }
        case 5: {
            string name, pass; double sal;
            cout << "  Employee name: "; cin.ignore(); getline(cin, name);
            cout << "  Password: ";      cin >> pass;
            cout << "  Salary: ";        cin >> sal;
            if (!Validation::isValidName(name) ||
                !Validation::isValidPassword(pass) ||
                !Validation::isValidSalary(sal)) {
                cout << "  Invalid input.\n"; break;
            }
            Employee e(0, name, pass, sal);
            admin->addEmployee(e); break;
        }
        case 6: admin->listEmployees(); break;
        case 7: {
            int id; cout << "  Employee ID: "; cin >> id;
            Employee* e = admin->searchEmployee(id);
            if (e) e->display(); else cout << "  Not found.\n"; break;
        }
        case 8: {
            int id; string name, pass; double sal;
            cout << "  Employee ID: "; cin >> id;
            cout << "  New name (blank to skip): ";    cin.ignore(); getline(cin, name);
            cout << "  New password (blank to skip): ";             getline(cin, pass);
            cout << "  New salary (0 to skip): ";      cin >> sal;
            admin->editEmployee(id, name, pass, sal); break;
        }
        case 9: admin->display(); break;
        case 10: {
            string newPass;
            cout << "  New password: "; cin >> newPass;
            if (admin->setPassword(newPass)) {
                vector<Admin> admins = FilesHelper::getAdmins();
                for (auto& a : admins)
                    if (a.getId() == admin->getId()) { a.setPassword(newPass); break; }
                FilesHelper::rewriteAdmins(admins);
                cout << "  Password updated.\n";
            }
            break;
        }
        case 0: cout << "  Logging out...\n"; return false;
        default: cout << "  Invalid option.\n";
    }
    return true;
}
