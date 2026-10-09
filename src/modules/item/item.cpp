#include "item/item.hpp"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

inline double moneyFormatSimple(uint32_t __v) {
    return  __v / 100.0;
}


const std::string& Item::getGlobalName() const {
    return this->global_name;
}

const uint32_t& Item::getCubic() const {return this->cubic_cm;}
const uint32_t& Item::getWeight() const {return this->weight_g;}
const cents& Item::getBruteValue() const {return this->value;}

std::string Item::formatData() const {
    std::ostringstream buffer;
    buffer << "G_Name: " << global_name << "\n"
           << "M3: " << cubic_cm << "\n"
           << "Weight: " << weight_g << "\n"
           << "Value: " << moneyFormatSimple(value) << "\n";

    return buffer.str();
}
