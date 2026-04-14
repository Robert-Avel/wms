#pragma once
#include "item.hpp"
#include "status.hpp"
#include "warehouse.hpp"
#include <cstdint>
#include <vector>


class WMS {
    private:
    std::pmr::vector<Warehouse> whs;
    std::pmr::vector<Item> itens;


    public:
    WMS() = default;

    uint32_t activeWH();
    uint32_t itensCount();

    Status itemNew(Item& __i);
    Status itemNew(uint32_t identifier_,std::string global_name_, cubic m3_,double weight_,cents brute_value_);
    const Item* itemGetbID(uint32_t __id);


    Status warehouseNew(std::string __identifier, cubic __capacity);
    Status warehouseNew(Warehouse __w);
    Warehouse* whGetbID(std::string identifier);

    Status cargoAdd(std::string wh_id, uint32_t iten_id);

};
