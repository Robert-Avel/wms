#include "IdObj.hpp"
#include "item/Item.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <optional>
#include "data/BaseDB.hpp"


bool ItemDBs::saveOne(const Obj& obj, std::ofstream& file) {
    const Item& i = obj.cgetObj();

    file.write((char*) &obj.getGroup(), sizeof(uint64_t));
    file.write((char*) &obj.getID(), sizeof(uint64_t));

    size_t g_name_size = i.getGlobalName().size();
    file.write((char*) &g_name_size, sizeof(size_t));
    file.write(i.getGlobalName().c_str(), g_name_size);

    file.write((char*) &i.getCubic(), sizeof(uint32_t));
    file.write((char*) &i.getWeight(), sizeof(uint32_t));
    file.write((char*) &i.getBruteValue(), sizeof(Cents));

    return true;
}

std::optional<ItemDBs::Obj> ItemDBs::loadOne(std::ifstream& file) {
    std::optional<ItemDBs::Obj> i;
    if(!file) {
        std::cerr << "File not open!\n";
        return i;
    }

    uint64_t _group{0};
    uint64_t _id{0};
    size_t g_name_size{0};

    uint32_t cubic{0};
    uint32_t weight{0};
    Cents value{0};

    file.read((char*) &_group, sizeof(uint64_t));
    file.read((char*) &_id, sizeof(uint64_t));

    file.read((char*) &g_name_size, sizeof(size_t));
    std::string g_name(g_name_size, '\0');
    file.read((char*) g_name.data(), g_name_size);

    file.read((char*) &cubic, sizeof(cubic));
    file.read((char*) &weight, sizeof(weight));
    file.read((char*) &value, sizeof(value));

    i = IdObj<Item>{{g_name, cubic, weight, value}, _id, _group};
    return i;
}

bool ItemDBs::insert(const Obj& o) {
    return data.insert(o.getGroup(), o.getID(), o.cgetObj(), true);
}

void ItemDBs::saveIterator(std::ofstream& file) {
    for(auto& g: data) {
        for(auto& obj: g.second) {
            saveOne(obj.second, file);
        }
    }
}
