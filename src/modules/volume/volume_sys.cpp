#include "volume/volume_sys.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include "volume/volume.hpp"


uint64_t VolumeManager::createVolume(uint64_t group, uint64_t item_id_) {
    IdObj<Item>* i = itens_data.getItem(group, item_id_);
    if(i == nullptr) {return 0;}

    Volume v{item_id_, i->cgetObj()};
    return linked_data.append(group, v, true);
}

const IdObj<Volume>* VolumeManager::getVolume(uint64_t group, uint64_t id) {
    return linked_data.getItem(group, id);
}

std::list<const IdObj<Volume>*> VolumeManager::list(uint64_t group, uint32_t page) {
    std::list<const IdObj<Volume>*> output;

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
