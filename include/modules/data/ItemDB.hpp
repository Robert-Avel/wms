#ifndef ITEM_DB_HPP
#define ITEM_DB_HPP

#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "item/Item.hpp"
#include <fstream>
#include <optional>


class ItemDB {
    public:
    bool saveFile(IdObj<Item> obj, std::ofstream& file);
    std::optional<IdObj<Item>> loadFile(std::ifstream& file);

    IdGroup<Item> data;

    ItemDB() = default;

    void saveAllFile(std::ofstream& file);
    bool loadAllFile(std::ifstream& file, size_t d_size);
};

#endif
