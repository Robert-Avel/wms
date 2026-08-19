#include "IDed_map.hpp"
#include "volume.hpp"
#include <string>


class DataManager {
    public:
    IDedMap<Item> item_d;
    IDedMap<Volume> volume_d;


    bool saveItem(std::string& filename);
    bool loadItem(std::string& filename);
    void loadItem(IDedMap<Item>& itens) {
        item_d = itens;
    }

    bool saveVolume(std::string& filename);
    bool loadVolume(std::string& filename);
    void loadVolume(IDedMap<Volume>& volume) {
        volume_d = volume;
    }
};
