#include "volume/Volume.hpp"
#include <cstring>
#include <cstring>
#include <iostream>
#include <sstream>


const time_t& Volume::getCreatedIn() const {return this->created_in;}


const uint64_t& Volume::getItemID() const {
    return this->item_id;
}


const uint64_t& Volume::getBatchID() const {
    return this->volume_batch;
}


const uint32_t& Volume::getWeight() const {return this->weight_g;}

const uint32_t& Volume::getCubic() const {return this->cubic_cm;}

const cents& Volume::getValue() const {return this->value;}


std::string Volume::formatData() const {
    std::stringstream buffer;
    buffer
        << "Item: " << item_id << '\n'
        << "Batch: " << volume_batch << '\n'
        << "Created in: " << created_in << '\n'
        << "Weight: " << weight_g << '\n'
        << "cm3: " << cubic_cm << '\n'
        << "Value: " << value << '\n';

    return buffer.str();
}
