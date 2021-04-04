#include <cstring>
#include "Room.hpp"

Room::Room() {
    
    area = 0;
}
Room::Room(const char desc_[30], double area_) {
    strcpy(desc, desc_);
    area = area_;
}

Room::Room(const Room &obj) {
    strcpy(desc, obj.desc);
    area = obj.area;
}

Room& Room::operator=(const Room &obj) {
    if(this != &obj) {
        strcpy(desc, obj.desc);
        area = obj.area;
    }
    return *this;
}

const char* Room::getDescription() const {
    //const char *pt = &desc[0];
    return &desc[0];
}

double Room::getArea() const {
    return area;
}

void Room::setDescription(const char* desc_) {
    strcpy(desc, desc_);
}

void Room::setArea(const double area_) {
    area = area_;
}

std::ostream& operator<<(std::ostream &os, const Room &obj) {
    os << "\nRoom description: " << obj.desc << '\n'
    << "Area: " << obj.area << " square meters\n";

    return os;
}

std::istream& operator>>(std::istream &is, Room &obj) {
    //std::cout << "Enter room description: \n"; 
    is >> obj.desc;

    is >> obj.area;

    return is;
}