#include "WMSData.hpp"
#include <exception>
#include <sstream>
#include <iostream>
#include <string>


WMSData::WMSData(std::string data_base): err_sql(nullptr), indexer(0) {
    int r = sqlite3_open(data_base.c_str(), &db);
    if(r != SQLITE_OK) {db = nullptr;}

    r = sqlite3_exec(db, TABLE_INIT, nullptr, nullptr, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }

    loadGroupMap();
}

WMSData::~WMSData() {
    for(auto& i: itens) {
        saveIndex(ITEM_TABLE_NAME, i.first, i.second.showNexID());
    }

    sqlite3_close(db);
}



//static
int WMSData::groupCallBack(void* cls, int argc, char** argv, char** argv_name) {
    if(argc != 2) {return 1;}

    auto& g_names = reinterpret_cast<WMSData*>(cls)->group_translation;
    g_names.insert({argv[1], atol(argv[0])});
    return 0;
}

    
int WMSData::indexCallBack(void* cls, int argc, char** argv, char** argv_name) {
    if(argc != 2) {return 1;}
    
    reinterpret_cast<WMSData*>(cls)->indexer = atol(argv[2]);
}



void WMSData::saveIndex(std::string name, uint64_t group, uint64_t index) {
    std::stringstream query;
    query << "INSERT INTO" << INDEX_TABLE_NAME << "(table, last_index) VALUES " << "(" << name << ", " << group << ", " << index << ");";
    sqlite3_exec(db, query.str().c_str(), nullptr, nullptr, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
}

uint64_t WMSData::getIndex(std::string name, uint64_t group) {
    std::stringstream query;
    query << "SELECT * FROM " << INDEX_TABLE_NAME << " WHERE table == \"" << name << "\"AND group == " << "group" << ";";
    sqlite3_exec(db, query.str().c_str(), &indexCallBack, this, &err_sql);
        if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
    return indexer;
}


bool WMSData::saveGroupMap(uint64_t id, std::string name) {
    std::stringstream query;
    query << "INSERT INTO " << GROUP_TABLE_NAME << "(id, name) VALUES" 
     << "(" << id << ", \"" << name << "\");";

    sqlite3_exec(db, query.str().c_str(), nullptr, nullptr, &err_sql);
        if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
        return false;
    }
    return true;
}

bool WMSData::saveGroupMap() {
    if(group_translation.empty()) {return false;}

    for(auto& it: group_translation) {
        this->saveGroupMap(it.second, it.first);

    }   
}


bool WMSData::loadGroupMap() {
    sqlite3_exec(db, "SELECT * FROM " GROUP_TABLE_NAME ";", &groupCallBack, this, &err_sql);
        if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
        return false;
    }
    return true;

}


