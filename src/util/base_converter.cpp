#include "base_converter.hpp"
#include <algorithm>
#include <cstring>


static std::string convert(uint32_t value, uint8_t base, const char* using__) {
    if (value == 0) {return "0";}
    if(base < 2 || base > strlen(using__)) {return "";}

    std::string buffer;
    buffer.reserve(32);
    while (value > 0) {
        buffer.push_back(using__[value % base]);
        value /= base;
    }
    std::reverse(buffer.begin(), buffer.end());
    return buffer;
}


std::string intToBase(uint32_t value, uint8_t base) {
    return convert(value, base, digit);
}

std::string intToAlphabetic(uint32_t value, uint8_t base) {
    return convert(value, base, digit_alphabetic);
}
