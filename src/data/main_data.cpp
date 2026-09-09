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
    if(r != SQLITE_OK) {return;}
}

//static
int WMSData::itemCallBack(void* cls, int argc, char** argv, char** argv_name) {
    if(argc != 6) {return 1;}

    uint64_t g_id = atol(argv[1]);
    
    reinterpret_cast<WMSData*>(cls)->itens.newGroup(g_id);
    auto g = reinterpret_cast<WMSData*>(cls)->itens.getGroup(g_id);
    g->insert(atol(argv[0]), Item(argv[2], atof(argv[3]), atof(argv[4]), atoi(argv[5]), atol(argv[0]), atol(argv[1])));

    Item* i = g->getItem(atoi(argv[0]));
    if(i == nullptr) {std::cout << "OOOOPSSS\n";} else {std::cout << i->formatData() << "\n";}

    return 0;
}


WMSData::~WMSData() {
    sqlite3_close(db);
}


std::string WMSData::formatItemInsertion(Item& i) {
    std::stringstream buffer;
    buffer << "INSERT INTO " << ITEM_TABLE_NAME << " VALUES" << " ("
    << i.getID() << "," 
    << i.getGroup() << ","
    << "'" << i.getGlobalName() << "',"
    << i.getCubic() << "," 
    << i.getWeight() << "," 
    << i.getBruteValue() << ");";
    std::cout << buffer.str() << "\n";
    return buffer.str();
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
bool WMSData::deleteItem() {

}