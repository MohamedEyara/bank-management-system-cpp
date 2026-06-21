#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "Screens.h"
#include "FilesHelper.h"
#include "FileManager.h"
using namespace std;

void ensureDataFilesExist() {
    _mkdir("data");

    auto touch = [](const string& path) {
        ifstream f(path);
        if (!f.good()) {
            ofstream create(path);
        }
        };
    touch("data/Clients.txt");
    touch("data/Employees.txt");
    touch("data/Admins.txt");
    touch("data/clients_last_id.txt");
    touch("data/employees_last_id.txt");
    touch("data/admins_last_id.txt");
}

void seedDefaultAdmin() {
    auto admins = FilesHelper::getAdmins();
    if (!admins.empty()) return;

    FileManager fm;
    Admin defaultAdmin(0, "AdminUser", "Admin1234", 10000.0);
    fm.addAdmin(defaultAdmin);
    cout << "  [Setup] Default admin created - ID: 1, Password: Admin1234\n\n";
}

int main() {
    ensureDataFilesExist();
    seedDefaultAdmin();
    Screens::runApp();
    return 0;
}