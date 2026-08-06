#include "IDed_map.hpp"
#include "item.hpp"
#include "interface.hpp"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <list>


bool WMRobert::itemLoad() {
    std::ifstream file(this->item_file_name, std::ios::in | std::ios::binary);
    if(!file) {return false;}

    bID next_id;
    size_t size;
    bID id;

    file.read((char*) &next_id, sizeof(bID));
    this->itens.setNexID(next_id);
    file.read((char*) &size, sizeof(size_t));
    for(size_t i = 0; i < size; i++) {
        file.read((char*) &id, sizeof(bID));
        Item it = Item(file);
        itens.insert(id, it);
    }
    #ifdef DEBUG
    std::cout << "Itens loaded: " << itens.size() << "\n";
    #endif

    return 0;
}


bool WMRobert::itemSave() {
    std::ofstream file(this->item_file_name, std::ios::out | std::ios::binary | std::ios::trunc);
    if(!file) {return false;}

    size_t size = itens.size();
    bID next_ID = itens.showNexID();

    file.write((char*) &next_ID, sizeof(bID));
    file.write((char*) &size, sizeof(size_t));
    auto iter = itens.begin();
    while(iter != itens.end()) {
        file.write((char*) &iter->first, sizeof(bID));
        iter->second.saveData(file);
        iter++;
    }
    return true;
}


cID WMRobert::itemNew(std::string name, double weight, double cubic, cents value) {
    Item i{name, cubic, weight, value};
    return this->itens.codeID(itens.append(i));
}

Item* WMRobert::itemInfo(cID id_) {
    return itens.getItem(id_);
}


std::list<std::pair<cID, const Item*>> WMRobert::itemList(uint32_t page) {
    std::list<std::pair<cID, const Item*>> output;

    if(itens.isEmpty()) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= itens.size(); it_id++) {
        if(page == i_page) {
            Item* i = this->itens.getItem(it_id);
            output.push_back({itens.codeID(it_id), i});
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}


std::list<std::pair<cID, const Item*>> WMRobert::searchItem(std::string name) {
    std::list<std::pair<cID, const Item*>> output;
    if(itens.isEmpty()) {return output;}

    auto it = itens.begin();
    while (it != itens.end()) {
        if(it->second.getGlobalName().find_first_of(name) != it->second.getGlobalName().npos) {
            output.push_back({itens.codeID(it->first), &it->second});
        }
        it++;
    }
    return output;
}
