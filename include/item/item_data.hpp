#pragma once

#include <sqlite3.h>
#include "identificator.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstdint>
#include <fstream>
#include <unordered_map>


using ItemMap = std::unordered_map<uint32_t, Item>;


class ItemData {
    ItemMap data;
    IdMode code_mode;
    uint64_t next_id;

    uint64_t getNewID();

    public:
    ItemData() = default;
    ItemData(IdMode code_mode_): code_mode(code_mode_), next_id(1) {};
    ItemData(std::ifstream& file);

    Status newItem(const Item i);
    Status newItem(const std::string global_name_, double m3_, double weight_, cents brute_value_);

    Status removeItem(uint64_t id);
    Status removeItem(std::string& id);

    const Item* getItem(uint64_t id);
    const Item* getItem(std::string& id);


    const ItemMap::const_iterator begin();
    const ItemMap::const_iterator end();

    bool saveData(std::ofstream& file);
};
