#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee {

protected:

    std::string name;
    size_t experience;

    virtual std::ostream& print(std::ostream&) const = 0;

public:
    virtual Employee* clone() const = 0;
    std::string getName() const;
    size_t getExperience() const;
    //virtual bool operator==(Employee *e) const = 0;
    //virtual bool sameAs(Employee *e) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
};

#endif