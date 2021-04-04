#pragma once
#include <iostream>

class Room {

private:
    char desc[30];
    double area;

public:
    Room();
    Room(const char desc_[30], double area_);
    Room(const Room &obj);
    Room& operator=(const Room &obj);
    const char* getDescription() const;
    double getArea() const;
    void setDescription(const char* desc_);
    void setArea(const double area_);

    friend std::ostream& operator<<(std::ostream &os, const Room &obj);
    friend std::istream& operator>>(std::istream &is, Room &obj);
};