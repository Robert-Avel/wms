#include "item.hpp"
#include "status.hpp"
#include <unordered_map>


class ItemData {
    std::unordered_map<ID, Item> data;

    public:
    ItemData() = default;

    Status newItem(const Item& i);
    Status newItem(ID identifier_, std::string global_name_, double m3_, double weight_, cents brute_value_);

    Status removeItem(ID id);

    const Item* getItem(ID id);
};
