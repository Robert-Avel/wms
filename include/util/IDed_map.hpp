#pragma once


#include "base_converter.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>


typedef uint64_t bID;
typedef std::string cID;


template <class T>
class IDedMap {
    std::unordered_map<uint64_t, T> data;
    basec::StdMode code_mode;
    uint64_t next_id;

    uint64_t getNewID();

    public:
    IDedMap<T>() = default;
    IDedMap<T>(basec::StdMode code_mode_): code_mode(code_mode_), next_id(1) {};
    IDedMap<T>(basec::StdMode code_mode_, uint64_t next_id_):
    code_mode(code_mode_), next_id(next_id_) {};

    bID append(const T& i);

    bool insert(uint64_t id, const T& i);

    bool erase(uint64_t id);

    bool erase(std::string& id);

    T* getItem(uint64_t id);

    T* getItem(const std::string& id);

    std::string codeID(uint64_t id__) const;

    uint64_t trueID(std::string id__) const;


    basec::StdMode getMode() const;


    size_t size() const;


    void setMode(basec::StdMode nw_mode);
    uint64_t showNexID() const;
    void setNexID(uint64_t id_);

    typename std::unordered_map<uint64_t, T>::iterator begin();

    typename std::unordered_map<uint64_t, T>::iterator end();

    bool isEmpty() const;
};
