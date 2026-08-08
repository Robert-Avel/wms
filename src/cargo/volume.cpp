#include "volume.hpp"
#include "IDed_map.hpp"
#include "get_bytes.hpp"
#include <cstring>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>


const bID& Volume::getItemID() const {
    return this->item_id;
}

const bID& Volume::getID() const {
    return this->volume_id;
}

const bID& Volume::getBatchID() const {
    return this->volume_batch;
}


double Volume::getWeight() const {return this->weight;}

double Volume::getCubic() const {return this->volume_m3;}

cents Volume::getValue() const {return this->value;}


std::string Volume::formatData() const {
    std::stringstream buffer;
    buffer
        << "Item: " << item_id << '\n'
        << "Batch: " << volume_batch << '\n'
        << "Volume: " << volume_id << '\n'
        << "Weight: " << weight << '\n'
        << "m3: " << volume_m3 << '\n'
        << "Value: " << value << '\n';

    return buffer.str();
}


std::vector<std::byte> Volume::getBytes() const {
    void* members[] = {
        (void*)&item_id,
        (void*)&volume_id,
        (void*)&volume_batch,
        (void*)&weight,
        (void*)&volume_m3,
        (void*)&value
    };

    size_t sizes[] = {
        sizeof(item_id),
        sizeof(volume_id),
        sizeof(volume_batch),
        sizeof(weight),
        sizeof(volume_m3),
        sizeof(value)
    };


    size_t objc_size = 0;
    for(size_t s: sizes) {objc_size += s;}

    std::vector<std::byte> output(objc_size);
    std::byte* data_ptr = output.data();
    for(int i = 0; i < 6; i++) {
        std::memcpy(data_ptr, members[i], sizes[i]);
        data_ptr += sizeof(sizes[i]);
    }

    return output;
}


Volume::Volume(std::vector<std::byte> data) {
    void* members[] = {
        (void*)&item_id,
        (void*)&volume_id,
        (void*)&volume_batch,
        (void*)&weight,
        (void*)&volume_m3,
        (void*)&value
    };

    size_t sizes[] = {
        sizeof(item_id),
        sizeof(volume_id),
        sizeof(volume_batch),
        sizeof(weight),
        sizeof(volume_m3),
        sizeof(value)
    };

    auto data_ptr = data.data();
    for(int i = 0; i < 6; i++) {
        std::memcpy(members[i], data_ptr, sizes[i]);
        data_ptr += sizeof(sizes[i]);
    }
}
