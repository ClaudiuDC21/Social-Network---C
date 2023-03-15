#pragma once
#include <string>
#include "../AbstractDataType(TAD)/List.h"
using namespace std;

class Event {
private:
    int id{};
    string name;
    string date;
    string location;
    List<int> participants;


public:
    Event();
    Event(int id, string name, string date, string location);
    ~Event();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    string getDate() const;
    void setDate(string date);

    string getLocation() const;
    void setLocation(string location);

    void addParticipant(int id);
    void removeParticipant(int id);
    List<int> getParticipants() const;

    friend ostream& operator<<(ostream& out, Event& event);
    friend istream& operator>>(istream& in, Event& event);

    bool operator<(const Event& event);
    bool operator>(const Event& event);

};
