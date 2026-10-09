//Modulo de gerenciamento de Itens
#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include <cstdint>
#include <string>
#include <list>


class ItemManager  {
    IdGroup<Item>& linked_data;

    public:
        ItemManager() = delete;
        ItemManager(IdGroup<Item>& data): linked_data(data) {}

        const IdObj<Item>* getItem(uint64_t group, uint64_t id);
        uint64_t creteItem(uint64_t group, std::string global_name, uint32_t cubic_cm, uint32_t weight_g, cents value);
        std::list<const IdObj<Item>*> list(uint64_t group, uint32_t page);
};
