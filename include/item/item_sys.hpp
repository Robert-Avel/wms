#include "base_converter.hpp"
#include "item.hpp"
#include "IDed_map.hpp"
#include <list>
#include <string>

class ItemSys {
    IDedMap<Item> itens;
    std::string item_db_name;
    basec::StdMode code_mode;

    public:
    bool load();
    bool save();

    ItemSys(std::string db_name, basec::StdMode mode): item_db_name(db_name), code_mode(mode) {}

    cID create(std::string name, double weight, double cubic, cents value);
    Item* info(cID id_);
    std::list<std::pair<cID, const Item*>> list(uint32_t page);
    std::list<std::pair<cID, const Item*>> search(std::string name);
};
