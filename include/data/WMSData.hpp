#pragma once
#include "item.hpp"
#include "volume.hpp"
#include "group.hpp"
#include "GroupPrefixMap.hpp"
#include <sqlite3.h>
#include <functional>
#include "ItemDataMngr.hpp"


#define VOLUME_TABLE_NAME "volumes"
#define GROUP_TABLE_NAME "groups"
#define INDEX_TABLE_NAME "indx"

#define VOLUME_TABLE(NAME) NAME "(hash BIGINT PRIMARY KEY, id INTEGER, group_id INTEGER, item_id INTEGER, volume_batch INTEGER, weight DOUBLE, volume_m3 DOUBLE, value INTEGER)"
#define GROUP_TABLE(NAME) NAME "(id INTEGER PRIMARY KEY, name TEXT)"
#define INDEX_TABLE(NAME) NAME "(table BIGINT, group BIGINT,last_index BIGINT)"

#define CREATE_IFNE "CREATE TABLE IF NOT EXISTS "

#define TABLE_NEW(TABLE) CREATE_IFNE TABLE ";"

#define TABLE_INIT \
TABLE_NEW(ITEM_TABLE(ITEM_TABLE_NAME)) \
TABLE_NEW(VOLUME_TABLE(VOLUME_TABLE_NAME)) \
TABLE_NEW(GROUP_TABLE(GROUP_TABLE_NAME)) \
TABLE_NEW(INDEX_TABLE(INDEX_TABLE_NAME))

class WMSData {
    sqlite3* db;
    char* err_sql;


    static int groupCallBack(void*, int argc, char** argv, char** argv_name);
    static int indexCallBack(void*, int argc, char** argv, char** argv_name);

    public:
    uint64_t indexer;
    GroupMap<Volume> volumes;
    GroupMap<Item> itens;
    GroupPrefixMap group_translation;

    
    WMSData(std::string data_base);
    ~WMSData();

    void saveIndex(std::string name, uint64_t group, uint64_t index);
    uint64_t getIndex(std::string name, uint64_t group);

    bool saveGroupMap(uint64_t id, std::string name);
    bool saveGroupMap();
    bool loadGroupMap();
    bool deleteGroupMap(uint64_t group_id);
};