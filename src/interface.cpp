#include "interface.hpp"
#include "item.hpp"
#include "status.hpp"


 Status wmr::item::create(ItemData &db, std::string name_, double m3_, double weight_, cents brute_value_) {
     return db.newItem(name_, m3_, weight_, brute_value_);
}


const Item* wmr::item::get(ItemData& db,std::string id_) {
    return db.getItem(id_);
}
