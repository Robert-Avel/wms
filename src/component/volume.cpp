#include "volume.hpp"
#include "types.hpp"
#include <cstring>
#include <cstring>
#include <iostream>
#include <sstream>



const bruteID& Volume::getItemID() const {
    return this->item_id;
}


const bruteID& Volume::getBatchID() const {
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
        << "Weight: " << weight << '\n'
        << "m3: " << volume_m3 << '\n'
        << "Value: " << value << '\n';

    return buffer.str();
}
