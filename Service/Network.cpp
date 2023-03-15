#include "Network.h"
#include <fstream>
#include <iostream>
#include <string>

Network::Network()
= default;

Network::Network(string usersFile, string eventsFile)
{
    this->fileOfUsers = usersFile;
    this->fileOfEVents = eventsFile;

    try {
        readEventsFromFile();
        saveUserFromFile();
    } catch (string& basicString) {
        cout << basicString << endl;
    }
}

Network::~Network()
{
    if (!fileOfEVents.empty())
        saveEventsInFile();

    if (!fileOfUsers.empty())
        saveUserInFile();
}

void Network::addUser(const User& user) {
    List<User> listOfUsers = getUsers();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == user.getId()) {
            throw string("This user already exists!");
        }
    }

    users.add(user);
}

void Network::addEvent(const Event& event) {
    List<Event> listOfEvents = getEvents();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == event.getId()) {
            throw string("This event already exists!");
        }
    }
    events.add(event);
}

void Network::addChat(const Chat& chat) {
    List<Chat> listOfChats = getChats();
    List<User> listOfUSers = getUsers();

    bool findFirsUser = false;
    bool findSecondUser = false;

    for (int i = 0; i < listOfChats.getSize(); i++) {
        if (listOfChats[i].getUser1() == chat.getUser1() && listOfChats[i].getUser2() == chat.getUser2()) {
            throw string("This chat already exists!");
        }
    }

    for (int i = 0; i < listOfUSers.getSize(); i++) {
        if (listOfUSers[i].getId() == chat.getUser1()) {
            findFirsUser = true;
        }
        if (listOfUSers[i].getId() == chat.getUser2()) {
            findSecondUser = true;
        }
    }

    if (!findFirsUser) {
        throw string("The user with the id " + to_string(chat.getUser1()) + " does not exist!");
    }

    if (!findSecondUser) {
        throw string("The user with the id " + to_string(chat.getUser2()) + " does not exist!");
    }

    for (int i = 0; i < listOfChats.getSize(); i++) {
        if (listOfChats[i].getId() == chat.getId()) {
            throw string("This chat already exists!");
        }
    }

    chats.add(chat);
}

void Network::sendMessage(int IdUserSender, int IdUserReceiver, string message) {
    for (int i = 0; i < chats.getSize(); i++) {
        if ((chats[i].getUser1() == IdUserSender && chats[i].getUser2() == IdUserReceiver) || (chats[i].getUser1() == IdUserReceiver &&
                                                                                                   chats[i].getUser2() == IdUserSender)) {
            cout << "before dump" << endl;
            chats[i].addMessage(IdUserSender, message);
            cout << "after dump" << endl;
            return;
        }
    }

    throw string("There is no chat between these two users!");
}

void Network::updateUser(int id, const User& user) {
    List<User> listOfUsers = this->users.getOrderedList();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == id) {
            this->users.remove(listOfUsers[i]);
            this->users.add(user);
            return;
        }
    }

    throw string("The user with the id " + to_string(id) + " does not exist!");
}

void Network::updateEvent(int id, const Event& event) {
    List<Event> listOfEvents = this->events.getOrderedList();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == id) {
            this->events.remove(listOfEvents[i]);
            this->events.add(event);
            return;
        }
    }

    throw string("The event with the id " + to_string(id) + " does not exist!");
}

void Network::deleteUser(int id) {
    List<User> listOfUsers = this->users.getOrderedList();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == id) {
            this->deleteUserFromList(id);
            this->users.remove(listOfUsers[i]);
            return;
        }
    }

    throw string("The user with the id " + to_string(id) + " does not exist!");
}

void Network::deleteEvent(int id) {
    List<Event> listOfEvents = this->events.getOrderedList();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == id) {
            this->deleteEventFromList(id);
            this->events.remove(listOfEvents[i]);
            return;
        }
    }
    throw string("The event with the id" + to_string(id) + " does not exist!");
}

User Network::getUser(int id) {
    List<User> listOfUsers = this->users.getOrderedList();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == id) {
            return listOfUsers[i];
        }
    }

    throw string("The user with the id " + to_string(id) + " does not exist!");
}

