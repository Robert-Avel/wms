#pragma once

#include "item.hpp"
#include "cargo.hpp"
#include <string>

class Werehouse {
  private:
  std::string identifier;
  cubic actual;
  cubic capacity;
  MultiCargo wh;

  public:
  Werehouse(std::string __identifier, cubic __capacity);
  const cubic getActual();
  const cubic getCapacity();
  const std::string getID();


};
