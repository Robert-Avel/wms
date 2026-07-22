#pragma once

#include "identificator.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include <vector>


class ItemData {
    std::unordered_map<uint32_t, Item> data;
    IdMode code_mode;


    public:
    ItemData(IdMode code_mode_): code_mode(code_mode_) {};
    ItemData(IdMode code_mode_, std::vector<std::byte> data);

    Status newItem(const Item i);
    Status newItem(const ID identifier_, const std::string global_name_, double m3_, double weight_, cents brute_value_);

    Status removeItem(ID& id);

    const Item* getItem(ID& id);

    bool saveData(std::ofstream& file);
};
