#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <stdint.h>
#include "IDed_obj.hpp"
typedef uint32_t cents;


/*É a representação de um registro de um item */
class Item: public IDedObj {
    std::string global_name;

    double cubic;
    double weight;
    cents brute_value;


    public:
    Item() = default;
    Item(std::string global_name_, double m3_, double weight_, cents brute_value_):
         IDedObj(), global_name(global_name_), cubic(m3_), weight(weight_), brute_value(brute_value_) {}

    Item(std::ifstream& file);


    const std::string& getGlobalName() const;
    double getCubic() const;
    double getWeight() const;
    cents getBruteValue() const;

    std::string formatData() const;

    bool saveData(std::ofstream& file);

};
