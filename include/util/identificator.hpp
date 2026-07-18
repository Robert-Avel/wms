#include <cstdint>
#include <string>

enum IdMode {
    NUMERIC,
    ALPHABETIC,
    ALPHANUMERIC,
    HEXADECIMAL,
    OCTAL
};

class ID {
    uint64_t id;
    IdMode std_mode;

    public:
    ID(uint64_t id_, IdMode std_mode_): id(id_), std_mode(std_mode_) {}

    uint64_t getID() const;

    std::string Str() const;

    std::string Str(IdMode m__) const;

    bool operator==(const ID& other) {
        return this->id == other.id;
    }

    bool operator==(const uint64_t& other) {
        return this->id == other;
    }
};
