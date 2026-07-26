#pragma once

#include <cstdint>
#include <string>

enum IdMode {
    NUMERIC = 10,
    ALPHABETIC = 26,
    ALPHANUMERIC = 36,
    HEXADECIMAL = 16,
    OCTAL = 8
};





class ID {
    uint64_t id;
    IdMode std_mode;

    public:
    ID() = default;
    ID(uint64_t id_, IdMode std_mode_): id(id_), std_mode(std_mode_) {}

    uint64_t bruteID() const;

    std::string Str() const;

    std::string Str(IdMode m__) const;

    IdMode getMode() const;

    bool operator==(const ID& other) {
        return this->id == other.id;
    }

    bool operator==(const uint64_t& other) {
        return this->id == other;
    }


    static uint8_t hasNum(IdMode i__);
};
