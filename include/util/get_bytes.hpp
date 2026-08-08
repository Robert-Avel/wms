#include <cstddef>
#include <cstring>
#include <vector>

namespace util
{
template<typename T>
std::vector<std::byte> getBytes(T* _obj) {

    size_t _obj_size = sizeof(*_obj);
    std::vector<std::byte> output(_obj_size);
    //std::byte* byte_ptr = (std::byte*) _obj;

    std::memcpy(output.data(), reinterpret_cast<const void*>(_obj), _obj_size);
    return output;
}
}
