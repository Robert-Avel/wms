#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>
typedef uint32_t cents;


/*É a representação de um registro de um item */
class Item {
    std::string global_name;

    uint32_t cubic_cm;
    uint32_t weight_g;
    cents value;


    public:
    Item() = default;
    Item(std::string global_name_, uint32_t m3_, uint32_t weight_, cents brute_value_):
        global_name(global_name_), cubic_cm(m3_), weight_g(weight_), value(brute_value_) {}


    const std::string& getGlobalName() const;
    const uint32_t& getCubic() const;
    const uint32_t& getWeight() const;
    const cents& getBruteValue() const;

    std::string formatData() const;

};
