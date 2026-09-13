#pragma once
#include "item.hpp"
#include "IDed_map.hpp"
#include "group.hpp"
#include "WMSData.hpp"
#include "GroupPrefixMap.hpp"
#include <cstdint>
#include <list>
#include <string>


class ItemSys {
    GroupMap<Item>& data_base;
    GroupPrefixMap& group_names;

    public:
    ItemSys(WMSData& db): data_base(db.itens), group_names(db.group_translation) {}

    uint64_t createGroup(std::string prefix);
    GroupPrefixMap getGroups() const;


    uint64_t createItem(std::string group, std::string name, double weight, double cubic, cents value);
    Item* infoItem(std::string group, uint64_t id_);
    std::list<const Item*> list(std::string prefix, uint32_t page);
    std::list<const Item*> search(std::string name);
};
