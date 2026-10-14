#include "IdMap.hpp"
#include <cstdint>
#include <optional>
#include "warehouse/Warehouse.hpp"


class WarehouseDB {
    public:
    bool saveFile(Warehouse obj, uint64_t id, std::ofstream& file);
    std::optional<std::pair<uint64_t, Warehouse>> loadFile(std::ifstream& file);

    IdMap<Warehouse> data;

    WarehouseDB() = default;

    void saveAllFile(std::ofstream& file);
    bool loadAllFile(std::ifstream& file, size_t d_size);
};
