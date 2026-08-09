#include "byte_serializator.hpp"
#include <cstddef>
#include <cstring>


bool ByteS::expand(size_t size) {
    if(_data == nullptr) {
        this->_data = new unsigned char[size]();
        allocated += size;
        return true;
    }
    size_t old_s = allocated;
    allocated += size;

    unsigned char* old_d = _data;
    this->_data = new unsigned char[allocated];

    memcpy(_data, old_d, old_s);

    delete [] old_d;
    return true;
}


bool ByteS::collapse(size_t __s) {
    if (_data == nullptr || __s > allocated) {
        return false;
    }

    allocated -= __s;
    if(allocated == 0) {
        delete [] _data;
        _size = 0;
        _data = nullptr;
        return true;
    }

    unsigned char* n_data = new unsigned char[allocated]();
    memcpy(n_data, _data, allocated);

    delete [] _data;
    _data = n_data;
    if (_size > allocated) {
        _size = allocated;
    }
    return true;
}



ByteS::ByteS(): _data(nullptr), _size(0), allocated(0) {}
ByteS::~ByteS() {
    if (_data != nullptr) {
        delete [] _data;
    }
}

template<typename T>
ByteS& ByteS::operator<<(const T& other) {
    size_t other_size = sizeof(other);
    if (_size + other_size > allocated) {
        expand(_size + other_size - allocated);
    }

    const unsigned char* input_ptr = reinterpret_cast<const unsigned char*>(&other);
    unsigned char* data_ptr = _data + _size;
    memcpy(data_ptr, input_ptr, other_size);
    _size += other_size;

    return *this;
}


template<typename T>
bool ByteS::operator>>(T& other) {
    size_t other_size = sizeof(other);
    if(_size < other_size) {
        return false;
    }

    unsigned char* output_ptr = reinterpret_cast<unsigned char*>(&other);
    unsigned char* data_ptr = _data + _size - other_size;
    memcpy(output_ptr, data_ptr, other_size);
    _size -= other_size;
    collapse(other_size);

    return true;
}

unsigned char* ByteS::data() {return _data;}
size_t ByteS::size() {return _size;}


template ByteS& ByteS::operator<< <ByteS>(const ByteS& other);
template ByteS& ByteS::operator<< <unsigned long>(const unsigned long& other);
template ByteS& ByteS::operator<< <double>(const double& other);
template ByteS& ByteS::operator<< <unsigned int>(const unsigned int& other);

template bool ByteS::operator>><unsigned int>(unsigned int&);
template bool ByteS::operator>><double>(double&);
template bool ByteS::operator>><unsigned long>(unsigned long&);
