#include "data/BaseDB.hpp"
#include "volume/Volume.hpp"
#include <iostream>

bool VolumeDBs::saveOne(const Obj& obj, std::ofstream& file) {
    const Volume& v = obj.cgetObj();

    file.write((char*) &obj.getGroup(), sizeof(uint64_t));
    file.write((char*) &obj.getID(), sizeof(uint64_t));

    file.write((char*) &v.getItemID(), sizeof(uint64_t));
    file.write((char*) &v.getWeight(), sizeof(uint32_t));
    file.write((char*) &v.getCubic(), sizeof(uint32_t));
    file.write((char*) &v.getValue(), sizeof(Cents));
    file.write((char*) &v.getCreatedIn(), sizeof(time_t));
    file.write((char*) &v.getBatchID(), sizeof(uint64_t));

    return true;
}

std::optional<VolumeDBs::Obj> VolumeDBs::loadOne(std::ifstream& file) {
    std::optional<VolumeDBs::Obj> output;
    if(!file) {
        std::cerr << "File not open!\n";
        return output;
    }

    uint64_t group_id{0};
    uint64_t id{0};

    uint64_t item_id{0};
    uint32_t weight_g{0};
    uint32_t cubic_cm{0};
    Cents value{0};

    time_t created_in{0};
    uint64_t volume_batch{0};

    file.read((char*) &group_id, sizeof(uint64_t));
    file.read((char*) &id, sizeof(uint64_t));

    file.read((char*) &item_id, sizeof(uint64_t));
    file.read((char*) &weight_g, sizeof(uint32_t));
    file.read((char*) &cubic_cm, sizeof(uint32_t));
    file.read((char*) &value, sizeof(Cents));
    file.read((char*) &created_in, sizeof(time_t));
    file.read((char*) &volume_batch, sizeof(uint64_t));

    output = IdObj<Volume>{{item_id, weight_g, cubic_cm, value, volume_batch, created_in}, id, group_id};
    return output;
}


bool VolumeDBs::insert(const Obj& o) {
    return data.insert(o.getGroup(), o.getID(), o.cgetObj(), true);
}


void VolumeDBs::saveIterator(std::ofstream& file) {
    for(auto& g: data) {
        for(auto& o: g.second) {
            saveOne(o.second, file);
        }
    }
}
