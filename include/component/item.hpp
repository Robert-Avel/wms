#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <stdint.h>
#include "IDed_obj.hpp"
#include "byte_serializator.hpp"
typedef uint32_t cents;


/*É a representação de um registro de um item */
class Item: public IDedObj {
    std::string global_name;

    double cubic;
    double weight;
    cents brute_value;


    public:
    Item() = default;
    Item(std::string global_name_, double m3_, double weight_, cents brute_value_, uint64_t id = 0, uint64_t group = 0):
         IDedObj(id, group), global_name(global_name_), cubic(m3_), weight(weight_), brute_value(brute_value_) {}

    Item(ByteS& bytes);


    const std::string& getGlobalName() const;
    double getCubic() const;
    double getWeight() const;
    cents getBruteValue() const;

    std::string formatData() const;

    ByteS getBytes();
};
