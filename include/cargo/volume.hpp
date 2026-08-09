#pragma once
#include "item.hpp"
#include "IDed_map.hpp"
#include "byte_serializator.hpp"


class Volume {
    bID item_id;
    bID volume_batch;
    bID volume_id;


    double weight;
    double volume_m3;
    cents value;


    public:
    Volume(const bID item_id_, const bID volume_id_, const bID volume_batch_, double weight_, double m3_, cents value_):
        item_id(item_id_), volume_batch(volume_batch_), volume_id(volume_id_), weight(weight_), volume_m3(m3_), value(value_) {}


    Volume(ByteS& data);
    const bID& getItemID() const;

    const bID& getID() const;

    const bID& getBatchID() const;

    double getWeight() const;

    double getCubic() const;

    cents getValue() const;

    std::string formatData() const;

    ByteS getBytes() const;
};
