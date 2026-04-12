#pragma once
#include "item.hpp"
#include "status.hpp"
#include "werehouse.hpp"
#include <cstdint>
#include <vector>


class WMS {
    private:
    std::pmr::vector<Werehouse> whs;
    std::pmr::vector<Item> itens;


    public:
    WMS() = default;
    uint32_t activeWH();
    uint32_t itensCount();
    Status itemNew(Item& __i);
    Status itemNew(uint32_t identifier_,std::string global_name_, cubic m3_,double weight_,cents brute_value_);
    const Item* getbID(uint32_t __id);

};
