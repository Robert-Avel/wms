#pragma once
#include "IDed_map.hpp"
#include "volume.hpp"

class VolumeSys {
    IDedMap<Volume>& volumes;

    public:
        VolumeSys(IDedMap<Volume>& db): volumes(db) {}


};
