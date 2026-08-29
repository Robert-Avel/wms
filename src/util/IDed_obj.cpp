#include "IDed_obj.hpp"
#include <cstdint>
#include <sys/types.h>


void IDedObj::setID(uint64_t _id) {
    this->id = _id;
}


uint64_t IDedObj::getID() {return id;}

void IDedObj::setGroup(uint32_t _group) {
    this->group = _group;
}

uint32_t IDedObj::getGroup() {
    return group;
}
