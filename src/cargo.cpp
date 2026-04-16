#include "cargo.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cstdint>
#include <functional>
#include <sstream>


UnitCargo::UnitCargo(const Item& cargo_, uint32_t quantity_):
cargo(std::ref(cargo_)), quantity(quantity_) {}


double UnitCargo::getTotalWeight() const{
    return cargo.weight * quantity;
}

double UnitCargo::getTotalCubic() const{
    return cargo.m3 * quantity;
}

double UnitCargo::getTotalCents() const{
    return cargo.brute_value * quantity;
}

const Item& UnitCargo::getItem() const{
    return cargo;
}
uint32_t UnitCargo::getQuantity() const{
    return quantity;
}

uint32_t UnitCargo::getID() const{
    return cargo.identifier;
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
void UnitCargo::quantityDecrement(int32_t qnt) {quantity -= quantity;}




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
    auto it = cargos.begin();
    while(it != cargos.end()) {
        if(it->getID() == identifier) {
            cargos.erase(it);
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


std::string MultiCargo::format(bool indent) {
    if (cargos.empty()) {return "\tNo Itens";}

    std::ostringstream buffer;
    for(const UnitCargo& c: cargos) {
        buffer << (indent ? "\t": "")<< c.getQuantity() << "x | " << c.format() << "\n";
    }
    return buffer.str();
}
