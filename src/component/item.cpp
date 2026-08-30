#include "item.hpp"
#include "byte_serializator.hpp"
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

double Item::getCubic() const {return this->cubic;}
double Item::getWeight() const {return this->weight;}
cents Item::getBruteValue() const {return this->brute_value;}

std::string Item::formatData() const {
    std::ostringstream buffer;
    buffer << "G_Name: " << global_name << "\n"
           << "M3: " << cubic << "\n"
           << "Weight: " << weight << "\n"
           << "Value: " << moneyFormatSimple(brute_value) << "\n";

    return buffer.str();
}

Item::Item(ByteS& bytes) : IDedObj() {
    if (bytes.size() == 0) {
        std::cerr << "File Empty\n";
        return;
    }

    bytes.pop<uint64_t>(this->id)
        .pop<uint32_t>(this->group)
        .pop(this->global_name);
    bytes.pop<double>(this->cubic)
        .pop<double>(this->weight)
        .pop<cents>(this->brute_value);
}



ByteS Item::getBytes() {
    ByteS buffer;

    buffer.append<uint64_t>(id)
        .append<uint32_t>(group)
        .append(global_name)
        .append<double>(cubic)
        .append<double>(weight)
        .append<cents>(brute_value);


    return buffer;
}
