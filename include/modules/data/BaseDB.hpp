#pragma once
#include "GroupMngr.hpp"
#include "IdGroup.hpp"
#include "IdMap.hpp"
#include "IdObj.hpp"
#include "warehouse/Warehouse.hpp"
#include "item/Item.hpp"
#include "volume/Volume.hpp"
#include <cstddef>
#include <optional>
#include <fstream>

template<class Container, class Obj>
class BaseDB {
    protected:

        virtual bool saveOne(const Obj& obj, std::ofstream& file) = 0;
        virtual std::optional<Obj> loadOne(std::ifstream& file) = 0;
        virtual bool insert(const Obj& o) = 0;
        virtual void saveIterator(std::ofstream& file) = 0;

    public:
    Container data;

    BaseDB() = default;
    virtual ~BaseDB() = default;

    bool saveAllFile(std::ofstream& file) {
        if(!file) {return false;}

        saveIterator(file);
        return true;
    }

    bool loadAllFile(std::ifstream& file, size_t d_size) {
        if(!file) {return false;}

        for(size_t i = 0; i < d_size; i++) {
            const auto l_obj = loadOne(file);
            if(l_obj.has_value()) {
                this->insert(l_obj.value());
            }
        }
        return true;
    }

    bool loadAllFile(std::ifstream& file) {
        if(!file) {return false;}
        size_t ssize;
        file.read((char*) &ssize, sizeof(size_t));
        return loadAllFile(file, ssize);
    }
};


class GroupDBs : public BaseDB<StrMap, std::pair<std::string, uint64_t>> {
public:
    using Obj = std::pair<std::string, uint64_t>;

    bool saveOne(const Obj& obj, std::ofstream& file) override;
    std::optional<Obj> loadOne(std::ifstream& file) override;
    bool insert(const Obj& o) override;
    void saveIterator(std::ofstream& file) override;
};

// --- ItemDBs ---
class ItemDBs : public BaseDB<IdGroup<Item>, IdObj<Item>> {
public:
    using Obj = IdObj<Item>;

    bool saveOne(const Obj& obj, std::ofstream& file) override;
    std::optional<Obj> loadOne(std::ifstream& file) override;
    bool insert(const Obj& o) override;
    void saveIterator(std::ofstream& file) override;
};

// --- VolumeDBs ---
class VolumeDBs : public BaseDB<IdGroup<Volume>, IdObj<Volume>> {
public:
    using Obj = IdObj<Volume>;

    bool saveOne(const Obj& obj, std::ofstream& file) override;
    std::optional<Obj> loadOne(std::ifstream& file) override;
    bool insert(const Obj& o) override;
    void saveIterator(std::ofstream& file) override;
};

// --- WarehouseDBs ---
class WarehouseDBs : public BaseDB<IdMap<Warehouse>, std::pair<uint64_t, Warehouse>> {
public:
    using Obj = std::pair<uint64_t, Warehouse>;

    bool saveOne(const Obj& obj, std::ofstream& file) override;
    std::optional<Obj> loadOne(std::ifstream& file) override;
    bool insert(const Obj& o) override;
    void saveIterator(std::ofstream& file) override;
};
