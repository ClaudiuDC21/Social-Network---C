#pragma once
#include <string>
#include "../AbstractDataType(TAD)/List.h"
using namespace std;

class Chat {
private:
    int id{};
    int user1{};
    int user2{};
    List<pair<int, string>> messages;

public:
    Chat();
    Chat(int id, int id_user1, int id_user2);
    ~Chat();

    int getId() const;
    void setId(int id);

    int getUser1() const;
    void setUser1(int user1);

    int getUser2() const;
    void setUser2(int user2);

    void addMessage(int idUserSending, string message);
    List<pair<int, string>> getMessages() const;

    friend ostream& operator<<(ostream& out, Chat& chat);
    friend istream& operator>>(istream& in, Chat& chat);


};

