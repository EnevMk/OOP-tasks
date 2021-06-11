#ifndef TIMESTAMPT_HPP
#define TIMESTAMPT_HPP

#include <iostream>
#include <string>

class TimeStamp {

protected:
    unsigned long time;

public:
    TimeStamp();
    TimeStamp(unsigned long time_);
    unsigned long getTime() const;
    void setValue(const unsigned long time_);

    friend std::ostream& operator<<(std::ostream& os, const TimeStamp &obj);
    friend std::istream& operator>>(std::istream& is, TimeStamp &obj);

    TimeStamp operator+(const TimeStamp &obj);
    TimeStamp& operator+=(const TimeStamp &obj);
};

#endif