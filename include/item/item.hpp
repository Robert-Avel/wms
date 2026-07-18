#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>
#include "identificator.hpp"
typedef uint32_t cents;


/*É a representação de um registro de um item */
class Item {

    ID identificator; //Codebar too
    std::string global_name;

    double cubic;
    double weight;
    cents brute_value;


    public:
    Item(uint64_t identificator_, IdMode identificator_type,std::string global_name_, double m3_, double weight_, cents brute_value_):
        identificator(identificator_, identificator_type), global_name(global_name_), cubic(m3_), weight(weight_), brute_value(brute_value_) {}


    std::string getID() const;
    const std::string& getGlobalName() const;
    double getCubic() const;
    double getWeight() const;
    cents getBruteValue() const;

    std::string formatData() const;
};
