#include "TimeStampWithDescription.hpp"

TimeStampWithDescription::TimeStampWithDescription():TimeStamp() {
    
    desc = "";
}

TimeStampWithDescription::TimeStampWithDescription(const unsigned long time_, const std::string& desc_)
    :TimeStamp(time_)
{
    desc = desc_;
}

std::string TimeStampWithDescription::getDescription() const {
    return desc;
}

void TimeStampWithDescription::setDescription(const std::string& str_) {
    desc = str_;
}

std::ostream& operator<<(std::ostream& os, const TimeStampWithDescription &obj) {
    os << obj.time << '\n';
    os << obj.desc << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, TimeStampWithDescription &obj) {
    is >> obj.time;
    
    is >> obj.desc;
    /* std::string file;
    getline(is, file) */
    return is;
}