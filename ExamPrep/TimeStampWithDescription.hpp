#ifndef TIMESTAMPWITHDESCRIPTION_HPP
#define TIMESTAMPWITHDESCRIPTION_HPP

#include "TimeStamp.hpp"
#include <cstring>

class TimeStampWithDescription : public TimeStamp {

private:
    std::string desc;

public:
    TimeStampWithDescription();
    TimeStampWithDescription(const unsigned long time_, const std::string& desc_);

    std::string getDescription() const;
    void setDescription(const std::string& str_);
    
    friend std::ostream& operator<<(std::ostream& os, const TimeStampWithDescription &obj);
    friend std::istream& operator>>(std::istream& is, TimeStampWithDescription &obj);
};

#endif