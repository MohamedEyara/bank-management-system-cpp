#pragma once
#include <string>
#include "Admin.h"
#include "FilesHelper.h"
#include "EmployeeManager.h"
using namespace std;

class AdminManager {
public:
    static void printAdminMenu();
    static Admin* login(int id, const string& password);
    static bool adminOptions(Admin* admin);
};
