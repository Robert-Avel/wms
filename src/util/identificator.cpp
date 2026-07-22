#include "identificator.hpp"
#include "base_converter.hpp"
#include <cstdint>
#include <string>
#include <math.h>


uint64_t ID::bruteID() const {
    return this->id;
}

std::string ID::Str() const {
    return Str(std_mode);
}

IdMode ID::getMode() const {
    return this->std_mode;
}


std::string ID::Str(IdMode m__) const {
    switch (m__) {
        case NUMERIC:
            return std::to_string(this->id);

        case ALPHABETIC:
            return intToAlphabetic(this->id);

        case ALPHANUMERIC:
            return intToBase(this->id);

        case HEXADECIMAL:
            return intToBase(this->id, 16);

        case OCTAL:
            return intToBase(this->id, 8);

        default:
            return "";
    }
}
