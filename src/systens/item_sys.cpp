#include "item_sys.hpp"
#include "IDed_map.hpp"


uint64_t ItemSys::create(std::string name, double weight, double cubic, cents value) {
    Item i{name, cubic, weight, value};
    return itens.append(i);
}

Item* ItemSys::info(uint64_t id_) {
    return itens.getItem(id_);
}


std::list<std::pair<uint64_t, const Item*>> ItemSys::list(uint32_t page) {
    std::list<std::pair<uint64_t, const Item*>> output;

    if(itens.isEmpty()) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= itens.size(); it_id++) {
        if(page == i_page) {
            Item* i = this->itens.getItem(it_id);
            output.push_back({it_id, i});
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}

std::list<std::pair<uint64_t, const Item*>> ItemSys::search(std::string name) {
    std::list<std::pair<uint64_t, const Item*>> output;
    if(itens.isEmpty()) {return output;}

    auto it = itens.begin();
    while (it != itens.end()) {
        if(it->second.getGlobalName().find_first_of(name) != it->second.getGlobalName().npos) {
            output.push_back({it->first, &it->second});
        }
        it++;
    }
    return output;
}
