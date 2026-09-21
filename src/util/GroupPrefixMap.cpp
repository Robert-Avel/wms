#include "GroupPrefixMap.hpp"


uint64_t* GroupPrefixMap::translateGName(std::string name) {
    if(this->find(name) == this->end()) {return nullptr;};
    return &this->at(name);
}


bool GroupPrefixMap::hasPrefix(uint64_t i) const {
    for(auto& it: *this) {
        if(it.second == i) {
            return true;
        }
    }
    return false;
}
