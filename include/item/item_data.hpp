#pragma once

#include "item.hpp"
#include "status.hpp"
#include <cstdint>
#include <unordered_map>


class ItemData {
    std::unordered_map<uint32_t, Item> data;

    public:
    ItemData() = default;

    Status newItem(const Item i);
    Status newItem(const ID identifier_, const std::string global_name_, double m3_, double weight_, cents brute_value_);

    Status removeItem(ID& id);

    const Item* getItem(ID& id);
};
