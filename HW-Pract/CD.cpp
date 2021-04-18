#include "CD.hpp"

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

double CD::priceForGB() const {
    return (price/spaceTotal);
}

size_t CD::freeSpacePercentage() const {
    return (100 * ((spaceAvailable)/spaceTotal));
}

void CD::print() const {
    std::cout <<  "\nCD information: \n"
    << "\nmanufacturer: " << manufacturer
    << "\nAvailable space: " << spaceAvailable << " GB"
    << "\nTotal space: " << spaceTotal << " GB"
    << "\nFree space percentage: " << freeSpacePercentage() << '%'
    << "\nPrice: " << price << " BGN"
    << "\nPrice for GB: " << priceForGB() << " BGN";
}

CD& CD::operator-=(size_t mb) {
    if (rewritable && spaceAvailable + (0.001 * mb) <= spaceTotal) {
        spaceAvailable = spaceAvailable + (0.001 * mb);
    }
    return *this;
}

CD& CD::operator+=(size_t mb) {
    if (rewritable && spaceAvailable - (0.001 * mb) >= 0) {
        spaceAvailable = spaceAvailable - (0.001 * mb);
    }
    return *this;
}