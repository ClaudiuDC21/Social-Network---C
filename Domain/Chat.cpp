#include "Chat.h"
#include <fstream>
#include <iostream>
#include <tuple>
#include <iomanip>

Chat::Chat()
= default;

Chat::Chat(int id, int id_user1, int id_user2)
{
    this->id = id;
    this->user1 = id_user1;
    this->user2 = id_user2;
}

Chat::~Chat()
= default;

int Chat::getId() const {
    return id;
}

void Chat::setId(int id) {
    this->id = id;
}

int Chat::getUser1() const {
    return user1;
}

void Chat::setUser1(int user1) {
    this->user1 = user1;
}

int Chat::getUser2() const {
    return user2;
}

void Chat::setUser2(int user2) {
    this->user2 = user2;
}

void Chat::addMessage(int idUserSending, string message) {
    messages.add(pair<int, string>(idUserSending, message));
}

List<pair<int,string>> Chat::getMessages() const {
    return messages;
}

ostream& operator<<(ostream& out, Chat& chat) {
    out << chat.id << " " << chat.user1 << " " << chat.user2 << " ";
    out << chat.messages.getSize() << " ";
    for (int i = 0; i < chat.messages.getSize(); i++) {
        out << chat.messages[i].first << " " << quoted(chat.messages[i].second) << " ";
    }
    return out;
}

istream& operator>>(istream& in, Chat& chat) {
    in >> chat.id >> chat.user1 >> chat.user2;
    int numberOfMessages;
    in >> numberOfMessages;
    for (int i = 0; i < numberOfMessages; i++) {
        int id_user1;
        string message;
        in >> id_user1 >> quoted(message);
        chat.messages.add(pair<int, string>(id_user1, message));
    }

    return in;
}