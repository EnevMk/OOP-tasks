#pragma once
#include "Room.hpp"

class Apartment {

private:
    Room *roomsList;
    size_t count;

public:

    Apartment(Room *roomsList_, size_t count_);
    Apartment(const Apartment &obj);
    Apartment& operator=(const Apartment &obj);
    ~Apartment();
    const Room* getRooms() const;
    size_t getRoomsCount() const;
    double getApartamentArea() const;
    double getAverageArea() const;
    const Room operator[](const char *desc_) const;
    bool operator<(const Apartment &obj) const;
    bool operator==(const Apartment &obj) const;
    bool operator>(const Apartment &obj) const;
    bool operator>=(const Apartment &obj) const;
    bool operator<=(const Apartment &obj) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Apartment &obj);
};