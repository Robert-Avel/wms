#include "ItemDataMngr.hpp"
#include <iostream>
#include <sstream>

//static
int ItemDataMngr::itemCallBack(void* cls, int argc, char** argv, char** argv_name) {
    if(argc != 7) {return 1;}

    uint64_t g_id = atol(argv[2]);
    
    static_cast<GroupMap<Item>*>(cls)->newGroup(g_id); //Open if not exist
    auto g = static_cast<GroupMap<Item>*>(cls)->getGroup(g_id);
    g->insert(atol(argv[1]), Item(argv[3], atof(argv[4]), atof(argv[5]), atoi(argv[6]), atol(argv[1]), atol(argv[2])));

    for(int i = 0; i < argc; i++) {std::cout << " | " << argv[i];}
    std::cout << " |\n";

    return 0;
}

std::string ItemDataMngr::formatItemInsertion(Item& i) {
    std::stringstream buffer;
    buffer << "INSERT INTO " << ITEM_TABLE_NAME << " VALUES" << " ("
    << i.hashID() << "," 
    << i.getID() << "," 
    << i.getGroup() << ","
    << "'" << i.getGlobalName() << "',"
    << i.getCubic() << "," 
    << i.getWeight() << "," 
    << i.getBruteValue() << ");";
    std::cout << buffer.str() << "\n";
    return buffer.str();
}

bool ItemDataMngr::saveItem() {
    for(auto& it: itens) {
        for(auto& it_in: it.second) {
            saveItem(it.first, it_in.first);

        }
    }
    return true;
}


bool ItemDataMngr::saveItem(uint64_t group_id, uint64_t id) {
    char* err_sql;
    IDedMap<Item>* group = itens.getGroup(group_id);
    if(group == nullptr) {return false;}

    Item* i = group->getItem(id);
    if(i == nullptr) {return false;}

    sqlite3_exec(opened_db, formatItemInsertion(*i).c_str(), nullptr, nullptr, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
        return false;
    }
    return true;
}

bool ItemDataMngr::loadItem(uint64_t group_id, uint64_t id) {
    char* err_sql;
    std::stringstream query;
    
    query << "SELECT * FROM " << ITEM_TABLE_NAME << " WHERE group_id == " << group_id << " AND id == " << id << ";";
    sqlite3_exec(opened_db, query.str().c_str(), &itemCallBack, this, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
        return false;
    }
    return true;
}

bool ItemDataMngr::loadItem() {
    char* err_sql;
    std::stringstream query;
    
    query << "SELECT * FROM " << ITEM_TABLE_NAME << ";";
    sqlite3_exec(opened_db, query.str().c_str(), &itemCallBack, this, &err_sql);
    if(err_sql != nullptr) {
        std::cout << err_sql << "\n";
        sqlite3_free(err_sql);
        return false;
    }
    return true;
}
