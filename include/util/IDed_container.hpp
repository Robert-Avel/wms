#pragma once

#include "identificator.hpp"
#include "status.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>


template <class T>
class IDedContainer {
    std::unordered_map<uint64_t, T> data;
    IdMode code_mode;
    uint64_t next_id;

    uint64_t getNewID();

    public:
    IDedContainer<T>() = default;
    IDedContainer<T>(IdMode code_mode_): code_mode(code_mode_), next_id(1) {};

    void append(const T& i);
    Status insert(uint64_t id, const T& i);

    Status erase(uint64_t id);
    Status erase(std::string& id);
    Status erase(T& id);

    T* getItem(uint64_t id);
    T* getItem(const std::string& id);

    std::string codeID(uint64_t id__) const;
    uint64_t trueID(std::string id__) const;

    IdMode getMode() const;
    uint64_t showNexID() const;

    typename std::unordered_map<uint64_t, T>::iterator begin();
    typename std::unordered_map<uint64_t, T>::iterator end();

    bool isEmpty() const;
};
