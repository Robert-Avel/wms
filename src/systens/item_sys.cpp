#include "item_sys.hpp"
#include "IDed_map.hpp"
#include "WMSData.hpp"




uint64_t ItemSys::createItem(uint64_t group, std::string name, double weight, double cubic, cents value) {
    if(!group_names.hasPrefix(group)) {return 0;}

    uint64_t i_id = data_base.getGroup(group)->showNexID();
    
    Item i{name, cubic, weight, value, i_id, group};
    
    data_base.append(group, i, true);

    return i_id;
}

uint64_t ItemSys::createItem(std::string group, std::string name, double weight, double cubic, cents value) {
    uint64_t* g_id = group_names.translateGName(group);
    if(g_id == nullptr) {return 0;}
    else return this->createItem(*g_id, name, weight, cubic, value);
}


Item* ItemSys::infoItem(uint64_t group, uint64_t id_) {
    if(!group_names.hasPrefix(group)) {return nullptr;}

    return data_base.getItem(group, id_);
}


Item* ItemSys::infoItem(std::string group, uint64_t id_) {
    uint64_t* g_id = group_names.translateGName(group);
    if(g_id == nullptr) {return 0;}
    else return this->infoItem(*g_id, id_);
}


std::list<const Item*> ItemSys::list(uint64_t group, uint32_t page) {
    std::list<const Item*> output;
    
    if(data_base.isEmpty() || !group_names.hasPrefix(group)) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= data_base.size(); it_id++) {
        if(page == i_page) {
            Item* i = this->data_base.getItem(group, it_id);
            if(i != nullptr) {output.push_back(i);}
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}

std::list<const Item*> ItemSys::list(std::string group, uint32_t page) {
    uint64_t* g_id = group_names.translateGName(group);
    if(g_id == nullptr) {return std::list<const Item*>();}
    else return this->list(*g_id, page);
}


std::list<const Item*> ItemSys::search(std::string name) {
    std::list<const Item*> output;
    if(data_base.isEmpty()) {return output;}

    for(auto& it: data_base) {
        for(auto& it2: it.second) {
            if(it2.second.getGlobalName().find_first_of(name) != it2.second.getGlobalName().npos) {
                output.push_back(&it2.second);
            }
        }
    }
}
