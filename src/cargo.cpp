#include "cargo.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstddef>
#include <cstdint>
#include <sstream>


UnitCargo::UnitCargo(Item& cargo_, uint32_t quantity_) : cargo(cargo_)
{
    quantity = quantity_;
    cargo = cargo_;
}


double UnitCargo::getTotalWeight() const{
    return cargo.get().weight * quantity;
}

double UnitCargo::getTotalCubic() const{
    return cargo.get().m3 * quantity;
}

double UnitCargo::getTotalCents() const{
    return cargo.get().brute_value * quantity;
}

const Item& UnitCargo::getItem() const{
    return cargo;
}
uint32_t UnitCargo::getQuantity() const{
    return quantity;
}

uint32_t UnitCargo::getID() const{
    return cargo.get().identifier;
}

std::string UnitCargo::format() const {
    Item i = getItem();
    std::ostringstream buffer;
    buffer << i.identifier << " | "
           << i.global_name << " | "
           << i.weight << " | "
           << i.m3 << " | "
           << i.brute_value << "\n";
    return buffer.str();
}


void UnitCargo::quantityIncrement(int32_t qnt) {quantity += quantity;}




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

UnitCargo* MultiCargo::getCargo(uint32_t index) {
    if(cargos.size() < index || index < 0) {
        return nullptr;
    }
    else {
        return &cargos[index];
    }
}

UnitCargo* MultiCargo::getCargoByID(uint32_t identifier) {
    for(UnitCargo& u: cargos) {
        if(u.getID() == identifier) {
            return &u;
        }
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


std::string MultiCargo::format(bool indent) const {
    if (cargos.empty()) {return "\tNo Itens";}
    std::ostringstream buffer;
    for(const UnitCargo& c: cargos) {
        buffer << (indent ? "\t": "") << c.format() << "\n";
    }
    return buffer.str();
}
