#ifndef HR_HPP
#define HR_HPP

#include <vector>
#include <iostream>
#include <typeinfo>

#include "Employee.hpp"

class HR {

private:
    std::vector<Employee*> employees;

public:
    void addEmployee(Employee *e);
    ~HR();
    friend std::ostream& operator<<(std::ostream& os, const HR &obj);
};

#endif