#include "data_manager.hpp"
#define CONFIG_FILE "config_wms.bin"



bool DataManager::saveItem(std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if(!file || item_d.isEmpty()) {return false;}

    size_t size = item_d.size();
    bruteID next_ID = item_d.showNexID();

    file.write((char*) &next_ID, sizeof(bruteID));
    file.write((char*) &size, sizeof(size_t));
    auto iter = item_d.begin();
    while(iter != item_d.end()) {
        file.write((char*) &iter->first, sizeof(bruteID));
        iter->second.saveData(file);
        iter++;
    }
    return true;

}

bool DataManager::loadItem(std::string& filename) {
    std::ifstream file{filename, std::ios::binary};
    if(!file || !file.is_open()) {return false;}

    bruteID next_id;
    size_t size;
    bruteID id;

    file.read((char*) &next_id, sizeof(bruteID));
    this->item_d.setNexID(next_id);
    file.read((char*) &size, sizeof(size_t));
    for(size_t i = 0; i < size; i++) {
        file.read((char*) &id, sizeof(bruteID));
        Item it = Item(file);
        item_d.insert(id, it);
    }
    return true;
}

bool DataManager::saveVolume(std::string& filename) {
    return false;
}

bool DataManager::loadVolume(std::string& filename) {
    return false;
}
