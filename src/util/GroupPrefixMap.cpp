#include "GroupPrefixMap.hpp"


uint64_t* GroupPrefixMap::translateGName(std::string name) {
    if(this->find(name) == this->end()) {return nullptr;};
    return &this->at(name);
}
