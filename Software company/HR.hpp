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
    size_t size() const;
    Employee* operator[](int i) const;
    ~HR();
    void leaveJob(int i);
    friend std::ostream& operator<<(std::ostream& os, const HR &obj);
};

#endif