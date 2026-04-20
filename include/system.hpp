#pragma once
#include "item.hpp"
#include "status.hpp"
#include "warehouse.hpp"
#include <cstdint>
#include <string>
#include <vector>


class WMS {
    private:
    std::pmr::vector<Warehouse> whs;
    std::pmr::vector<Item> itens;

    Warehouse* warehouse_cursor;


    public:
    WMS() = default;

    //Cursor
    Status select_wh(std::string identifier);
    Warehouse& getSelectedWH();

    //Status
    uint32_t activeWH();
    uint32_t itensCount();

    //Item Managent
    Status itemNew(Item& __i);
    Status itemNew(uint32_t identifier_,std::string global_name_, cubic m3_,double weight_,cents brute_value_);
    const Item* itemGetbID(uint32_t __id);
    std::string itemList();

    //Warehouse Managent
    Status warehouseNew(std::string __identifier, cubic __capacity);
    Status warehouseNew(Warehouse __w);
    Status warehouseDelete();
    Warehouse* whGetbID(std::string identifier);
    std::string whList();

    Status cargoAdd(uint32_t item_id, uint32_t quantity_);
    Status cargoRemove(uint32_t item_id, uint32_t quantity_);
};
