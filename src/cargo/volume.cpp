#include "volume.hpp"
#include "IDed_map.hpp"
#include "byte_serializator.hpp"
#include <cstring>
#include <cstring>
#include <iostream>
#include <sstream>


const bID& Volume::getItemID() const {
    return this->item_id;
}

const bID& Volume::getID() const {
    return this->volume_id;
}

const bID& Volume::getBatchID() const {
    return this->volume_batch;
}


double Volume::getWeight() const {return this->weight;}

double Volume::getCubic() const {return this->volume_m3;}

cents Volume::getValue() const {return this->value;}


std::string Volume::formatData() const {
    std::stringstream buffer;
    buffer
        << "Item: " << item_id << '\n'
        << "Batch: " << volume_batch << '\n'
        << "Volume: " << volume_id << '\n'
        << "Weight: " << weight << '\n'
        << "m3: " << volume_m3 << '\n'
        << "Value: " << value << '\n';

    return buffer.str();
}


ByteS Volume::getBytes() const {
    ByteS buffer{};

    buffer.append((char*)&item_id, sizeof(item_id))
        .append((char*)&volume_id, sizeof(volume_id))
        .append((char*)&volume_batch, sizeof(volume_batch))
        .append((char*)&weight, sizeof(weight))
        .append((char*)&volume_m3, sizeof(volume_m3))
        .append((char*)&value, sizeof(value));

    return buffer;
}


Volume::Volume(ByteS& data) {
    data.pop((char*)&this->item_id, sizeof(item_id));
    data.pop((char*)&this->volume_id, sizeof(volume_id));
    data.pop((char*)&this->volume_batch, sizeof(volume_batch));
    data.pop((char*)&this->weight, sizeof(weight));
    data.pop((char*)&this->volume_m3, sizeof(volume_m3));
    data.pop((char*)&this->value, sizeof(value));
}
