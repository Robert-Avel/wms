#include "data_manager.hpp"
#include <ios>
#define CONFIG_FILE "config_wms.bin"

DataBaseMng::~DataBaseMng() {
    if(file.is_open()) {
        file.close();
    }
}

size_t DataBaseMng::size() {
    if(!file) {
        file.open(file_name, std::ios::out | std::ios::binary);
    }
    size_t size;
    file.write((char*) &size, sizeof(size_t));
    return size;
}

template<typename T>
T DataBaseMng::load(size_t index) {
    file.open(file_name, std::ios::out | std::ios::binary);
    file.
}

template<typename T>
void DataBaseMng::save(T& i) {

}
