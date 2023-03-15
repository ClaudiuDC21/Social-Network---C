#pragma once

#include <string>
#include "../AbstractDataType(TAD)/List.h"

using namespace std;

class User {
private:
    int id;
    string name;
    int age;
    string email;
    string password;
    List<int> following;
    List<int> followers;
    List<int> friends;
    List<int> events;

public:
    User();
    User(int id, string name, int age, string email, string password);
    ~User();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    int getAge() const;
    void setAge(int age);

    string getEmail() const;
    void setEmail(string email);

    string getPassword() const;
    void setPassword(string password);

    List<int> getFollowing() const;
    List<int> getFollowers() const;
    List<int> getFriends() const;
    List<int> getEvents() const;

    void addFollowing(int id);
    void removeFollowing(int id);

    void addFollower(int id);
    void removeFollower(int id);

    void addFriend(int id);
    void removeFriends(int id);

    void addEvent(int id);
    void removeEvent(int id);

    friend ostream &operator<<(ostream &out, User &user);

    friend istream &operator>>(istream &in, User &user);

    bool operator<(const User &user);

    bool operator>(const User &user);

    bool operator==(const User &user);

};