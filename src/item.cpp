#include "item.hpp"
#include <cstdint>
#include <sstream>

inline double moneyFormatSimple(uint32_t __v) {
    return  __v / 100.0;
}

Item::Item(uint32_t identifier_,std::string global_name_, cubic m3_,double weight_,cents brute_value_):
identifier(identifier_)
{
    global_name = global_name_;
    m3 = m3_;
    weight = weight_;
    brute_value = brute_value_;
}

std::string Item::formatData() const {
    std::ostringstream buffer;
    buffer << "ID: " << identifier << "\n"
           << "G_Name: " << global_name << "\n"
           << "M3: " << m3 << "\n"
           << "Weight: " << weight << "\n"
           << "Value: " << moneyFormatSimple(brute_value) << "\n";

    return buffer.str();
}
