#include "data/WarehouseDB.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <fstream>

bool WarehouseDB::saveFile(Warehouse obj, uint64_t id, std::ofstream& file) {
    if(!file) {
        std::cerr << "File not open!\n";
        return false;
    }
    file.write((char*) &id, sizeof(uint64_t));
    size_t ssize = obj.getName().size();
    file.write((char*) &ssize, sizeof(size_t));
    file.write(obj.getName().c_str(), ssize);

    file.write((char*) &obj.getCapacity(), sizeof(CubicCm));
    return true;
}

std::optional<std::pair<uint64_t, Warehouse>> WarehouseDB::loadFile(std::ifstream& file) {
    std::optional<std::pair<uint64_t, Warehouse>> output;
    if(!file) {
        std::cerr << "File not open!\n";
        return output;
    }
    uint64_t id;
    file.read((char*) &id, sizeof(uint64_t));

    size_t ssize;
    file.read((char*) &ssize, sizeof(size_t));

    std::string name(ssize, '\0');
    file.read(name.data(), ssize);

    CubicCm cub;
    file.read((char*) &cub, sizeof(CubicCm));

    output = {id, {name, cub}};
    return output;
}


void WarehouseDB::saveAllFile(std::ofstream& file) {
    if(!file) {
        std::cerr << "File not open!\n";
        return;
    }
    for(auto& wh: data) {
        saveFile(wh.second, wh.first, file);
    }
}
bool WarehouseDB::loadAllFile(std::ifstream& file, size_t d_size) {
    if(!file) {
        std::cerr << "File not open!\n";
        return false;
    }
    for(size_t i = 0; i < d_size; i++) {
        auto r = loadFile(file);
        if(r.has_value()) {
            data.insert(r->first, r->second);
        }
    }
    return true;
}
