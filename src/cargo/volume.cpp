#include "volume.hpp"
#include <sstream>
#include <string>

const ID& Volume::getItemID() const {return this->item_id;}

const ID& Volume::getID() const {return this->volume_id;}

const ID& Volume::getGroup() const {return this->volume_batch;}

std::string Volume::getFullID() const {
    std::stringstream buffer;
    buffer << volume_id.Str() << "-" << volume_batch.Str() << "-" << item_id.Str();
    return buffer.str();
}

double Volume::getWeight() const {return this->weight;}

double Volume::getCubic() const {return this->volume_m3;}
