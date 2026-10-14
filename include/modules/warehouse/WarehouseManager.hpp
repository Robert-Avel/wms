#ifndef WAREHOUSE_MANAGER
#define WAREHOUSE_MANAGER

#include "IdMap.hpp"
#include "warehouse/Warehouse.hpp"
#include <cstdint>
#include <list>

class WarehouseManager {
    IdMap<Warehouse>& data;

    public:
        WarehouseManager(IdMap<Warehouse>& data_): data(data_) {}

        uint64_t createWH(std::string name, CubicCm capacity);
        const Warehouse* getWH(uint64_t id) const;
        std::list<std::pair<uint64_t, const Warehouse*>> list(uint32_t page);
};

#endif
