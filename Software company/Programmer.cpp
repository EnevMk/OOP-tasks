#include "Programmer.hpp"

Programmer::Programmer(std::string name_, size_t exp_, bool knowsCpp, bool knowsCSharp) {
    name = name_;
    experience = exp_;
    cpp = knowsCpp;
    cSharp = knowsCSharp;
}

std::ostream& Programmer::print(std::ostream& os) const {
    os << name << ' ' << experience << ' ' << cpp << ' ' << cSharp << '\n';
    return os;
}

void Programmer::setName(std::string name_) {
    name = name_;
}

void Programmer::setExperience(size_t exp_)  {
    experience = exp_;
}

void Programmer::setCppKnowledge(bool knowsCpp) {
    cpp = knowsCpp;
}

void Programmer::setCSharpKnowledge(bool knowsCSharp) {
    cSharp = knowsCSharp;
}

Employee* Programmer::clone() const {
    Employee *cloned = new Programmer(*this);
    return cloned;
}

/* bool Programmer::operator==(Programmer &obj) const {
    return name == e->name && cpp 
} */

/* std::string Programmer::getName() const {
    return name;
}

size_t Programmer::getExperience() const {
    return experience;
} */

bool Programmer::knowsCpp() const {
    return cpp;
}

bool Programmer::knowsCSharp() const {
    return cSharp;
}