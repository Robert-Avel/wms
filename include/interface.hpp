#pragma once
#include <optional>
#include "identificator.hpp"
#include "item.hpp"
#include "item_data.hpp"
#include "status.hpp"


class RobertWMS {
    ItemData itens;


    public:
        RobertWMS() = default;

        void setItemDataMode(IdMode mode_);
        Status newItem(std::string name_, double m3_, double weight_, cents brute_value_);
        const Item* getItem(std::string id_);
};
