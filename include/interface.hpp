#pragma once
#include "IDed_map.hpp"
#include "item.hpp"
#include <cstdint>
#include <list>
#include <string>
#include <utility>


class WMRobert {
    IDedMap<Item> itens;
    std::string item_file_name;

    public:
        WMRobert() = default;

        bool itemLoad();
        bool itemSave();

        ID itemNew(std::string name, double weight, double cubic, cents value);
        Item* itemInfo(ID id_);
        std::list<std::pair<ID, const Item*>> itemList(uint32_t page);
        std::list<std::pair<ID, const Item*>> searchItem(std::string name);
};
