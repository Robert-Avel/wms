#pragma once
#include "byte_serializator.hpp"
#include "item.hpp"
#include "types.hpp"
#include <cstdint>


class Volume: public IDedObj {
    bruteID item_id;
    bruteID volume_batch;


    double weight;
    double volume_m3;
    cents value;


    public:
    Volume(const bruteID item_id_, const bruteID volume_batch_, double weight_, double m3_, cents value_, uint64_t id = 0, uint64_t group = 0):
         IDedObj(id, group), item_id(item_id_), volume_batch(volume_batch_), weight(weight_), volume_m3(m3_), value(value_) {}


    Volume(ByteS& byte);

    const bruteID& getItemID() const;

    const bruteID& getBatchID() const;

    double getWeight() const;

    double getCubic() const;

    cents getValue() const;

    std::string formatData() const;

    ByteS getBytes();
};
