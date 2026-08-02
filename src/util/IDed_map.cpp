#include "base_converter.hpp"
#include "IDed_map.hpp"
#include <cstdint>
#include <string>

template<class T>
bool IDedMap<T>::isEmpty() const {
    return data.empty();
}

template<class T>
basec::StdMode IDedMap<T>::getMode() const {
    return code_mode;
}


template<class T>
uint64_t IDedMap<T>::showNexID() const {
    return next_id;
}


template<class T>
uint64_t IDedMap<T>::getNewID() {
    return next_id++;
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IDedMap<T>::begin() {
    return data.begin();
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IDedMap<T>::end() {
    return data.end();
}


template <class T>
ID IDedMap<T>::append(const T& i) {
    ID id = getNewID();
    data.insert({id, i});
    return id;
}


template <class T>
bool IDedMap<T>::insert(uint64_t id, const T& i) {
    if(data.find(id) != data.end()) {return false;}

    data.insert({id, i});
    return true;
}


template <class T>
std::string IDedMap<T>::codeID(uint64_t id__) const {
    return basec::intToBase(id__, code_mode);
}


template <class T>
uint64_t IDedMap<T>::trueID(std::string id__) const {
    return basec::baseToInt(id__, code_mode);
}


template <class T>
bool IDedMap<T>::erase(uint64_t id) {
    if (data.find(id) == data.end()) {
        return false;
    }
    data.erase(id);
    return true;
}


template <class T>
bool IDedMap<T>::erase(std::string& id) {
    return erase(IDedMap<T>::trueID(id));
}

template <class T>
T* IDedMap<T>::getItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return nullptr;
    }
    return &data.at(id);
}

template <class T>
T* IDedMap<T>::getItem(const std::string& id) {
    return getItem(IDedMap<T>::trueID(id));
}

template <class T>
size_t IDedMap<T>::size() const {
    return data.size();
}

template <class T>
void IDedMap<T>::setMode(basec::StdMode nw_mode) {
    this->code_mode = nw_mode;
}
