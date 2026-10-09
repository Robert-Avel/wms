#include "item/item_sys.hpp"
#include "IdObj.hpp"



const IdObj<Item>* ItemManager::getItem(uint64_t group, uint64_t id) {
    return linked_data.getItem(group, id);
}

uint64_t ItemManager::creteItem(uint64_t group, std::string global_name, uint32_t cubic_cm, uint32_t weight_g, cents value) {
    Item i{global_name, cubic_cm, weight_g, value};
    return linked_data.append(group, i, true);
}



std::list<const IdObj<Item>*> ItemManager::list(uint64_t group, uint32_t page) {
    std::list<const IdObj<Item>*> output;

    if(linked_data.isEmpty()) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= linked_data.size(); it_id++) {
        if(page == i_page) {
            auto* i = this->linked_data.getItem(group, it_id);
            if(i != nullptr) {output.push_back(i);}
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}
