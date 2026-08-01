#pragma once

#include <cstdint>
#include <string>


namespace basec
{
    enum StdMode {
        NUMERIC = 10,
        ALPHABETIC = 26,
        ALPHANUMERIC = 36,
        HEXADECIMAL = 16,
        OCTAL = 8
    };


    std::string fintToBase(uint64_t value, uint8_t base = 36);
    std::string fintToAlphabetic(uint32_t value, uint8_t base = 26);

    std::string intToBase(uint64_t value, StdMode mode_);

    uint64_t fbaseToInt(std::string code, uint8_t base, bool has_numbers);
    uint64_t baseToInt(std::string code, StdMode mode_);

}
