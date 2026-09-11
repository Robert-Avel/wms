#pragma once
#include "item.hpp"
#include "volume.hpp"
#include "group.hpp"
#include <sqlite3.h>
#include <functional>


#define ITEM_TABLE_NAME "items"
#define VOLUME_TABLE_NAME "volumes"

#define ITEM_TABLE(NAME) NAME "(hash BIGINT PRIMARY KEY, id INTEGER, group_id INTEGER, global_name TEXT, cubic DOUBLE, weight DOUBLE, brute_value INTEGER)"
#define VOLUME_TABLE(NAME) NAME "(hash BIGINT PRIMARY KEY, id INTEGER, group_id INTEGER, item_id INTEGER, volume_batch INTEGER, weight DOUBLE, volume_m3 DOUBLE, value INTEGER)"

#define CREATE_IFNE "CREATE TABLE IF NOT EXISTS "

#define TABLE_NEW(TABLE) CREATE_IFNE TABLE ";"

#define TABLE_INIT TABLE_NEW(ITEM_TABLE(ITEM_TABLE_NAME)) TABLE_NEW(VOLUME_TABLE(VOLUME_TABLE_NAME))

class WMSData {
    sqlite3* db;
    char* err_sql;

    std::size_t hashID(uint64_t group, uint64_t id);
    std::string formatItemInsertion(Item& i);
    static int itemCallBack(void*, int argc, char** argv, char** argv_name);

    public:
    GroupMap<Volume> volumes;
    GroupMap<Item> itens;
    
    WMSData(std::string data_base);
    ~WMSData();


    bool saveItem(uint64_t group, uint64_t id);
    bool saveItem();
    bool loadItem(uint64_t group_id, uint64_t id);
    bool loadItem();
    bool deleteItem(uint64_t group_id, uint64_t id);


    bool saveVolume();
    bool loadVolume();
    bool deleteVolume();
};