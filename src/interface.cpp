#include "IDed_container.hpp"
#include "item.hpp"
#include "interface.hpp"
#include "status.hpp"
#include <cstddef>
#include <ios>


static IDedContainer<Item> item_db;


bool wmr::item::load(std::ifstream& file, std::string file_name) {
    file.open(file_name, std::ios::in | std::ios::binary);
    if(!file) {return false;}

    size_t size;
    ID id;

    file.read((char*) &size, sizeof(size_t));
    for(size_t i = 0; i < size; i++) {
        file.read((char*) &id, sizeof(ID));
        Item it = Item(file);
        item_db.insert(id, it);
    }
    return 0;
}


bool wmr::item::save(std::ofstream& file, std::string file_name) {
    file.open(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
    if(!file) {return false;}

    size_t size = item_db.size();
    ID id;

    file.write((char*) &size, sizeof(size_t));

    auto iter = item_db.begin();
    while(iter != item_db.end()) {
        file.write((char*) &iter->first, sizeof(ID));
        iter->second.saveData(file);
        iter++;
    }
    return true;
}



void wmr::item::setDataMode(basec::StdMode mode_) {
    item_db.setMode(mode_);
}


Status wmr::item::create(std::string name_, double m3_, double weight_, cents brute_value_) {
    Item i = {name_, m3_, weight_, brute_value_};
    item_db.append(i);
    return SUCCESS;
}


const Item* wmr::item::get(std::string id_) {
    return item_db.getItem(id_);
}
