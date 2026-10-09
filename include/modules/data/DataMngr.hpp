#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include "IdGroup.hpp"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include "data/ItemDB.hpp"
#include "item/item.hpp"


class DataFileMnger {
    std::string file_name;
    public:

    ItemDataBase itens;

    DataFileMnger(std::string file): file_name(file) {
        std::ifstream open_db(file, std::ios::binary);
        if(!open_db) {return;}

        size_t itens_n{0};
        open_db.read((char*) &itens_n, sizeof(itens_n));
        std::cout << "Size to Load: " << itens_n << '\n';
        itens.loadAllFile(open_db, itens_n);
        itens.data.updateID();
    }

    ~DataFileMnger() {
        if(itens.data.isEmpty()) {return;}
        std::ofstream open_db(file_name, std::ios::binary | std::ios::trunc);

        size_t itens_n = itens.data.size();
        open_db.write((char*) &itens_n, sizeof(size_t));
        itens.saveAllFile(open_db);
    }
};


#endif
