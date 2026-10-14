#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include <cstddef>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include "data/GroupDB.hpp"
#include "data/ItemDB.hpp"
#include "data/VolumeDB.hpp"
#include "data/WarehouseDB.hpp"


class DataMnger {
    std::string file_name;

    void WarehouseLoad(std::ifstream& open_db) {
        size_t gsize{0};
        open_db.read((char*) &gsize, sizeof(gsize));
        warehouses.loadAllFile(open_db, gsize);
        warehouses.data.uptadeLastID();
    }

    void ItemLoad(std::ifstream& open_db) {
        size_t gsize{0};
        open_db.read((char*) &gsize, sizeof(gsize));
        itens.loadAllFile(open_db, gsize);
        itens.data.updateID();
    }


    void GroupLoad(std::ifstream& open_db) {
        size_t gsize;
        open_db.read((char*) &gsize, sizeof(size_t));
        groups.loadAllFile(open_db, gsize);
    }

    void VolumeLoad(std::ifstream& open_db) {
        size_t gsize;
        open_db.read((char*) &gsize, sizeof(size_t));
        volumes.loadAllFile(open_db, gsize);
    }


    void WarehouseSave(std::ofstream& open_db) {
        if(warehouses.data.isEmpty()) {return;}

        size_t gsize = warehouses.data.size();
        open_db.write((char*) &gsize, sizeof(size_t));
        warehouses.saveAllFile(open_db);
    }

    void ItemSave(std::ofstream& open_db) {
        if(itens.data.isEmpty()) {return;}

        size_t gsize = itens.data.size();
        open_db.write((char*) &gsize, sizeof(size_t));
        itens.saveAllFile(open_db);
    }

    void GroupSave(std::ofstream& open_db) {
        size_t gsize = groups.data.size();
        open_db.write((char*) &gsize, sizeof(size_t));
        groups.saveAllFile(open_db);
    }

    void VolumeSave(std::ofstream& open_db) {
        size_t gsize = volumes.data.size();
        open_db.write((char*) &gsize, sizeof(size_t));
        volumes.saveAllFile(open_db);
    }

    public:
    ItemDB itens;
    GroupDB groups;
    VolumeDB volumes;
    WarehouseDB warehouses;

    DataMnger(std::string file): file_name(file) {
        std::ifstream open_db(file, std::ios::binary);
        if(!open_db) {return;}

        ItemLoad(open_db);
        GroupLoad(open_db);
        VolumeLoad(open_db);
        WarehouseLoad(open_db);
        open_db.close();
    }

    ~DataMnger() {
        std::ofstream open_db(file_name, std::ios::binary | std::ios::trunc);

        ItemSave(open_db);
        GroupSave(open_db);
        VolumeSave(open_db);
        WarehouseSave(open_db);
        open_db.close();
    }
};


#endif
