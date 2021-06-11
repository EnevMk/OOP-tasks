#include <iostream>
#include <fstream>
#include "TimeStampWithDescription.hpp"

int main() {
    TimeStampWithDescription test;
    test.setDescription("The moment students are taking the OOP exam");
    test.setValue(1621425050);

    std::cout << test;
    return 0;
}