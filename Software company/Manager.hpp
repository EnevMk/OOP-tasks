#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Employee.hpp"

class Manager : public Employee {

private:
    size_t teamSize;

    std::ostream& print(std::ostream&) const;
public:

    Manager(std::string name_, size_t exp_, size_t teamSize_);
    void setName(std::string name_);
    void setExperience(size_t exp_);
    void setTeamSize(size_t teamSize_);
    Employee* clone() const;
    bool operator==(Employee *e) const;
    /* std::string getName() const;
    size_t getExperience() const; */
    size_t getTeamSize() const;
    
    
};

#endif