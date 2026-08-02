#include "IDed_map.hpp"
#include "item.hpp"
#include "interface.hpp"
#include <cstddef>
#include <fstream>
#include <ios>
#include <list>


bool WMRobert::itemLoad() {
    std::ifstream file(this->item_file_name, std::ios::in | std::ios::binary);
    if(!file) {return false;}

    size_t size;
    ID id;

    file.read((char*) &size, sizeof(size_t));
    for(size_t i = 0; i < size; i++) {
        file.read((char*) &id, sizeof(ID));
        Item it = Item(file);
        itens.insert(id, it);
    }
    return 0;
}


bool WMRobert::itemSave() {
    std::ofstream file(this->item_file_name, std::ios::out | std::ios::binary | std::ios::trunc);
    if(!file) {return false;}

    size_t size = itens.size();

    file.write((char*) &size, sizeof(size_t));

    auto iter = itens.begin();
    while(iter != itens.end()) {
        file.write((char*) &iter->first, sizeof(ID));
        iter->second.saveData(file);
        iter++;
    }
    return true;
}


ID WMRobert::itemNew(std::string name, double weight, double cubic, cents value) {
    Item i{name, cubic, weight, value};
    return itens.append(i);
}

Item* WMRobert::itemInfo(ID id_) {
    return itens.getItem(id_);
}


std::list<std::pair<ID, const Item*>> WMRobert::itemList(uint32_t page) {
    std::list<std::pair<ID, const Item*>> output;

    if(itens.isEmpty()) {return output;}

    int i_page = 1;
    auto it = itens.begin();
    while (it != itens.end()) {
        if(page == i_page) {
            output.push_back({it->first, &it->second});
        }
        if(page % 10 == 0) {page++;}
        it++;
    }
    return output;
}


std::list<std::pair<ID, const Item*>> WMRobert::searchItem(std::string name) {
    std::list<std::pair<ID, const Item*>> output;
    if(itens.isEmpty()) {return output;}

    auto it = itens.begin();
    while (it != itens.end()) {
        if(it->second.getGlobalName().find_first_of(name) != std::string::npos) {
            output.push_back({it->first, &it->second});
        }
        it++;
    }
    return output;
}
