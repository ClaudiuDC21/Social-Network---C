#include "Event.h"
#include <fstream>

Event::Event()
= default;

Event::Event(int id, string name, string data, string locatie)
{
    this->id = id;
    this->name = name;
    this->date = data;
    this->location = locatie;
}

Event::~Event()
= default;

int Event::getId() const {
    return id;
}

void Event::setId(int id) {
    this->id = id;
}


string Event::getName() const {
    return name;
}

void Event::setName(string name) {
    this->name = name;
}

string Event::getDate() const {
    return date;
}

void Event::setDate(string date) {
    this->date = date;
}

string Event::getLocation() const {
    return location;
}

void Event::setLocation(string location) {
    this->location = location;
}

List<int> Event::getParticipants() const {
    return participants;
}


void Event::addParticipant(int id) {
    participants.add(id);
}

void Event::removeParticipant(int id) {
    for (int i = 0; i < participants.getSize(); i++) {
        if (participants[i] == id) {
            participants.remove(i);
            break;
        }
    }
}

bool Event::operator<(const Event& event) {
    return this->name < event.name;
}

bool Event::operator>(const Event& event) {
    return this->name > event.name;
}

ostream& operator<<(ostream& out, Event& event) {
    out << event.id << " " << event.name << " " << event.date << " " << event.location << " " << event.participants.getSize() << " ";
    for (int i = 0; i < event.participants.getSize(); i++) {
        out << event.participants[i] << " ";
    }

    return out;
}

istream& operator>>(istream& in, Event& event) {
    int numberOfParticipants;

    in >> event.id >> event.name >> event.date >> event.location >> numberOfParticipants;
    for (int i = 0; i < numberOfParticipants; i++) {
        int id;
        in >> id;
        event.participants.add(id);
    }

    return in;
}
