#pragma once


#include "base_converter.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>


typedef uint64_t ID;


template <class T>
class IDedContainer {
    std::unordered_map<uint64_t, T> data;
    basec::StdMode code_mode;
    uint64_t next_id;

    uint64_t getNewID() {
        return next_id++;
    }

    public:
    IDedContainer<T>() = default;
    IDedContainer<T>(basec::StdMode code_mode_): code_mode(code_mode_), next_id(1) {};

    void append(const T& i) {
        data.insert({getNewID(), i});
    }

    bool insert(uint64_t id, const T& i) {
        if(!(data.find(id) == data.end())) {return false;}

        data.insert({id, i});
        return true;
    }

    bool erase(uint64_t id) {
        if (data.find(id) == data.end()) {
            return false;
        }
        data.erase(id);
        return true;
    }

    bool erase(std::string& id) {
        return erase(this->trueID(id));
    }

    T* getItem(uint64_t id) {
        if (data.find(id) == data.end()) {
            return nullptr;
        }
        return &data.at(id);
    }

    T* getItem(const std::string& id) {
        return getItem(this->trueID(id));
    }

    std::string codeID(uint64_t id__) const {
        return basec::fintToBase(id__, code_mode);
    }

    uint64_t trueID(std::string id__) const {
        return basec::baseToInt(id__, code_mode);
    }


    basec::StdMode getMode() const {
        return code_mode;
    }


    size_t size() const {
        return data.size();
    }


    void setMode(basec::StdMode nw_mode) {
        this->code_mode = nw_mode;
    }

    uint64_t showNexID() const {
        return next_id;
    }

    typename std::unordered_map<uint64_t, T>::iterator begin() {
        return data.begin();
    }

    typename std::unordered_map<uint64_t, T>::iterator end() {
        return data.end();
    }

    bool isEmpty() const {
        return data.empty();
    }
};
