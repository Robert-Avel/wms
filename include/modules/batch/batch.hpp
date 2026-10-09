#include "item/item.hpp"
#include <cstdint>
#include <vector>


class Batch {
    public:
    std::vector<uint64_t> volumes_id;

    Batch(uint64_t id = 0, uint64_t group = 0) {}
};
