#pragma once

#include <cstddef>
#include <cstdint>
#include <unordered_map>


template <class T>
class IDedMap {
    std::unordered_map<uint64_t, T> data;
    uint64_t next_id;

    uint64_t getNewID();

    public:
    IDedMap<T>(): next_id(1) {};
    IDedMap<T>(uint64_t next_id_): next_id(next_id_) {};

    uint64_t append(const T& i);

    bool insert(uint64_t id, const T& i);

    bool erase(uint64_t id);

    T* getItem(uint64_t id);


    size_t size() const;


    uint64_t showNexID() const;
    void setNexID(uint64_t id_);

    typename std::unordered_map<uint64_t, T>::iterator begin();

    typename std::unordered_map<uint64_t, T>::iterator end();

    bool isEmpty() const;
};
