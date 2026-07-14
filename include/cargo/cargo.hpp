#pragma once
#include "item.hpp"
#include "status.hpp"
#include <cstddef>
#include <cstdint>
#include <list>
#include "volume.hpp"


class Cargo {
    std::list<Volume> cargos;
    ID cargo_id;

    public:
    Cargo(const ID id): cargo_id(id) {}

    Status appendVolume(const Volume& cargo);

    Status removeVolume(const ID& identifier);
    Status removeVolume(size_t index);

    double getTotalWeight();

    uint32_t getTotalCubic();

    cents getTotalCents();

    Volume* getCargoByID(uint32_t identifier);

    std::string format(bool indent);
};
