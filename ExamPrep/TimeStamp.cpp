#include "TimeStamp.hpp"

TimeStamp::TimeStamp() {
    time = 0;
}

TimeStamp::TimeStamp(unsigned long time_) {

    if (time >= 0) {
        time = time_;
    }   
}

unsigned long TimeStamp::getTime() const {
    return time;
}

void TimeStamp::setValue(const unsigned long time_) {
    if (time >= 0) {
        time = time_;
    }
}

std::ostream& operator<<(std::ostream& os, const TimeStamp &obj) {
    os << obj.time;
    return os;
}

std::istream& operator>>(std::istream& is, TimeStamp &obj) {
    is >> obj.time;
    return is;
}

TimeStamp TimeStamp::operator+(const TimeStamp &obj) {
    TimeStamp result;
    result.setValue(this->getTime() + obj.getTime());
    return result;
}

TimeStamp& TimeStamp::operator+=(const TimeStamp &obj) {
    *this = *this + obj;
    return *this;
}