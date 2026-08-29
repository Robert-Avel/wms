#include "item.hpp"
#include "volume.hpp"
#include "group.hpp"
#include <sqlite3.h>

class WMSData {
    public:
    GroupMap<Volume> volumes;
    GroupMap<Item> itens;
};
