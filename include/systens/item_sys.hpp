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
    sqlite3*& db_link;
    GroupMap<Item>& data_base;
    GroupPrefixMap& group_names;

    public:
    ItemSys(WMSData& db): data_base(db.itens), group_names(db.group_translation), db_link(db.db) {}


    uint64_t createItem(std::string group, std::string name, double weight, double cubic, cents value);
    uint64_t createItem(uint64_t group, std::string name, double weight, double cubic, cents value);
    Item* infoItem(std::string group, uint64_t id_);
    Item* infoItem(uint64_t group, uint64_t id_);
    std::list<const Item*> list(std::string group, uint32_t page);
    std::list<const Item*> list(uint64_t group, uint32_t page);
    std::list<const Item*> search(std::string name);
    bool eraseItem(uint64_t group, uint64_t id_);
    bool eraseItem(std::string group, uint64_t id_);
};