Event Network::getEvent(int id) {
    List<Event> listOfEvents = this->events.getOrderedList();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == id) {
            return listOfEvents[i];
        }
    }

    throw string("The event with the id " + to_string(id) + " does not exist!");
}

Chat Network::getChat(int id) {
    for (int i = 0; i < chats.getSize(); i++) {
        if (chats[i].getId() == id) {
            return chats[i];
        }
    }

    throw string("The chat with the id " + to_string(id) + " does not exist!");
}

List<User> Network::getUsers() {
    return this->users.getOrderedList();
}

List<Event> Network::getEvents() {
    return this->events.getOrderedList();
}

List<Chat> Network::getChats() {
    return this->chats;
}

Chat Network::getChatBetween(int id_user1, int id_user2) {

    for (int i = 0; i < chats.getSize(); i++) {
        if (chats[i].getUser1() == id_user1 && chats[i].getUser2() == id_user2) {
            return chats[i];
        }
        else if (chats[i].getUser1() == id_user2 && chats[i].getUser2() == id_user1) {
            return chats[i];
        }
    }
    throw string("There is no chat between these users!");
}

void Network::addFriendship(int idUser1, int idUser2) {
    List<User> listOfUsers = this->users.getOrderedList();

    User *user1 = nullptr;
        User *user2 = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == idUser1) {
            user1 = &listOfUsers[i];
        }
        if (listOfUsers[i].getId() == idUser2) {
            user2 = &listOfUsers[i];
        }
    }

    if (user1 == nullptr || user2 == nullptr) {
        throw string("The user with the id " + to_string(idUser1) + " or with the id " + to_string(idUser2) + " does not exist!");
    }

    if (user1->getId() == user2->getId()) {
        throw string("You can't add friendship to yourself!");
    }

    List<int> friendsOfUser1 = user1->getFriends();
    List<int> friendsOfUSer2 = user2->getFriends();

    for (int i = 0; i < friendsOfUser1.getSize(); i++) {
        if (friendsOfUser1[i] == user2->getId()) {
            throw string("The user with the id " + to_string(idUser2) + " is already a friend with the user " + to_string(idUser1) + "!");
        }
    }

    user1->addFriend(user2->getId());
    user2->addFriend(user1->getId());

    this->users.remove(*user1);
    this->users.remove(*user2);

    this->users.add(*user1);
    this->users.add(*user2);
}

void Network::deleteFriendship(int idUser1, int idUser2) {
        List<User> listOfUsers = this->users.getOrderedList();

    User *user1 = nullptr;
    User *user2 = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == idUser1) {
            user1 = &listOfUsers[i];
        }
        if (listOfUsers[i].getId() == idUser2) {
            user2 = &listOfUsers[i];
        }
    }

    if (user1 == nullptr || user2 == nullptr) {
        throw string("The user with the id " + to_string(idUser1) + " or the id " + to_string(idUser2) + " deoes not exist!");
    }

    if (user1->getId() == user2->getId()) {
        throw string("One cannot remove friendship with oneself!");
    }

    List<int> friendsOfUser1 = user1->getFriends();
    List<int> friendsOfUser2 = user2->getFriends();

    for (int i = 0; i < friendsOfUser1.getSize(); i++) {
        if (friendsOfUser1[i] == user2->getId()) {
            user1->removeFriends(user2->getId());
            user2->removeFriends(user1->getId());

            this->users.remove(*user1);
            this->users.remove(*user2);

            this->users.add(*user1);
            this->users.add(*user2);
            return;
        }
    }

    throw string("Utilizatorul cu id-ul " + to_string(idUser2) + " nu este prieten cu utilizatorul cu id-ul " + to_string(idUser1) + "!");
}

List<int> Network::getFriendship(int idUser) {
    List<User> lista = this->users.getOrderedList();

    User *u = nullptr;

    for (int i = 0; i < lista.getSize(); i++) {
        if (lista[i].getId() == idUser) {
            u = &lista[i];
        }
    }

    if (u == nullptr) {
        throw string("Utilizatorul cu id-ul " + to_string(idUser) + " nu exists!");
    }

    return u->getFriends();
}

