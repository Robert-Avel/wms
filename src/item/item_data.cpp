#include "item_data.hpp"
#include "item.hpp"
#include "status.hpp"


Status ItemData::newItem(const Item i) {
    if (data.find(i.bruteID()) == data.end()) {
        data.insert_or_assign(i.bruteID(), i);
        return SUCCESS;
    }
    return ALREADY_EXIST;
}

Status ItemData::newItem(const ID identifier_,const std::string global_name_, double m3_, double weight_, cents brute_value_) {
    return newItem(
        Item(identifier_.bruteID(),
            identifier_.getMode(),
            global_name_,
            m3_,
            weight_,
            brute_value_
        )
    );
}

Status ItemData::removeItem(ID& id) {
    if (data.find(id.bruteID()) == data.end()) {
        return NOT_FOUND;
    }
    data.erase(id.bruteID());
    return SUCCESS;
}

const Item* ItemData::getItem(ID& id) {
    if (data.find(id.bruteID()) == data.end()) {
        return nullptr;
    }
    return &data.at(id.bruteID());
}
