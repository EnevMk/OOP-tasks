#include "HR.hpp"

void HR::addEmployee(Employee *e) {
    employees.push_back(e->clone());
}

std::ostream& operator<<(std::ostream& os, const HR &obj) {
    for (int i = 0; i < obj.employees.size(); ++i) {
        os << typeid(*obj.employees[i]).name() << ' ' << *obj.employees[i] << '\n';
    }
    return os;
}

HR::~HR() {
    int size = employees.size();

    for (Employee *e : employees) {
        delete e;
    }
}