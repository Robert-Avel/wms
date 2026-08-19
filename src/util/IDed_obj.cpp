#include "IDed_obj.hpp"
#include <cstdint>
#include <sys/types.h>


IDedObj::~IDedObj() {
    clearID();
    clearGroup();
}


bool IDedObj::clearID() {
    if(id != nullptr) {
        delete id;
        return true;
    }
    return false;
}
bool IDedObj::setID(uint64_t _id) {
    if (id == nullptr) {
        id = new uint64_t(_id);
        return true;
    }
    return false;
}


uint64_t* IDedObj::getID() {return id;}

bool IDedObj::clearGroup() {
    if(group != nullptr) {
        delete group;
        return true;
    }
    return false;
}
bool IDedObj::setGroup(uint32_t _group) {
    if (group == nullptr) {
        group = new uint32_t(_group);
        return true;
    }
    return false;
}
uint32_t* IDedObj::getGroup() {
    return group;
}
