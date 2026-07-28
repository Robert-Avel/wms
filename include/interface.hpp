#pragma once
#include "identificator.hpp"
#include "item.hpp"
#include "item_data.hpp"
#include "status.hpp"


namespace wmr {
    namespace item {

    void setDataMode(ItemData& db, IdMode mode_);
    Status create(ItemData& db,std::string name_, double m3_, double weight_, cents brute_value_);
    const Item* get(ItemData& db,std::string id_);
    }
}
