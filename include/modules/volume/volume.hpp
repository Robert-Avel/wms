#pragma once
#include "item/item.hpp"
#include <cstddef>
#include <cstdint>
#include <ctime>


class Volume {
    uint64_t item_id;
    uint32_t weight_g;
    uint32_t cubic_cm;
    cents value;

    time_t created_in;
    uint64_t volume_batch;



    public:
    Volume(const uint64_t item_id_, uint32_t weight_g_, uint32_t cubic_cm3, cents value_, const uint64_t volume_batch_ = 0, time_t created_in = time(NULL)):
    item_id(item_id_), weight_g(weight_g_), cubic_cm(cubic_cm3), value(value_), created_in(created_in), volume_batch(volume_batch_)
    {}
    Volume(const uint64_t item_id_, const Item item, const uint64_t volume_batch_ = 0):
    item_id(item_id_), weight_g(item.getWeight()), cubic_cm(item.getCubic()), value(item.getBruteValue()), created_in(time(NULL)), volume_batch(volume_batch_)
    {}


    const time_t& getCreatedIn() const;

    const uint64_t& getItemID() const;

    const uint64_t& getBatchID() const;

    const uint32_t& getWeight() const;

    const uint32_t& getCubic() const;

    const cents& getValue() const;

    std::string formatData() const;

};
