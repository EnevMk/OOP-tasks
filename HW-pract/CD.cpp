#include "CD.hpp"
#include <iomanip>

void strCpy(char *dest, const char *src) {
    //src[CONST_MANUFACTURER_SIZE] = '\0';

    for (size_t i = 0; i < CONST_MANUFACTURER_SIZE - 1; ++i) {
        dest[i] = src[i];
    }
    dest[CONST_MANUFACTURER_SIZE - 1] = '\0';
}

CD::CD() {
    strCpy(manufacturer, "Unknown");
    spaceAvailable = 0;
    spaceTotal = 0;
    rewritable = 0;
    price = 0;
    format = DiscFormat::CD_ROM;
}

CD::CD(const char* manufacturer_, const double space_, const bool rewritable_, const double price_) {
    strCpy(manufacturer, manufacturer_);
    spaceTotal = space_;
    spaceAvailable = spaceTotal;
    rewritable = rewritable_;
    price = price_;
    format = DiscFormat::CD_ROM;
}

float CD::priceForGB() const {
    return (price/(float)spaceTotal);
}

size_t CD::freeSpacePercentage() const {
    return (100 * spaceAvailable/spaceTotal);
}

size_t CD::occupiedSpacePercentage() const {
    return (100 * (spaceTotal - spaceAvailable)/spaceTotal);
}

void CD::print() const {
    
    std::cout <<  "\nCD information: \n"
    << "\nmanufacturer: " << manufacturer
    << "\nAvailable space: " << spaceAvailable << " GB"
    << "\nTotal space: " << spaceTotal << " GB"
    << "\nFree space percentage: " << freeSpacePercentage() << '%'
    << "\nOccupied space percentage: " << occupiedSpacePercentage() << '%'
    << "\nPrice: " << price << " BGN"
    << "\nPrice for GB: " << std::setprecision(2) << std::fixed << priceForGB() << " BGN";
}

CD& CD::operator-=(const size_t mb) {
    if (rewritable && spaceAvailable + (0.001 * mb) <= spaceTotal) {
        spaceAvailable = spaceAvailable + (0.001 * mb);
    }
    return *this;
}

CD& CD::operator+=(const size_t mb) {
    if (rewritable && spaceAvailable - (0.001 * mb) >= 0) {
        spaceAvailable = spaceAvailable - (0.001 * mb);
    }
    return *this;
}