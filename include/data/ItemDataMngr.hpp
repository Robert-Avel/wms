#include <sqlite3.h>
#include "group.hpp"
#include "item.hpp"
#include "GroupPrefixMap.hpp"
#include <exception>

#define ITEM_TABLE_NAME "items"
#define ITEM_TABLE(NAME) NAME "(hash BIGINT PRIMARY KEY, id INTEGER, group_id INTEGER, global_name TEXT, cubic DOUBLE, weight DOUBLE, brute_value INTEGER)"


class ItemDataMngr
{
private:
    sqlite3*& opened_db;
    GroupMap<Item> itens;
    GroupPrefixMap& group_translation;

    static int ItemDataMngr::itemCallBack(void* cls, int argc, char** argv, char** argv_name);
    std::string formatItemInsertion(Item& i);

public:
    ItemDataMngr(sqlite3*& o_db, GroupPrefixMap& group_map): opened_db(o_db), group_translation(group_map) {}

    bool saveItem(uint64_t group, uint64_t id);
    bool saveItem();
    bool loadItem(uint64_t group_id, uint64_t id);
    bool loadItem();
    bool deleteItem(uint64_t group_id, uint64_t id);

};
