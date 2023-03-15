#pragma once
#include "../AbstractDataType(TAD)/List.h"
#include "../AbstractDataType(TAD)/OrderedMultitude.h"
#include "../Domain/Chat.h"
#include "../Domain/User.h"
#include "../Domain/Event.h"

using namespace std;

class Network {
private:
    string fileOfUsers;
    string fileOfEVents;

    OrderedMultitude<User> users;
    OrderedMultitude<Event> events;
    List<Chat> chats;

    void saveUserInFile();
    void saveUserFromFile();

    void saveEventsInFile();
    void readEventsFromFile();

    void deleteUserFromList(int id);
    void deleteEventFromList(int id);


public:
    Network();
    Network(string usersFile, string eventsFile);
    ~Network();

    void addUser(const User& user);
    void updateUser(int id, const User& user);
    void deleteUser(int id);
    User getUser(int id);
    List<User> getUsers();

    void addEvent(const Event& event);
    void updateEvent(int id, const Event& event);
    void deleteEvent(int id);
    Event getEvent(int id);
    List<Event> getEvents();

    void addChat(const Chat& chat);
    void sendMessage(int IdUserSender, int IdUserReceiver, string message);
    Chat getChat(int id);
    List<Chat> getChats();
    Chat getChatBetween(int id_user1, int id_user2);

    void addFriendship(int idUser1, int idUser2);
    void deleteFriendship(int idUser1, int idUser2);
    List<int> getFriendship(int idUser);


    void addFollower(int idUser1, int idUser2);
    void deleteFollower(int idUser1, int idUser2);
    List<int> getFollowers(int idUser);

    void takePartAtEvent(int userId, int eventId);
    void deleteParticiation(int userId, int eventId);
    List<int> getParticipants(int eventId);
    List<int> getEventsParticipation(int userId);

    void setUserFile(const string &UsersFile);

    void setEventFile(const string &EventsFile);

};
