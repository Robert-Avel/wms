#include <cstddef>
#include <cstdint>
#include <optional>
#include <utility>
#include "data/BaseDB.hpp"


bool GroupDBs::saveOne(const Obj& obj, std::ofstream& file) {
    size_t ssize = obj.first.size();
    file.write((char*) &ssize, sizeof(size_t));
    file.write(obj.first.c_str(), ssize);
    file.write((char*) &obj.second, sizeof(uint64_t));

    return true;
}

std::optional<GroupDBs::Obj> GroupDBs::loadOne(std::ifstream& file) {
    std::optional<std::pair<std::string, uint64_t>> output;
    if(!file) {return output;}

    size_t ssize;
    file.read((char*) &ssize, sizeof(size_t));

    std::string name(ssize, '\0');
    file.read(name.data(), ssize);

    uint64_t id;
    file.read((char*) &id, sizeof(uint64_t));

    output = {name, id};
    return output;
}


bool GroupDBs::insert(const Obj& o) {
    data.insert({o.first, o.second});
    return true;
}


void GroupDBs::saveIterator(std::ofstream& file) {
    if(!file) {return;}

    for(auto& obj: this->data) {
        saveOne(obj, file);
    }
}
