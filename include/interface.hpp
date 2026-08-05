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
        WMRobert(std::string item_file_name_):
        itens(basec::StdMode::HEXADECIMAL), item_file_name(item_file_name_) {};

        bool itemLoad();
        bool itemSave();

        cID itemNew(std::string name, double weight, double cubic, cents value);
        Item* itemInfo(cID id_);
        std::list<std::pair<cID, const Item*>> itemList(uint32_t page);
        std::list<std::pair<cID, const Item*>> searchItem(std::string name);
};
