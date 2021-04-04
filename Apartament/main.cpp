#include <iostream>
//#include "Room.hpp"
#include "Apartment.hpp"

int main() {

    /* Room r1("Boksoniera", 70);
    std::cout << r1; */

    Room arr[] = {{"Kitchen", 10}, {"Living room", 25}, {"Bedroom", 15}};

    Apartment a2(arr, 3);

    std::cout << a2;


    return 0;
}