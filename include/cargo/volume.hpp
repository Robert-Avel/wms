#pragma once
#include "item.hpp"


class Volume {
    ID item_id;
    ID volume_batch;
    ID volume_id;


    double weight;
    double volume_m3;
    cents value;


    public:
    Volume(const ID item_id_, ID volume_id_, const ID volume_batch_, double weight_, double m3_):
        item_id(item_id_), volume_batch(volume_batch_), volume_id(volume_id_), weight(weight_), volume_m3(m3_) {}

    const ID& getItemID() const;

    const ID& getID() const;

    const ID& getGroup() const;

    std::string getFullID() const;

    double getWeight() const;

    double getCubic() const;
};
