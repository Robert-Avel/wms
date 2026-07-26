#include "item_data.hpp"
#include "base_converter.hpp"
#include "identificator.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstdint>
#include <iostream>


uint64_t ItemData::getNewID() {
    return next_id++;
}


const std::unordered_map<uint32_t, Item>::const_iterator ItemData::begin() {
    return data.cbegin();
}

const std::unordered_map<uint32_t, Item>::const_iterator ItemData::end() {
    return data.cend();
}



ItemData::ItemData(std::ifstream& file) {
    if (!file) {
        std::cerr << "File is not open or its damaged\n";
        return;
    }

    uint32_t db_size;
    file.read((char*) &db_size, sizeof(uint32_t));
    file.read((char*) &code_mode, sizeof(IdMode));
    file.read((char*) &next_id, sizeof(uint64_t));

    for(uint32_t i = 0; i < db_size; i++) {
        Item buffer = Item(file);
        data.insert_or_assign(buffer.bruteID(), buffer);
    }
}



Status ItemData::newItem(const Item i) {
    if (data.find(i.bruteID()) == data.end()) {
        data.insert({i.bruteID(), i});
        return SUCCESS;
    }
    return ALREADY_EXIST;
}

Status ItemData::newItem(const std::string global_name_, double m3_, double weight_, cents brute_value_) {
    return newItem(
        Item( getNewID(),
            code_mode,
            global_name_,
            m3_,
            weight_,
            brute_value_
        )
    );
}

Status ItemData::removeItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return NOT_FOUND;
    }
    data.erase(id);
    return SUCCESS;
}

Status ItemData::removeItem(std::string& id) {
    return removeItem(BaseToInt(id, code_mode, ID::hasNum(code_mode)));
}


const Item* ItemData::getItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return nullptr;
    }
    return &data.at(id);
}

const Item* ItemData::getItem(std::string& id) {
    return getItem(BaseToInt(id, code_mode, ID::hasNum(code_mode)));
}



bool ItemData::saveData(std::ofstream& file) {
    if (!file) {
        std::cerr << "File is not open or its damaged\n";
        return false;
    }

    uint32_t db_size = data.size();
    file.write((char*) &db_size, sizeof(uint32_t));
    file.write((char*) &code_mode, sizeof(IdMode));
    file.write((char*) &next_id, sizeof(uint64_t));


    auto it = data.begin();
    while (it != data.end()) {
        if(!it->second.saveData(file)) {
            return false;
        }
    }

    return true;
}
