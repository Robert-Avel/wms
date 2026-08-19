#include "item.hpp"
#include <cstdint>
#include <vector>


class Batch: public IDedObj {
    public:
    std::vector<uint64_t> volumes_id;

    Batch(): IDedObj() {}
};
