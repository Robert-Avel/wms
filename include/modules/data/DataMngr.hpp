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


class DataMnger {
    std::string file_name;

    void ItemLoad(std::ifstream& open_db) {
        size_t itens_n{0};
        open_db.read((char*) &itens_n, sizeof(itens_n));
        itens.loadAllFile(open_db, itens_n);
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


    void ItemSave(std::ofstream& open_db) {
        if(itens.data.isEmpty()) {return;}

        size_t itens_n = itens.data.size();
        open_db.write((char*) &itens_n, sizeof(size_t));
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

    DataMnger(std::string file): file_name(file) {
        std::ifstream open_db(file, std::ios::binary);
        if(!open_db) {return;}

        ItemLoad(open_db);
        GroupLoad(open_db);
        VolumeLoad(open_db);
        open_db.close();
    }

    ~DataMnger() {
        std::ofstream open_db(file_name, std::ios::binary | std::ios::trunc);

        ItemSave(open_db);
        GroupSave(open_db);
        VolumeSave(open_db);
        open_db.close();
    }
};


#endif
