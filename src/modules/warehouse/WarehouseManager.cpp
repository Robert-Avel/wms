#include "warehouse/WarehouseManager.hpp"
#include <cstdint>


uint64_t WarehouseManager::createWH(std::string name, CubicCm capacity) {
    auto a = Warehouse(name, capacity);
    return data.append(a);
}

const Warehouse* WarehouseManager::getWH(uint64_t id) const {
    return data.getItem(id);
}

std::list<std::pair<uint64_t, const Warehouse*>> WarehouseManager::list(uint32_t page) {
    std::list<std::pair<uint64_t, const Warehouse*>> output;

    if(data.isEmpty()) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= data.size(); it_id++) {
        if(page == i_page) {
            auto* i = this->data.getItem(it_id);
            if(i != nullptr) {output.push_back({it_id, i});}
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}
