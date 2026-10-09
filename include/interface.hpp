#pragma once
#include "data/DataMngr.hpp"
#include "item/item_sys.hpp"


class WMRobert {
    public:
        WMRobert(std::string data_base_file):
            data_module(data_base_file),
            item_module(data_module.itens.data) {}


        DataFileMnger data_module;
        ItemManager item_module;
};
