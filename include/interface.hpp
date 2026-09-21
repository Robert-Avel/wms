#pragma once
#include "item_sys.hpp"
#include "WMSData.hpp"
#include "group_sys.hpp"


class WMRobert {
    public:
        WMRobert(std::string data_base_file): 
        data_module(data_base_file), 
        item_module(data_module),
        group_module(data_module) {}

        WMSData data_module;
        ItemSys item_module;
        GroupSys group_module;
};
