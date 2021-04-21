#ifndef CD_HPP
#define CD_HPP
#include <iostream>
#define CONST_MANUFACTURER_SIZE 20

enum class DiscFormat {
    AudioCD,
    SuperAudioCD,
    CD_MIDI,
    CD_ROM,
    VCD,
    SuperVideoCD,
    CD_i,
    CD_i_ready
};

class CD {

private:
    char manufacturer[CONST_MANUFACTURER_SIZE];
    double spaceAvailable;
    double spaceTotal;
    bool rewritable;
    size_t price;
    DiscFormat format;

public:
    CD();
    CD(const char* manufacturer_, const double space_, const bool rewritable_, const double price_);
    float priceForGB() const;
    size_t occupiedSpacePercentage() const;
    size_t freeSpacePercentage() const;
    void print() const;
    CD& operator-=(const size_t mb_);
    CD& operator+=(const size_t mb_);

};

#endif