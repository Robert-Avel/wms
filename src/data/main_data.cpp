#include "main_data.hpp"
#include <exception>
#include <sstream>
#include <iostream>
#include <string>


WMSData::WMSData(std::string data_base): err_sql(nullptr) {
    int r = sqlite3_open(data_base.c_str(), &db);
    if(r != SQLITE_OK) {db = nullptr;}

    r = sqlite3_exec(db, TABLE_INIT, nullptr, nullptr, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
}


std::size_t WMSData::hashID(uint64_t group, uint64_t id) {
    std::hash<std::string> hasher;
    std::stringstream final_id;

    final_id << id << "-" << group;
    return hasher(final_id.str());
}



//static
int WMSData::itemCallBack(void* cls, int argc, char** argv, char** argv_name) {
    if(argc != 7) {return 1;}

    uint64_t g_id = atol(argv[2]);
    
    reinterpret_cast<WMSData*>(cls)->itens.newGroup(g_id); //Open if not exist
    auto g = reinterpret_cast<WMSData*>(cls)->itens.getGroup(g_id);
    g->insert(atol(argv[1]), Item(argv[3], atof(argv[4]), atof(argv[5]), atoi(argv[6]), atol(argv[1]), atol(argv[2])));

    for(int i = 0; i < argc; i++) {std::cout << " | " << argv[i];}
    std::cout << " |\n";

    return 0;
}


WMSData::~WMSData() {
    sqlite3_close(db);
}


std::string WMSData::formatItemInsertion(Item& i) {
    std::stringstream buffer;
    buffer << "INSERT INTO " << ITEM_TABLE_NAME << " VALUES" << " ("
    << hashID(i.getGroup(), i.getID()) << "," 
    << i.getID() << "," 
    << i.getGroup() << ","
    << "'" << i.getGlobalName() << "',"
    << i.getCubic() << "," 
    << i.getWeight() << "," 
    << i.getBruteValue() << ");";
    std::cout << buffer.str() << "\n";
    return buffer.str();
}


bool WMSData::saveItem() {
    auto it = itens.begin();
    while (it != itens.end())
    {
        auto it_in = it->second.begin();
        while (it_in != it->second.end())
        {
            saveItem(it->first, it_in->first);
            it_in++;
        }
        it++;
    }
}


bool WMSData::saveItem(uint64_t group_id, uint64_t id) {
    IDedMap<Item>* group = itens.getGroup(group_id);
    if(group == nullptr) {return false;}

    Item* i = group->getItem(id);
    if(i == nullptr) {return false;}

    sqlite3_exec(db, formatItemInsertion(*i).c_str(), nullptr, nullptr, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
    return true;
}

bool WMSData::loadItem(uint64_t group_id, uint64_t id) {
    std::stringstream query;
    query << "SELECT * FROM " << ITEM_TABLE_NAME << " WHERE group_id == " << group_id << " AND id == " << id << ";";
    sqlite3_exec(db, query.str().c_str(), &itemCallBack, this, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
    return true;
}

bool WMSData::loadItem() {
    std::stringstream query;
    query << "SELECT * FROM " << ITEM_TABLE_NAME << ";";
    sqlite3_exec(db, query.str().c_str(), &itemCallBack, this, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
    }
    return true;
}