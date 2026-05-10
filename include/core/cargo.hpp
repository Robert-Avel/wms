#pragma once
#include "item.hpp"
#include "status.hpp"
#include <cstdint>
#include <list>


class UnitCargo {
    const Item& cargo;
    uint32_t quantity;

    public:
    UnitCargo(const Item& cargo_, uint32_t quantity_);


    double getTotalWeight() const;
    double getTotalCubic() const;
    double getTotalCents() const;
    const Item& getItem() const;
    uint32_t getID() const;
    uint32_t getQuantity() const;
    std::string format() const;

    void quantityIncrement(int32_t qnt);
    void quantityDecrement(int32_t qnt);
};


class MultiCargo {
    std::list<UnitCargo> cargos;
    uint32_t identifier;

    public:
    MultiCargo(uint32_t id);
    Status appendCargo(const UnitCargo& cargo);
    Status removeCargo(uint32_t identifier);

    double getTotalWeight();
    uint32_t getTotalCubic();
    cents getTotalCents();
    UnitCargo* getCargoByID(uint32_t identifier);
    uint32_t getTotalQuantity();
    std::string format(bool indent);
};
