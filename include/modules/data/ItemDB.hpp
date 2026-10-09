#ifndef ITEM_DATA_BASE_HPP
#define ITEM_DATA_BASE_HPP

#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include <fstream>
#include <optional>


class ItemDataBase {
    public:
    bool saveFile(IdObj<Item> obj, std::ofstream& file);
    std::optional<IdObj<Item>> loadFile(std::ifstream& file);

    IdGroup<Item> data;

    ItemDataBase() = default;

    void saveAllFile(std::ofstream& file);
    bool loadAllFile(std::ifstream& file, size_t d_size);
};

#endif
