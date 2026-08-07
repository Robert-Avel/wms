#include "base_converter.hpp"
#include <string>


class _config_wms {
    public:
    std::string item_db_name;
    basec::StdMode _item;
    basec::StdMode _volume;


    _config_wms(std::string item_file, basec::StdMode item = basec::NUMERIC, basec::StdMode volume = basec::ALPHABETIC):
    item_db_name(item_file), _item(item), _volume(volume) {}
};
