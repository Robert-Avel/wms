#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "address/Address.hpp"

class Warehouse {
    std::string name;
    CubicCm capacity;

    public:
        Warehouse(std::string name_, CubicCm capacity_):
        name(name_), capacity(capacity_)
        {}

        const std::string& getName() const {return name;}
        const CubicCm& getCapacity() const {return capacity;}
};

#endif
