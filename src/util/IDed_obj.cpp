#include "IDed_obj.hpp"
#include <cstdint>
#include <sys/types.h>


void IDedObj::setID(uint64_t _id) {
    this->id = _id;
}


uint64_t IDedObj::getID() const {return id;}

void IDedObj::setGroup(uint32_t _group) {
    this->group = _group;
}

uint32_t IDedObj::getGroup() const {
    return group;
}


std::size_t IDedObj::hashID(uint64_t group, uint64_t id) {
    std::hash<std::string> hasher;
    std::stringstream final_id;

    final_id << id << "-" << group;
    return hasher(final_id.str());
}

std::size_t IDedObj::hashID() {
    return hashID(this->group, this->id);
}
