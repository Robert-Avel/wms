#pragma once
#include "GroupMngr.hpp"
#include "data/DataMngr.hpp"
#include "item/item_sys.hpp"
#include "volume/volume_sys.hpp"


static IdGroup<Volume> placeholder_data;


class WMRobert {

    public:
        WMRobert(std::string data_base_file):
            data_module(data_base_file),
            group_module(data_module.groups.data),
            item_module(data_module.itens.data, group_module),
            volume_module(data_module.volumes.data, group_module, data_module.itens.data)
            {}


        DataFileMnger data_module;
        GroupMngr group_module;
        ItemManager item_module;
        VolumeManager volume_module;

};
