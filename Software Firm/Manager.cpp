#include "Manager.hpp"

Manager::Manager(std::string name_, size_t exp_, size_t teamSize_) {
    name = name_;
    experience = exp_;
    teamSize = teamSize_;
}

std::ostream& Manager::print(std::ostream& os) const {
    os << name << ' ' << experience << ' ' << teamSize << '\n';
    return os;
}

void Manager::setName(std::string name_) {
    name = name_;
}

void Manager::setExperience(size_t exp_)  {
    experience = exp_;
}

void Manager::setTeamSize(size_t teamSize_) {
    teamSize = teamSize_;
}

Employee* Manager::clone() const {
    Employee *cloned = new Manager(*this);
    return cloned;
}
/* std::string Manager::getName() const {
    return name;
}

size_t Manager::getExperience() const {
    return experience;
} */

size_t Manager::getTeamSize() const {
    return teamSize;
}