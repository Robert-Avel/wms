#pragma once
#include "GroupMngr.hpp"
#include "data/DataMngr.hpp"
#include "item/item_sys.hpp"


class WMRobert {
    public:
        WMRobert(std::string data_base_file):
            data_module(data_base_file),
            group_module(data_module.groups.data),
            item_module(data_module.itens.data, group_module)
            {}


        DataFileMnger data_module;
        GroupMngr group_module;
        ItemManager item_module;



};
