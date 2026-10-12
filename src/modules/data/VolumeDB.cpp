#include "data/VolumeDB.hpp"
#include "volume/Volume.hpp"
#include <iostream>

bool VolumeDB::saveFile(IdObj<Volume> obj, std::ofstream& file) {
    if(!file) {
        std::cerr << "File not open!\n";
        return false;
    }
    Volume& v = obj.getObj();

    file.write((char*) &obj.getGroup(), sizeof(uint64_t));
    file.write((char*) &obj.getID(), sizeof(uint64_t));

    file.write((char*) &v.getItemID(), sizeof(uint64_t));
    file.write((char*) &v.getWeight(), sizeof(uint32_t));
    file.write((char*) &v.getCubic(), sizeof(uint32_t));
    file.write((char*) &v.getValue(), sizeof(cents));
    file.write((char*) &v.getCreatedIn(), sizeof(time_t));
    file.write((char*) &v.getBatchID(), sizeof(uint64_t));

    return true;
}

std::optional<IdObj<Volume>>
VolumeDB::loadFile(std::ifstream& file) {
    std::optional<IdObj<Volume>> output;
    if(!file) {
        std::cerr << "File not open!\n";
        return output;
    }

    uint64_t group_id{0};
    uint64_t id{0};

    uint64_t item_id{0};
    uint32_t weight_g{0};
    uint32_t cubic_cm{0};
    cents value{0};

    time_t created_in{0};
    uint64_t volume_batch{0};

    file.read((char*) &group_id, sizeof(uint64_t));
    file.read((char*) &id, sizeof(uint64_t));

    file.read((char*) &item_id, sizeof(uint64_t));
    file.read((char*) &weight_g, sizeof(uint32_t));
    file.read((char*) &cubic_cm, sizeof(uint32_t));
    file.read((char*) &value, sizeof(cents));
    file.read((char*) &created_in, sizeof(time_t));
    file.read((char*) &volume_batch, sizeof(uint64_t));

    output = IdObj<Volume>{{item_id, weight_g, cubic_cm, value, volume_batch, created_in}, id, group_id};
    return output;
}


void VolumeDB::saveAllFile(std::ofstream& file) {
    for(auto& g: data) {
        for(auto& o: g.second) {
            saveFile(o.second, file);
        }
    }
}


bool VolumeDB::loadAllFile(std::ifstream& file, size_t d_size) {
    if(!file) {
        std::cerr << "File not open!\n";
        return false;
    }
    for(size_t i = 0; i < d_size; i++) {
        auto r = loadFile(file);
        if(r.has_value()) {
            data.insert(r->getGroup(), r->getID(), r->getObj(), true);
        }
    }
    return true;
}
