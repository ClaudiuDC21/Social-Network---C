#pragma once
#include "../Service/Network.h"
using namespace std;

class UserInterface {
private:
    Network &network;

public:
    UserInterface(Network& network);
    ~UserInterface();

    void console();

    void addUser();
    void updateUser();
    void deleteUser();
    void showUserById();
    void showAllUsers();

    void addEvent();
    void updateEvent();
    void deleteEvent();
    void showEventById();
    void showEvents();

    void addChat();
    void sendMessage();
    void showChatById();
    void showChats();
    void showChatsBetween();

    void addFrindship();
    void deleteFriendship();
    void showFriendships();

    void addFollower();
    void deleteFollower();
    void showFollowers();

    void participationsAtEvent();
    void deleteParticipationAtEvent();
    void showParticipants();
    void showEventsParticipated();

};
