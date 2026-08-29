#include <cstddef>
#include <fstream>


class DataBaseMng {
    std::fstream file;
    std::string file_name;

    public:
    DataBaseMng(std::string filename): file_name(filename) {}
    ~DataBaseMng();

    size_t size();

    template<typename T>
    T load(size_t index);

    template<typename T>
    void save(T& i);


};
