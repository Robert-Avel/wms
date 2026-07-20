#include "item.hpp"
#include <cstdint>
#include <sstream>

inline double moneyFormatSimple(uint32_t __v) {
    return  __v / 100.0;
}

const ID& Item::getID() const {
    return this->identificator;
}

const uint64_t Item::bruteID() const {
    return this->identificator.bruteID();
}

const std::string& Item::getGlobalName() const {
    return this->global_name;
}
double Item::getCubic() const {return this->cubic;}
double Item::getWeight() const {return this->weight;}
cents Item::getBruteValue() const {return this->brute_value;}

std::string Item::formatData() const {
    std::ostringstream buffer;
    buffer << "ID: " << getID().Str() << "\n"
           << "G_Name: " << global_name << "\n"
           << "M3: " << cubic << "\n"
           << "Weight: " << weight << "\n"
           << "Value: " << moneyFormatSimple(brute_value) << "\n";

    return buffer.str();
}
