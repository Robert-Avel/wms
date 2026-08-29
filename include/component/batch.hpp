#include "item.hpp"
#include <cstdint>
#include <vector>


class Batch: public IDedObj {
    public:
    std::vector<uint64_t> volumes_id;

    Batch(uint64_t id = 0, uint64_t group = 0): IDedObj(id, group) {}
};
