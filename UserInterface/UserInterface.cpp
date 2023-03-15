#include "UserInterface.h"

#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

UserInterface::UserInterface(Network &network) : network(network) {}

UserInterface::~UserInterface()
= default;

void UserInterface::console() {
    int option;
    while (true) {
        cout << "---Welcome to the menu---" << endl;
        cout << "-------User--------" << endl;
        cout << "1. Add a user." << endl;
        cout << "2. Update a user." << endl;
        cout << "3. Delete a user." << endl;
        cout << "4. Show a specified user." << endl;
        cout << "5. Show all users" << endl;
        cout << "--------Event--------" << endl;
        cout << "6. Add an event" << endl;
        cout << "7. Update an event." << endl;
        cout << "8. Delete an event." << endl;
        cout << "9. Show a specified event." << endl;
        cout << "10. Show all events." << endl;
        cout << "---------Chat---------" << endl;
        cout << "11. Add a chat." << endl;
        cout << "12. Add a message." << endl;
        cout << "13. Show a specified chat." << endl;
        cout << "14. Show all the chats." << endl;
        cout << "15. Show chats between 2 users." << endl;
        cout << "------Friendship--------" << endl;
        cout << "16. Add a friendship." << endl;
        cout << "17. Delete a friendship." << endl;
        cout << "18. Show friends." << endl;
        cout << "-------Followers-------" << endl;
        cout << "19. Add a follower." << endl;
        cout << "20. Delete a follower." << endl;
        cout << "21. Show followers." << endl;
        cout << "------Participation------" << endl;
        cout << "22. Participation at an event." << endl;
        cout << "23. Delete participation." << endl;
        cout << "24. Show participants at an event." << endl;
        cout << "25. Show events participated." << endl;
        cout << "------------------" << endl;
        cout << "0. Exit." << endl;
        cout << "Pick an option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case 1:
                addUser();
                break;
            case 2:
                updateUser();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                showUserById();
                break;
            case 5:
                showAllUsers();
                break;
            case 6:
                addEvent();
                break;
            case 7:
                updateEvent();
                break;
            case 8:
                deleteEvent();
                break;
            case 9:
                showEventById();
                break;
            case 10:
                showEvents();
                break;
            case 11:
                addChat();
                break;
            case 12:
                sendMessage();
                break;
            case 13:
                showChatById();
                break;
            case 14:
                showChats();
                break;
            case 15:
                showChatsBetween();
                break;
            case 16:
                addFrindship();
                break;
            case 17:
                deleteFriendship();
                break;
            case 18:
                showFriendships();
                break;
            case 19:
                addFollower();
                break;
            case 20:
                deleteFollower();
                break;
            case 21:
                showFollowers();
                break;
            case 22:
                participationsAtEvent();
                break;
            case 23:
                deleteParticipationAtEvent();
                break;
            case 24:
                showParticipants();
                break;
            case 25:
                showEventsParticipated();
                break;
            case 0:
                return;
        }
    }
}

