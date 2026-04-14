#include "warehouse.hpp"
#include "cargo.hpp"
#include "status.hpp"
#include <cstdint>
#include <sstream>

Warehouse::Warehouse(std::string __identifier, cubic __capacity):  multi_c(0) {
    identifier = __identifier;
    capacity = __capacity;
    actual = 0;
}

inline cubic Warehouse::getActual() {return actual;}
inline cubic Warehouse::getCapacity() {return capacity;}
std::string Warehouse::getID() {return identifier;}

std::string Warehouse::format() const {
    std::ostringstream buffer;
    buffer << "ID: " << identifier << "\n"
           << "Capacity: " << capacity << "/" << actual << "\n"
           << "Itens: " << "\n" << multi_c.format(true);
    return buffer.str();
}



Status Warehouse::addCargo(const UnitCargo& uc) {
    if(actual + uc.getTotalCubic() > capacity) {return W_FULL;}

    if(multi_c.appendCargo(uc) == W_ALREADY_EXIST) {
        multi_c.getCargoByID(uc.getID())->quantityIncrement(uc.getQuantity());
    }
    return W_SUCCESS;
}

Status Warehouse::addCargo(uint32_t __id) {

}

Status Warehouse::removeCargo(const UnitCargo& uc) {

}

Status Warehouse::removeCargo(uint32_t __id) {

}
