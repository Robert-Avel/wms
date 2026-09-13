#include "item_sys.hpp"
#include "IDed_map.hpp"
#include "WMSData.hpp"


uint64_t ItemSys::createGroup(std::string prefix) {
    uint64_t g_id = data_base.newGroup();
    group_names.insert({prefix, g_id});
    return g_id;
}


GroupPrefixMap ItemSys::getGroups() const {return group_names;}


uint64_t ItemSys::createItem(std::string group, std::string name, double weight, double cubic, cents value) {
    uint64_t* g_id = group_names.translateGName(group);
    if(g_id == nullptr) {return 0;}

    uint64_t i_id = data_base.getGroup(*g_id)->showNexID();

    
    Item i{name, cubic, weight, value, i_id, *g_id};
    
    data_base.append(*g_id, i);

    return i_id;
}

Item* ItemSys::infoItem(std::string group, uint64_t id_) {
    auto g_id = group_names.translateGName(group);
    if(g_id == nullptr) {return nullptr;}

    return data_base.getItem(*g_id, id_);
}


std::list<const Item*> ItemSys::list(std::string prefix, uint32_t page) {
    std::list<const Item*> output;
    uint64_t* g_id = group_names.translateGName(prefix);
    
    if(data_base.isEmpty() || g_id == nullptr) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= data_base.size(); it_id++) {
        if(page == i_page) {
            Item* i = this->data_base.getItem(*g_id, it_id);
            output.push_back(i);
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}

std::list<const Item*> ItemSys::search(std::string name) {
    std::list<const Item*> output;
    if(data_base.isEmpty()) {return output;}

    auto it = data_base.begin();
    while (it != data_base.end()) {
        auto it2 = it->second.begin();
        while (it2 == it->second.end())
        {
            if(it2->second.getGlobalName().find_first_of(name) != it2->second.getGlobalName().npos) {
                output.push_back(&it2->second);
            }
            it2++;
        }
        it++;
    }
    return output;
}
