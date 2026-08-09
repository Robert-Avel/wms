#include <cstddef>




class ByteS {
    unsigned char* _data;
    size_t _size;
    size_t allocated;

    bool expand(size_t __s);
    bool collapse(size_t __s);

    public:
    ByteS();
    ~ByteS();

    template<typename T>
    ByteS& operator<<(const T& other);

    template<typename T>
    bool operator>>(T& other);

    unsigned char* data();
    size_t size();
};
