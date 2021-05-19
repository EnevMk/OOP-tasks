#include "Employee.hpp"

std::string Employee::getName() const {
    return name;
}

size_t Employee::getExperience() const {
    return experience;
}

std::ostream& operator<<(std::ostream& os, const Employee& obj) {
    obj.print(os);
    return os;
}