#pragma once
#include "UserInterface/UserInterface.h"
using namespace std;

int main() {

    Network network("users.txt", "events.txt");
    UserInterface userInterface(network);
    userInterface.console();
    return 0;
}