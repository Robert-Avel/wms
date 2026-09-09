#pragma once
#include "item_sys.hpp"


class WMRobert {
    public:
        WMRobert(): item_module(data_module.item_d) {}

        DataManager data_module;
        ItemSys item_module;
};
