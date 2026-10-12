#ifndef VOLUME_DATA_BASE_HPP
#define VOLUME_DATA_BASE_HPP

#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "volume/volume.hpp"
#include <fstream>
#include <optional>


class VolumeDB {
    public:
    bool saveFile(IdObj<Volume> obj, std::ofstream& file);
    std::optional<IdObj<Volume>> loadFile(std::ifstream& file);

    IdGroup<Volume> data;

    VolumeDB() = default;

    void saveAllFile(std::ofstream& file);
    bool loadAllFile(std::ifstream& file, size_t d_size);
};

#endif