void Network::addFollower(int idUser1, int idUser2) {
    List<User> lista = this->users.getOrderedList();

    User *u1 = nullptr;
    User *u2 = nullptr;

    for (int i = 0; i < lista.getSize(); i++) {
        if (lista[i].getId() == idUser1) {
            u1 = &lista[i];
        }
        if (lista[i].getId() == idUser2) {
            u2 = &lista[i];
        }
    }

    if (u1 == nullptr || u2 == nullptr) {
        throw string("Utilizatorul cu id-ul " + to_string(idUser1) + " sau cu id-ul " + to_string(idUser2) + " nu exists!");
    }

    if (u1->getId() == u2->getId()) {
        throw string("Nu se poate urmari pe el insusi.");
    }

    List<int> urmaritoriU1 = u1->getFollowers();

    for (int i = 0; i < urmaritoriU1.getSize(); i++) {
        if (urmaritoriU1[i] == u2->getId()) {
            throw string("Utilizatorul cu id-ul " + to_string(idUser2) + " urmareste deja utilizatorul cu id-ul " + to_string(idUser1) + "!");
        }
    }

    u1->addFollower(u2->getId());
    u2->addFollowing(u1->getId());

    this->users.remove(*u1);
    this->users.remove(*u2);

    this->users.add(*u1);
    this->users.add(*u2);
}

void Network::deleteFollower(int idUser1, int idUser2) {
    List<User> lista = this->users.getOrderedList();

    User *user1 = nullptr;
    User *user2 = nullptr;

    for (int i = 0; i < lista.getSize(); i++) {
        if (lista[i].getId() == idUser1) {
            user1 = &lista[i];
        }
        if (lista[i].getId() == idUser2) {
            user2 = &lista[i];
        }
    }

    if (user1 == nullptr || user2 == nullptr) {
        throw string("The user with the id " + to_string(idUser1) + " or with the id " + to_string(idUser2) + " does not exist!");
    }

    if (user1->getId() == user2->getId()) {
        throw string("A user cannot follow himself.");
    }

    List<int> followersOFUser1 = user1->getFollowers();

    for (int i = 0; i < followersOFUser1.getSize(); i++) {
        if (followersOFUser1[i] == user2->getId()) {
            user1->removeFollower(user2->getId());
            user2->removeFollowing(user1->getId());

            this->users.remove(*user1);
            this->users.remove(*user2);
            return;
        }
    }

    throw string("The user with the id " + to_string(idUser2) + " does not follow the user with the id" + to_string(idUser1) + "!");
}

List<int> Network::getFollowers(int idUser) {
    List<User> listOfUsers = this->users.getOrderedList();

    User *user = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == idUser) {
            user = &listOfUsers[i];
        }
    }

    if (user == nullptr) {
        throw string("The user with the id" + to_string(idUser) + " does not exist!");
    }

    return user->getFollowers();
}

void Network::takePartAtEvent(int userId, int eventId) {
    List<User> listOfUsers = this->users.getOrderedList();

    User *user = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == userId) {
            user = &listOfUsers[i];
        }
    }

    if (user == nullptr) {
        throw string("The user with the id " + to_string(userId) + " does not exist!");
    }

    List<Event> listOfEvents = this->events.getOrderedList();

    Event *event = nullptr;

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == eventId) {
            event = &listOfEvents[i];
        }
    }

    if (event == nullptr) {
        throw string("The event with the id " + to_string(eventId) + " does exist!");
    }

    List<int> listOfParticipants = event->getParticipants();

    for (int i = 0; i < listOfParticipants.getSize(); i++) {
        if (listOfParticipants[i] == user->getId()) {
            throw string("The user with the id " + to_string(userId) + " already participate in the event with the id " + to_string(eventId) + "!");
        }
    }

    event->addParticipant(user->getId());
    user->addEvent(event->getId());

    this->events.remove(*event);
    this->events.add(*event);

    this->users.remove(*user);
    this->users.add(*user);
}

