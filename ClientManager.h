#pragma once
#include <string>
#include "Client.h"
#include "FilesHelper.h"
using namespace std;

class ClientManager {
public:
    static void printClientMenu();
    static void updatePassword(Client* client);
    static Client* login(int id, const string& password);
    static bool clientOptions(Client* client);
private:
    static void updateClientFile(Client* client);
};
