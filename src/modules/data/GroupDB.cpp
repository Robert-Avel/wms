#include "data/GroupDB.hpp"
#include <cstddef>
#include <cstdint>
#include <optional>
#include <utility>


bool GroupDB::saveFile(const std::pair<std::string, uint64_t>& obj, std::ofstream& file) {
    if(!file) {return false;}

    size_t ssize = obj.first.size();
    file.write((char*) &ssize, sizeof(size_t));
    file.write(obj.first.c_str(), ssize);
    file.write((char*) &obj.second, sizeof(uint64_t));

    return true;
}

std::optional<std::pair<std::string, uint64_t>> GroupDB::loadFile(std::ifstream& file) {
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



void GroupDB::saveAllFile(std::ofstream& file) {
    if(!file) {return;}

    for(auto& obj: this->data) {
        saveFile(obj, file);
    }
}

bool GroupDB::loadAllFile(std::ifstream& file, size_t d_size) {
    if(!file) {return false;}

    for(size_t i = 0; i < d_size; i++) {
        auto r = loadFile(file);
        if(r.has_value()) {this->data.insert(r.value());}
    }
    return true;
}
