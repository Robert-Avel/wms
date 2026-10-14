#include "data/BaseDB.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <fstream>

bool WarehouseDBs::saveOne(const Obj& obj, std::ofstream& file) {
    file.write((char*) &obj.first, sizeof(uint64_t));
    size_t ssize = obj.second.getName().size();

    file.write((char*) &ssize, sizeof(size_t));
    file.write(obj.second.getName().c_str(), ssize);

    file.write((char*) &obj.second.getCapacity(), sizeof(CubicCm));
    return true;
}

std::optional<WarehouseDBs::Obj> WarehouseDBs::loadOne(std::ifstream& file) {
    std::optional<WarehouseDBs::Obj> output;
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


void WarehouseDBs::saveIterator(std::ofstream& file) {
    if(!file) {
        std::cerr << "File not open!\n";
        return;
    }
    for(auto& wh: data) {
        saveOne({wh.first, wh.second}, file);
    }
}


bool WarehouseDBs::insert(const Obj& o) {
    return data.insert(o.first, o.second);
}
