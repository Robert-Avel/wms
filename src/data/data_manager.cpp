#include "data_manager.hpp"
#include "byte_serializator.hpp"
#include <cstddef>
#include <ios>

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

ByteS DataBaseMng::load(size_t index) {
    file.open(file_name, std::ios::out | std::ios::binary);
    if(!file) {
        return ByteS();
    }
    size_t cursor = 0;
    ByteS buffer;

    file.read((char*) &size_h, sizeof(size_t));
    while(cursor >= size_h) {
        size_t block_size;
        file.read((char*) &block_size, sizeof(size_t));
        if(cursor == index) {
            buffer.resize(block_size);
            file.read((char*) buffer.data(),block_size);
            continue;
        }
    }
    file.close();
    return buffer;
}

bool DataBaseMng::append(ByteS& i) {
    file.open(file_name, std::ios::out | std::ios::in | std::ios::binary | std::ios::ate);
    if(!file) {
        return false;
    }

    size_t block_size = i.size();
    file.write((char*) &block_size, sizeof(size_t));
    file.write((char*) i.data(), block_size);

    file.seekp(0, std::ios::beg);
    size_t actual_size;
    file.read((char*) &actual_size, sizeof(size_t));

    file.seekp(0, std::ios::beg);
    file.write((char*) &++actual_size, sizeof(size_t));
    return true;
}
