#include <cstring>
#include "Apartment.hpp"

Apartment::Apartment(Room *roomsList_, size_t count_) {
    count = count_;
    roomsList = new Room[count];

    for (int i = 0; i < count; ++i) {
        roomsList[i] = roomsList_[i];
    }
}

Apartment::Apartment(const Apartment &obj) {
    count = obj.count;
    roomsList = new Room[count];

    for (int i = 0; i < count; ++i) {
        roomsList[i] = obj.roomsList[i];
    }
}

Apartment& Apartment::operator=(const Apartment &obj) {
    if (this != &obj) {
        delete[] roomsList;
        
        count = obj.count;
        roomsList = new Room[count];

        for (int i = 0; i < count; ++i) {
            roomsList[i] = obj.roomsList[i];
        }
    }

    return *this;
}

Apartment::~Apartment() {
    delete[] roomsList;
    count = 0;
}

const Room* Apartment::getRooms() const {
    return roomsList;
}

size_t Apartment::getRoomsCount() const {
    return count;
}

double Apartment::getApartamentArea() const {
    int apartmentArea = 0;
    for (int i = 0; i < count; ++i) {
        apartmentArea += roomsList[i].getArea();
    }

    return apartmentArea;
}

double Apartment::getAverageArea() const {
    return (getApartamentArea() / count);
}

const Room Apartment::operator[](const char *desc_) const {

    for (int i = 0; i < count; ++i) {

        if(!strcmp(desc_, roomsList[i].getDescription())) return roomsList[i];

    }
    return {nullptr, 0};
}

bool Apartment::operator<(const Apartment &obj) const {
    return this->getAverageArea() < obj.getAverageArea();
}

bool Apartment::operator==(const Apartment &obj) const {
    return this->getAverageArea() == obj.getAverageArea();
}

bool Apartment::operator>(const Apartment &obj) const {
    return this->getAverageArea() > obj.getAverageArea();
}

bool Apartment::operator>=(const Apartment &obj) const {
    return *this > obj || *this == obj;
}

bool Apartment::operator<=(const Apartment &obj) const {
    return *this < obj || *this == obj;
}

std::ostream& operator<<(std::ostream &os, const Apartment &obj) {
    for (int i = 0; i < obj.count; ++i) {

        os << obj.roomsList[i];
    }

    return os;
}