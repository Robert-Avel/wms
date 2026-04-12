#include "system.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstdint>


uint32_t WMS::activeWH() {
    return whs.size();
}

uint32_t WMS::itensCount() {
    return whs.size();
}


Status WMS::itemNew(Item& __i) {
    for(Item& i: itens) {
        if(i.identifier == __i.identifier) {return  W_ALREADY_EXIST;}
    }
    itens.push_back(__i);
    return W_SUCCESS;
}

Status WMS::itemNew(uint32_t identifier_,std::string global_name_, cubic m3_,double weight_,cents brute_value_)
{
    Item i = Item(identifier_, global_name_, m3_, weight_, brute_value_);
    return itemNew(i);
}


const Item* WMS::getbID(uint32_t __id) {
    for(Item& i: itens) {
        if(i.identifier == __id) {return &i;}
    }
    return nullptr;
}
