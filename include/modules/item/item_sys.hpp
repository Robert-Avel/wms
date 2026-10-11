//Modulo de gerenciamento de Itens
#include "GroupMngr.hpp"
#include "IdGroup.hpp"
#include "IdObj.hpp"
#include "item/item.hpp"
#include <cstdint>
#include <string>
#include <list>


class ItemManager  {
    IdGroup<Item>& linked_data;
    GroupMngr& group_sys;

    public:
        ItemManager() = delete;
        ItemManager(IdGroup<Item>& data, GroupMngr& group_):
        linked_data(data), group_sys(group_)
        {}

        const IdObj<Item>* getItem(uint64_t group, uint64_t id);
        const IdObj<Item>* getItem(std::string group, uint64_t id);

        uint64_t creteItem(uint64_t group, std::string global_name, uint32_t cubic_cm, uint32_t weight_g, cents value);
        uint64_t creteItem(std::string group, std::string global_name, uint32_t cubic_cm, uint32_t weight_g, cents value);

        std::list<const IdObj<Item>*> list(uint64_t group, uint32_t page);
        std::list<const IdObj<Item>*> list(std::string group, uint32_t page);
};
