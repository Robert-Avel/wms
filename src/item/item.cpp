#include "item.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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

Item::Item(std::ifstream& file) {
    if (!file) {
        std::cerr << "File is not open or its damaged\n";
        return;
    }

    size_t g_name_size_;

    double cubic_;
    double weight_;
    cents brute_value_;


    file.read((char*) &g_name_size_, sizeof(size_t));
    std::string g_name(g_name_size_, '\0');
    file.read((char*) g_name.data(), sizeof(g_name_size_));

    file.read((char*) &cubic_, sizeof(double));
    file.read((char*) &weight_, sizeof(double));
    file.read((char*) &brute_value_, sizeof(cents));

    this->global_name = g_name;
    this->cubic = cubic_;
    this->weight = weight_;
    this->brute_value = brute_value_;
}


bool Item::saveData(std::ofstream& file) {
    if (!file) {
        std::cerr << "File is not open or its damaged\n";
        return false;
    }

    size_t g_name_size = global_name.size();
    file.write((char*) &g_name_size, sizeof(size_t));
    file.write(global_name.c_str(), sizeof(g_name_size));

    file.write((char*) &cubic, sizeof(double));
    file.write((char*) &weight, sizeof(double));
    file.write((char*) &brute_value, sizeof(cents));

    return true;
}
