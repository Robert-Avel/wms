#pragma once

#include "item.hpp"
#include "cargo.hpp"
#include "status.hpp"
#include <cstdint>
#include <string>

class Warehouse {
  private:
  std::string identifier;
  cubic m3_capacity;
  MultiCargo multi_c;

  public:
  Warehouse(std::string __identifier, cubic __capacity);
  cubic getActual();
  cubic getCapacity() const;
  std::string getID() const;
  std::string format();


  Status cargoIncrement(const UnitCargo& uc);
  Status cargoRemove(const UnitCargo& uc);
  Status cargoDecrement(const Item& item, uint32_t qnt);
};
