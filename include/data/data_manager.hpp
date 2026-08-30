#include "byte_serializator.hpp"
#include <cstddef>
#include <fstream>


class DataBaseMng {
    std::fstream file;
    std::string file_name;
    size_t size_h;


    public:
    DataBaseMng(std::string filename): file_name(filename), size_h(0) {}
    ~DataBaseMng();

    size_t size();

    ByteS load(size_t index);

    bool append(ByteS& i);
};
