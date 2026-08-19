#pragma once
#include "item.hpp"
#include "IDed_map.hpp"
#include <cstdint>
#include <list>
#include <string>

class ItemSys {
    IDedMap<Item>& itens;

    public:
    ItemSys(IDedMap<Item>& db): itens(db) {}

    uint64_t create(std::string name, double weight, double cubic, cents value);
    Item* info(uint64_t id_);
    std::list<std::pair<uint64_t, const Item*>> list(uint32_t page);
    std::list<std::pair<uint64_t, const Item*>> search(std::string name);
};
