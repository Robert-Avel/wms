#include "cargo.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstddef>
#include <cstdint>


UnitCargo::UnitCargo(Item& cargo_, uint32_t quantity_) : cargo(cargo_)
{
    quantity = quantity_;
    cargo = cargo_;
}


inline double UnitCargo::getTotalWeight() const{
    return cargo.get().weight * quantity;
}

inline double UnitCargo::getTotalCubic() const{
    return cargo.get().m3 * quantity;
}

inline double UnitCargo::getTotalCents() const{
    return cargo.get().brute_value * quantity;
}

inline const Item& UnitCargo::getItem() const{
    return cargo;
}
inline uint32_t UnitCargo::getQuantity() const{
    return quantity;
}

inline uint32_t UnitCargo::getID() const{
    return cargo.get().identifier;
}


MultiCargo::MultiCargo(uint32_t id) {
    identifier = id;
}


Status MultiCargo::appendCargo(const UnitCargo& cargo) {
    for(UnitCargo& c: cargos) {
        if(c.getID() == cargo.getID()) {
            return W_ALREADY_EXIST;
        }
    }
    cargos.push_back(cargo);
    return W_SUCCESS;
}


Status MultiCargo::removeCargo(uint32_t identifier) {
    std::size_t s = cargos.size();
    for(size_t i = 0; i < s; i++) {
        if(cargos[i].getID() == identifier) {
            cargos.erase(cargos.begin() + i);
            return W_SUCCESS;
        }
    }
    return W_NOT_FOUND;
}


double MultiCargo::getTotalWeight() {
    int acc = 0;
    for(UnitCargo& c: cargos) {
        acc += c.getTotalWeight();
    }
    return acc;
}

uint32_t MultiCargo::getTotalCubic() {
    int acc = 0;
    for(UnitCargo& c: cargos) {
        acc += c.getTotalCubic();
    }
    return acc;
}

cents MultiCargo::getTotalCents() {
    int acc = 0;
    for(UnitCargo& c: cargos) {
        acc += c.getTotalCents();
    }
    return acc;
}

const Item* MultiCargo::getItem(uint32_t index) {
    if(cargos.size() < index || index < 0) {
        return nullptr;
    }
    else {
        return &cargos[index].getItem();
    }
}

const Item* MultiCargo::getItemByID(uint32_t identifier) {
    auto iterator = cargos.begin();
    while(iterator != cargos.end()) {
        if(iterator->getID() == identifier) {
            return &iterator->getItem();
        }
        ++iterator;
    }
    return nullptr;
}

uint32_t MultiCargo::getTotalQuantity() {
    int acc = 0;
    for(UnitCargo& c: cargos) {
        acc += c.getQuantity();
    }
    return acc;
}
