#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>
typedef uint32_t cents;
typedef uint32_t cubic;

class Item {
    public:

    uint32_t identifier; //Codebar too
    std::string global_name;
    cubic m3;
    double weight;
    cents brute_value;


    Item(uint32_t identifier_,
        std::string global_name_,
        cubic m3_,
        double weight_,
        cents brute_value_);

     std::string formatData() const;
};
