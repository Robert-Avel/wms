#include "data/ItemDB.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <optional>


bool ItemDataBase::saveFile(IdObj<Item> obj, std::ofstream& file) {
    if(!file) {
        std::cerr << "File not open!\n";
        return false;
    }
    Item& i = obj.getObj();

    file.write((char*) &obj.getGroup(), sizeof(uint64_t));
    file.write((char*) &obj.getID(), sizeof(uint64_t));

    size_t g_name_size = i.getGlobalName().size();
    file.write((char*) &g_name_size, sizeof(size_t));
    file.write(i.getGlobalName().c_str(), g_name_size);

    file.write((char*) &i.getCubic(), sizeof(uint32_t));
    file.write((char*) &i.getWeight(), sizeof(uint32_t));
    file.write((char*) &i.getBruteValue(), sizeof(cents));

    return true;
}

std::optional<IdObj<Item>> ItemDataBase::loadFile(std::ifstream& file) {
    std::optional<IdObj<Item>> i;
    if(!file) {
        std::cerr << "File not open!\n";
        return i;
    }

    uint64_t _group{0};
    uint64_t _id{0};
    size_t g_name_size{0};

    uint32_t cubic{0};
    uint32_t weight{0};
    cents value{0};

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

void ItemDataBase::saveAllFile(std::ofstream& file) {
    for(auto& g: data) {
        for(auto& obj: g.second) {
            saveFile(obj.second, file);
        }
    }
}

bool ItemDataBase::loadAllFile(std::ifstream& file, size_t d_size) {
    for(size_t i = 0; i < d_size; i++) {
        auto l_obj = loadFile(file);
        if(l_obj.has_value()) {
            data.insert(l_obj->getGroup(), l_obj->getID(), l_obj->getObj(), true);
        }
    }
    return true;
}
