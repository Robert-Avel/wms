#pragma once
#include "base_converter.hpp"
#include "item.hpp"
#include "status.hpp"
#include <fstream>


namespace wmr {
    namespace item {
        bool load(std::ifstream& file, std::string file_name);
        bool save(std::ofstream& file, std::string file_name);

        void setDataMode(basec::StdMode mode_);
        Status create(std::string name_, double m3_, double weight_, cents brute_value_);
        const Item* get(std::string id_);
    }
}
