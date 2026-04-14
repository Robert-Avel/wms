#include "warehouse.hpp"
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


const Item* WMS::itemGetbID(uint32_t __id) {
    for(Item& i: itens) {
        if(i.identifier == __id) {return &i;}
    }
    return nullptr;
}


Status WMS::warehouseNew(std::string __identifier, cubic __capacity) {
    Warehouse w = Warehouse(__identifier, __capacity);
    return warehouseNew(w);
}

Status WMS::warehouseNew(Warehouse __w) {
    for(Warehouse& i: whs) {
        if( __w.getID() == i.getID()) {return  W_ALREADY_EXIST;}
    }
    whs.push_back(__w);
    return W_SUCCESS;
}

Warehouse* WMS::whGetbID(std::string identifier) {
    for(Warehouse& w: whs) {
        if(w.getID() == identifier) {return &w;}
    }
    return nullptr;
}


Status WMS::cargoAdd(std::string wh_id, uint32_t iten_id) {
    Warehouse* wh = whGetbID(wh_id);
    const Item* i = itemGetbID(iten_id);

    if(wh == nullptr || i == nullptr) {return  W_NOT_FOUND;}

    wh.
}
