#ifndef PROGRAMMER_HPP
#define PROGRAMMER_HPP

#include "Employee.hpp"

class Programmer : public Employee {

private:
    bool cpp;
    bool cSharp;
    
    std::ostream& print(std::ostream&) const;

public:
    Programmer(std::string name_, size_t exp_, bool cpp_, bool cSharp_);
    void setName(std::string name_);
    void setExperience(size_t exp_);
    void setCppKnowledge(bool cpp_);
    void setCSharpKnowledge(bool cSharp_);
    Employee* clone() const;
    /* std::string getName() const;
    size_t getExperience() const; */
    bool knowsCpp() const;
    bool knowsCSharp() const;
    
};

#endif