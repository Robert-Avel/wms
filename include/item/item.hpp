#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>

typedef std::string ID;
typedef uint32_t cents;


/*É a representação de um registro de um item */
class Item {

    ID identifier; //Codebar too
    std::string global_name;

    double cubic;
    double weight;
    cents brute_value;


    public:
    Item(ID identifier_, std::string global_name_, double m3_, double weight_, cents brute_value_):
        identifier(identifier_), global_name(global_name_), cubic(m3_), weight(weight_), brute_value(brute_value_) {}


    const ID& getID() const;
    std::string& getGlobalName() const;
    double getCubic() const;
    double getWeight() const;
    cents getBruteValue() const;

     std::string formatData() const;
};
