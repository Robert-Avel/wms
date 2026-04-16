#include "warehouse.hpp"
#include "cargo.hpp"
#include "status.hpp"
#include <cstdint>
#include <sstream>

Warehouse::Warehouse(std::string __identifier, cubic __capacity):  multi_c(0) {
    identifier = __identifier;
    m3_capacity = __capacity;
}

cubic Warehouse::getActual() {return multi_c.getTotalCubic();}
cubic Warehouse::getCapacity() const {return m3_capacity;}
std::string Warehouse::getID() const {return identifier;}

std::string Warehouse::format() {
    std::ostringstream buffer;
    buffer << "ID: " << identifier << "\n"
           << "Capacity: " << m3_capacity << "/" << getActual() << "\n"
           << "Itens: " << "\n" << multi_c.format(true);
    return buffer.str();
}



Status Warehouse::cargoIncrement(const UnitCargo& uc) {
    if(getActual() + uc.getTotalCubic() > m3_capacity) {return W_FULL;}

    if(multi_c.appendCargo(uc) == W_ALREADY_EXIST) {
        multi_c.getCargoByID(uc.getID())->quantityIncrement(uc.getQuantity());
    }
    return W_SUCCESS;
}

Status Warehouse::cargoRemove(const UnitCargo& uc) {
    UnitCargo* target = multi_c.getCargoByID(uc.getID());

    if(target == nullptr) {return W_NOT_FOUND;}
    multi_c.removeCargo(uc.getID());
    return W_SUCCESS;
}

Status Warehouse::cargoDecrement(const UnitCargo& uc, uint32_t qnt) {
    UnitCargo* target = multi_c.getCargoByID(uc.getID());
    if(target == nullptr) {return W_NOT_FOUND;}

    if(qnt >= target->getQuantity()) {
        cargoRemove(uc);
    } else {
        target->quantityDecrement(qnt);
    }
    return W_SUCCESS;
}
