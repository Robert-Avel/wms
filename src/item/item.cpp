#include "item.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>

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

bool Item::saveData(std::ofstream& file) {
    if (!file) {
        std::cerr << "File is not open or its damaged\n";
        return false;
    }
    file.write((char*) this->bruteID(), sizeof(uint64_t));

    size_t g_name_size = global_name.size();
    file.write((char*) &g_name_size, sizeof(size_t));
    const char* g_name = global_name.c_str();
    file.write((char*) &g_name, sizeof(char));

    file.write((char*) &cubic, sizeof(double));
    file.write((char*) &weight, sizeof(double));
    file.write((char*) &brute_value, sizeof(cents));

    return true;
}
