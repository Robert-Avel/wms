#pragma once

#include "item.hpp"
#include "cargo.hpp"
#include "status.hpp"
#include <cstdint>
#include <string>

class Warehouse {
  private:
  std::string identifier;
  cubic actual;
  cubic capacity;
  MultiCargo multi_c;

  public:
  Warehouse(std::string __identifier, cubic __capacity);
  inline cubic getActual();
  inline cubic getCapacity();
  std::string getID();
  std::string format() const;


  Status addCargo(const UnitCargo& uc);
  Status addCargo(uint32_t __id);
  Status removeCargo(const UnitCargo& uc);
  Status removeCargo(uint32_t __id);
};
