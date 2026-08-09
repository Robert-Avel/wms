#include "volume.hpp"
#include "IDed_map.hpp"
#include "get_bytes.hpp"
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

    buffer << item_id;
    //buffer << volume_id;
    //buffer << volume_batch;
    //buffer << weight;
    //buffer << volume_m3;
    //buffer << value;

    return buffer;
}


Volume::Volume(ByteS& data) {
    this->value = 0;
    this->volume_m3 = 0;
    this->weight = 0;
    this->volume_batch = 0;
    this->volume_id = 0;
    data >> this->item_id;
}
