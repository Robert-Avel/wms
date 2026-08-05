#include "base_converter.hpp"
#include <cmath>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <string>

namespace basec {
    static const char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const char digit_alphabetic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

template <typename I>
inline uint64_t m_pow(I base, I exp) {

    if(exp == 0) {return 1;}
    uint64_t acc = 1;
    for(I i = 0; i < exp; i++) {
        acc *= base;
    }
    return acc;
}


static bool checkDigit(std::string code, uint8_t base, bool has_numbers) {
    const char* digit_base = has_numbers ? basec::digit : basec::digit_alphabetic;
    uint8_t len = strlen(digit_base);


    for(char& c: code) {
        for(uint8_t i = 0; i < len; i++) {
            if (c == digit_base[i] && i > base) {
                return false;
            }
        }
    }
    return true;
}


static std::string convert(uint64_t value, uint8_t base, const char* using__) {
    if (value == 0 ) {
        if(using__ == basec::digit) {return "0";}
        else return "A";
    }

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


uint64_t basec::fbaseToInt(std::string code, uint8_t base, bool has_numbers) {
    if(!checkDigit(code, base, has_numbers)) {
        return 0;
    }

    const char* digit_base = has_numbers ? digit : digit_alphabetic;
    uint64_t acc = 0;
    std::reverse(code.begin(), code.end());

    for(uint8_t c = 0; c < code.size(); c++) {
        char current_char = code[c];
        for(uint8_t i = 0; i < base; i++) {
            if(current_char == digit_base[i]) {
                acc += i * m_pow<uint64_t>(base, c);
                break;
            }
        }
    }
    return acc;
}


std::string basec::fintToBase(uint64_t value, uint8_t base) {
    return convert(value, base, digit);
}

std::string basec::intToBase(uint64_t value, StdMode mode_) {
    switch (mode_) {
        case NUMERIC:
            return std::to_string(value);

        case ALPHABETIC:
            return basec::fintToAlphabetic(value);

        case ALPHANUMERIC:
            return basec::fintToBase(value);

        case HEXADECIMAL:
            return basec::fintToBase(value, 16);

        case OCTAL:
            return basec::fintToBase(value, 8);

        default:
            return "ERR";
    }
}


uint64_t basec::baseToInt(std::string code, basec::StdMode mode_) {
    bool has_num =  mode_ != basec::StdMode::ALPHABETIC;

    return basec::fbaseToInt(code, mode_, has_num);
}

std::string basec::fintToAlphabetic(uint32_t value, uint8_t base) {
    return convert(value, base, digit_alphabetic);
}