void UserInterface::addUser() {
    int id, age;
    string name, email, password;

    cout << "Id: ";
    cin >> id;

    cout << "Nume: ";
    cin >> name;

    cout << "Age: ";
    cin >> age;

    cout << "Email: ";
    cin >> email;

    cout << "Password: ";
    cin >> password;

    try {
        network.addUser(User(id, name, age, email, password));
        cout << "The user has been successfully added!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::addEvent() {
    int id;;
    string name, date, location;

    cout << "Id: ";
    cin >> id;

    cout << "Name: ";
    cin >> name;

    cout << "Date: ";
    cin >> date;

    cout << "Location: ";
    cin >> location;

    try {
        network.addEvent(Event(id, name, date, location));
        cout << "The event has been successfully added!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::addChat() {
    int id, idUser1, idUser2;

    cout << "Id of the chat: ";
    cin >> id;

    cout << "Id of first user: ";
    cin >> idUser1;

    cout << "Id of second user: ";
    cin >> idUser2;

    try {
        network.addChat(Chat(id, idUser1, idUser2));
        cout << "The chat has been successfully added!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::sendMessage() {
    int idUserSender, idUserReceiver;
    string message;

    cout << "Id of the sending user: ";
    cin >> idUserSender;

    cout << "Id of the receiving user: ";
    cin >> idUserReceiver;

    cout << "Message: ";
    cin.ignore();
    getline(cin, message);

    try {
        network.sendMessage(idUserSender, idUserReceiver, message);
        cout << "Message sent succesfully!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::updateUser() {
    int id, age;
    string name, email, password;

    cout << "Id: ";
    cin >> id;

    cout << "New name: ";
    cin >> name;

    cout << "New age: ";
    cin >> age;

    cout << "New email: ";
    cin >> email;

    cout << "New password: ";
    cin >> password;

    try {
        network.updateUser(id, User(id, name, age, email, password));
        cout << "The user has been successfully modified!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::updateEvent() {
    int id;
    string name, date, location;

    cout << "Id: ";
    cin >> id;

    cout << "New name: ";
    cin >> name;

    cout << "New date: ";
    cin >> date;

    cout << "New location: ";
    cin >> location;

    try {
        network.updateEvent(id, Event(id, name, date, location));
        cout << "The event has been successfully modified!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::deleteUser() {
    int id;

    cout << "Id of the user you want to delete: ";
    cin >> id;

    try {
        network.deleteUser(id);
        cout << "The user has been successfully deleted!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::deleteEvent() {
    int id;

    cout << "Id of the event you want to delete: ";
    cin >> id;

    try {
        network.deleteEvent(id);
        cout << "The event has been successfully deleted!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showUserById() {
    int id;

    cout << "Id of the user: ";
    cin >> id;

    try {
        User user = network.getUser(id);
        cout << "Name: " << user.getName() << ", " << "Age: " << user.getAge() << ", " << "Email: " << user.getEmail() << ", " << "Password: " << user.getPassword() << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showEventById() {
    int id;

    cout << "Id of the event you want to see: ";
    cin >> id;

    try {
        Event event = network.getEvent(id);
        cout << "Name: " << event.getName() << ", " << "Date: " << event.getDate() << ", " << "Location: " << event.getLocation() << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showChatById() {
    int id;
    cout << "Id of the chat you want to see: ";
    cin >> id;

    try {
        Chat chat = network.getChat(id);

        string nameOfFirstUser = network.getUser(chat.getUser1()).getName();
        string nameOfSecondUser = network.getUser(chat.getUser2()).getName();

        auto list = chat.getMessages();
        cout << "Id of the chat: " << chat.getId() << "Messages: \n";
        for (int i = 0; i < list.getSize(); i++) {
            string nameSender = network.getUser(list[i].first).getName();
            string nameReceiver = (nameSender == nameOfFirstUser ? nameOfSecondUser : nameOfFirstUser);
            cout << nameSender << " - " << nameReceiver << ": " << list[i].second << endl;
        }

    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showAllUsers() {
    auto list = network.getUsers();

    if (list.getSize() == 0) {
        cout << "There are no users to be shown!" << endl;
        return;
    }

    cout << "Users: \n";
    for (int i = 0; i < list.getSize(); i++) {
        cout << "Id: " << list[i].getId() << ", " << "Name: " << list[i].getName() << ", " << "Age: " << list[i].getAge() << ", " << "Email: " << list[i].getEmail() << ", " << "Password: " << list[i].getPassword() << endl;
    }
}

void UserInterface::showEvents() {
    auto list = network.getEvents();

    if (list.getSize() == 0) {
        cout << "There are no events to be shown" << endl;
        return;
    }

    cout << "Events: \n";
    for (int i = 0; i < list.getSize(); i++) {
        cout << "Id: " << list[i].getId() << ", " << "Name: " << list[i].getName() << ", " << "Date: " << list[i].getDate() << ", " << "Location: " << list[i].getLocation() << endl;
    }
}

void UserInterface::showChats() {
    auto list = network.getChats();

    if (list.getSize() == 0) {
        cout << "There are no chats to be shown!" << endl;
        return;
    }

    cout << "Chats: \n";
    for (int i = 0; i < list.getSize(); i++) {
        string nameUser1 = network.getUser(list[i].getUser1()).getName();
        string nameUser2 = network.getUser(list[i].getUser2()).getName();

        for (int j = 0; j < list[i].getMessages().getSize(); j++) {
            string nameSender = network.getUser(list[i].getMessages()[j].first).getName();
            string nameReceiver = (nameSender == nameUser1 ? nameUser2 : nameUser1);
            cout << nameSender << " - " << nameReceiver << ": " << list[i].getMessages()[j].second << endl;
        }
    }
}

void UserInterface::showChatsBetween() {
    int id1, id2;

    cout << "Id of first user: ";
    cin >> id1;

    cout << "Id of second user: ";
    cin >> id2;

    try {
        Chat chat = network.getChatBetween(id1, id2);

        cout << "Chats: \n";
        for (int i = 0; i < chat.getMessages().getSize(); i++) {
            string nameSender = network.getUser(chat.getMessages()[i].first).getName();
            string nameReceiver = id1 == chat.getUser1() ? network.getUser(id2).getName() : network.getUser(
                    id1).getName();
            cout << nameSender << " - " << nameReceiver << ": " << chat.getMessages()[i].second << endl;
        }
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::addFrindship() {
    int id1, id2;

    cout << "Id of first user: ";
    cin >> id1;

    cout << "Id of second user: ";
    cin >> id2;

    try {
        network.addFriendship(id1, id2);
        cout << "The friendship has been successfully added!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::deleteFriendship() {
    int id1, id2;

    cout << "Id of first user: ";
    cin >> id1;

    cout << "Id of second user: ";
    cin >> id2;

    try {
        network.deleteFriendship(id1, id2);
        cout << "The friendship has been successfully deleted" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showFriendships() {
    int id;

    cout << "Id of the user: ";
    cin >> id;

    try {
        List<int> list = network.getFriendship(id);

        if (list.getSize() == 0) {
            cout << "There are no friends!" << endl;
            return;
        }

        cout << "Friends: \n";
        for (int i = 0; i < list.getSize(); i++) {
            User user = network.getUser(list[i]);
            cout << "Id: " << user.getId() << ", " << "Name: " << user.getName() << ", " << "Age: " << user.getAge() << ", " << "Email: " << user.getEmail() << endl;
        }
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::addFollower() {
    int id1, id2;

    cout << "Id of the followed user: ";
    cin >> id1;

    cout << "Id of the following person: ";
    cin >> id2;

    try {
        network.addFollower(id1, id2);
        cout << "The follower has been successfully added" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::deleteFollower() {
    int id1, id2;

    cout << "Id pf the followed user: ";
    cin >> id1;

    cout << "Id of the following user: ";
    cin >> id2;

    try {
        network.deleteFollower(id1, id2);
        cout << "The follower has been successfully deleted" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showFollowers() {
    int id;

    cout << "Id of the user: ";
    cin >> id;

    try {
        List<int> list = network.getFollowers(id);

        if (list.getSize() == 0) {
            cout << "There are no followers!" << endl;
            return;
        }

        cout << "Followers: \n";
        for (int i = 0; i < list.getSize(); i++) {
            User user = network.getUser(list[i]);
            cout << "Id: " << user.getId() << ", " << "Name: " << user.getName() << ", " << "Age: " << user.getAge() << ", " << "Email: " << user.getEmail() << endl;
        }
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::participationsAtEvent() {
    int id1, id2;

    cout << "Id of the user: ";
    cin >> id1;

    cout << "Id of the event: ";
    cin >> id2;

    try {
        network.takePartAtEvent(id1, id2);
        cout << "The participation at the event has been successfully added!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::deleteParticipationAtEvent() {
    int id1, id2;

    cout << "Id of the user: ";
    cin >> id1;

    cout << "Id of the event: ";
    cin >> id2;

    try {
        network.deleteParticiation(id1, id2);
        cout << "The participation at the event has been successfully deleted!" << endl;
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showParticipants() {
    int id;

    cout << "Id of the event: ";
    cin >> id;

    try {
        List<int> list = network.getParticipants(id);

        if (list.getSize() == 0) {
            cout << "There are no participants at the event." << endl;
            return;
        }

        cout << "Participants: \n";
        for (int i = 0; i < list.getSize(); i++) {
            User user = network.getUser(list[i]);
            cout << "Id: " << user.getId() << ", " << "Name: " << user.getName() << ", " << "Age: " << user.getAge() << ", " << "Email: " << user.getEmail()  << endl;
        }
    } catch (string error) {
        cout << error << endl;
    }
}

void UserInterface::showEventsParticipated() {
    int id;

    cout << "Id of the user: ";
    cin >> id;

    try {
        List<int> list = network.getEventsParticipation(id);

        if (list.getSize() == 0) {
            cout << "This user has not participated at any event!" << endl;
            return;
        }

        cout << "Events that the user participated at: \n";
        for (int i = 0; i < list.getSize(); i++) {
            Event event = network.getEvent(list[i]);
            cout << "Id: " << event.getId() << ", " << "Name: " << event.getName() << ", " << "Date: " << event.getDate() <<  endl;
        }
    } catch (string error) {
        cout << error << endl;
    }
}

