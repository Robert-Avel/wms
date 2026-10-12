#ifndef VOLUME_MANAGER_HPP
#define VOLUME_MANAGER_HPP

#include "GroupMngr.hpp"
#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include "volume/volume.hpp"
#include <cstdint>
#include <list>

class VolumeManager {
    IdGroup<Volume>& linked_data;
    GroupMngr& group_sys;
    IdGroup<Item>& itens_data;

    public:
    VolumeManager(IdGroup<Volume>& data, GroupMngr& groups, IdGroup<Item>& itens):
    linked_data(data), group_sys(groups), itens_data(itens)
    {}

    uint64_t createVolume(uint64_t group, uint64_t item_id_);

    const IdObj<Volume>* getVolume(uint64_t group, uint64_t id);

    std::list<const IdObj<Volume>*> list(uint64_t group, uint32_t page);

};

#endif
