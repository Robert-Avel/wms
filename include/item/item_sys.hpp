#include "base_converter.hpp"
#include "byte_serializator.hpp"
#include "item.hpp"
#include "IDed_map.hpp"
#include <list>
#include <string>

class ItemSys {
    IDedMap<Item> itens;
    basec::StdMode code_mode;

    public:
    ByteS getByte();

    ItemSys(basec::StdMode mode): code_mode(mode) {}
    ItemSys(ByteS& __bs);

    cID create(std::string name, double weight, double cubic, cents value);
    Item* info(cID id_);
    std::list<std::pair<cID, const Item*>> list(uint32_t page);
    std::list<std::pair<cID, const Item*>> search(std::string name);
};
