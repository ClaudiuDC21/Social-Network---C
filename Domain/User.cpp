#include "User.h"
#include <fstream>

User::User() {
    this->id = 0;
    this->name = "";
    this->age = 0;
    this->email = "";
    this->password = "";
}

User::User(int id, string name, int age, string email, string password) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
}

User::~User() {

}


int User::getId() const {
    return id;
}


void User::setId(int id) {
    this->id = id;
}

string User::getName() const {
    return name;
}

void User::setName(string name) {
    this->name = name;
}

int User::getAge() const {
    return age;
}

void User::setAge(int age) {
    this->age = age;
}

string User::getEmail() const {
    return email;
}

void User::setEmail(string email) {
    this->email = email;
}

string User::getPassword() const {
    return password;
}

void User::setPassword(string password) {
    this->password = password;
}

List<int> User::getFollowing() const {
    return following;
}

List<int> User::getFollowers() const {
    return followers;
}

List<int> User::getFriends() const {
    return friends;
}

List<int> User::getEvents() const {
    return events;
}



void User::addFollowing(int id) {
    following.add(id);
}

void User::removeFollowing(int id) {
    for (int i = 0; i < following.getSize(); i++) {
        if (following[i] == id) {
            following.remove(i);
            break;
        }
    }
}

void User::addFollower(int id) {
    followers.add(id);
}

void User::removeFollower(int id) {
    for (int i = 0; i < followers.getSize(); i++) {
        if (followers[i] == id) {
            followers.remove(i);
            break;
        }
    }
}

void User::addFriend(int id) {
    friends.add(id);
}

void User::removeFriends(int id) {
    for (int i = 0; i < friends.getSize(); i++) {
        if (friends[i] == id) {
            friends.remove(i);
            break;
        }
    }
}

void User::addEvent(int id) {
    events.add(id);
}

void User::removeEvent(int id) {
    for (int i = 0; i < events.getSize(); i++) {
        if (events[i] == id) {
            events.remove(i);
            break;
        }
    }
}


bool User::operator<(const User &user) {
    return this->name < user.name;
}

bool User::operator>(const User &user) {
    return this->name > user.name;
}

bool User::operator==(const User &user) {
    return this->name == user.name && this->age == user.age && this->email == user.email && this->password == user.password;
}

ostream &operator<<(ostream &out, User &user) {
    out << user.id << " " << user.name << " " << user.age << " " << user.email << " " << user.password << " ";
    out << user.following.getSize() << " ";

    for (int i = 0; i < user.following.getSize(); i++) {
        out << user.following[i] << " ";
    }

    out << user.followers.getSize() << " ";
    for (int i = 0; i < user.followers.getSize(); i++) {
        out << user.followers[i] << " ";
    }

    out << user.friends.getSize() << " ";
    for (int i = 0; i < user.friends.getSize(); i++) {
        out << user.friends[i] << " ";
    }

    out << user.events.getSize() << " ";
    for (int i = 0; i < user.events.getSize(); i++) {
        out << user.events[i] << " ";
    }

    return out;
}

istream &operator>>(istream &in, User &user) {
    in >> user.id >> user.name >> user.age >> user.email >> user.password;

    int nr;
    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        user.following.add(id);
    }

    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        user.followers.add(id);
    }

    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        user.friends.add(id);
    }

    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        user.events.add(id);
    }

    return in;
}