void Network::deleteParticiation(int userId, int eventId) {
    List<User> listOfUsers = this->users.getOrderedList();

    User *user = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == userId) {
            user = &listOfUsers[i];
        }
    }

    if (user == nullptr) {
        throw string("The user with the id" + to_string(userId) + " does not exist!");
    }

    List<Event> listOfEvents = this->events.getOrderedList();

    Event *event = nullptr;

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == eventId) {
            event = &listOfEvents[i];
        }
    }

    if (event == nullptr) {
        throw string("The event with the id " + to_string(eventId) + " does not exist!");
    }

    List<int> listOfParticipants = event->getParticipants();

    for (int i = 0; i < listOfParticipants.getSize(); i++) {
        if (listOfParticipants[i] == user->getId()) {
            event->removeParticipant(user->getId());
            user->removeEvent(event->getId());

            this->events.remove(*event);
            this->events.add(*event);

            this->users.remove(*user);
            this->users.add(*user);
            return;
        }
    }

    throw string("The user with the id " + to_string(userId) + " does not participate at the event with the id" + to_string(eventId) + "!");
}

List<int> Network::getParticipants(int eventId) {
    List<Event> listOfEvents = this->events.getOrderedList();

    Event *event = nullptr;

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        if (listOfEvents[i].getId() == eventId) {
            event = &listOfEvents[i];
        }
    }

    if (event == nullptr) {
        throw string("The event with the id " + to_string(eventId) + " does not exist!");
    }

    return event->getParticipants();
}

List<int> Network::getEventsParticipation(int userId) {
    List<User> listOfUsers = this->users.getOrderedList();

    User *user = nullptr;

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        if (listOfUsers[i].getId() == userId) {
            user = &listOfUsers[i];
        }
    }

    if (user == nullptr) {
        throw string("The user with the id " + to_string(userId) + " does not exist!");
    }

    return user->getEvents();
}


void Network::setUserFile(const string &UsersFile) {
    fileOfUsers = UsersFile;
}

void Network::setEventFile(const string &EventsFile) {
    fileOfEVents = EventsFile;
}

void Network::saveUserInFile() {
    ofstream fout(fileOfUsers);

    if (!fout.is_open()) {
        throw string("The file " + fileOfUsers + " could not be opened!");
    }

    List<User> listOfUsers = this->users.getOrderedList();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        fout << listOfUsers[i] << endl;
    }
}

void Network::saveUserFromFile() {
    ifstream fin(fileOfUsers);

    if (!fin.is_open()) {
        throw string("The file " + fileOfUsers + " could not be opened!");
    }

    User user;
    while (fin >> user) {
        this->users.add(user);
    }
}

void Network::saveEventsInFile() {
    ofstream fout(fileOfEVents);

    if (!fout.is_open()) {
        throw string("The file " + fileOfEVents + " could not be opened!");
    }

    List<Event> listOfEvents = this->events.getOrderedList();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        fout << listOfEvents[i] << endl;
    }
}

void Network::readEventsFromFile() {
    ifstream fin(fileOfEVents);

    if (!fin.is_open()) {
        throw string("The file " + fileOfEVents + " could not be opened!");
    }

    while (!fin.eof()) {
        Event event;
        fin >> event;

        if (fin.eof()) {
            break;
        }

        this->events.add(event);
    }
}

void Network::deleteUserFromList(int id) {
    List<User> lostOfUsers = this->users.getOrderedList();

    for (int i = 0; i < lostOfUsers.getSize(); i++) {
        if (lostOfUsers[i].getId() != id) {
            lostOfUsers[i].removeFriends(id);
            lostOfUsers[i].removeFollower(id);
            lostOfUsers[i].removeFollowing(id);
        }
    }

    List<Event> listOfEvents = this->events.getOrderedList();

    for (int i = 0; i < listOfEvents.getSize(); i++) {
        listOfEvents[i].removeParticipant(id);
    }

}

void Network::deleteEventFromList(int id) {
    List<User> listOfUsers = this->users.getOrderedList();

    for (int i = 0; i < listOfUsers.getSize(); i++) {
        listOfUsers[i].removeEvent(id);
    }
}

