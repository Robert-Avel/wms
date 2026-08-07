#include "IDed_map.hpp"
#include <cstdint>

template<class T>
bool IDedMap<T>::isEmpty() const {
    return data.empty();
}


template<class T>
uint64_t IDedMap<T>::showNexID() const {
    return next_id;
}

template<class T>
void IDedMap<T>::setNexID(uint64_t id_) {
    this->next_id = id_;
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
bID IDedMap<T>::append(const T& i) {
    bID id = getNewID();
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
bool IDedMap<T>::erase(uint64_t id) {
    if (data.find(id) == data.end()) {
        return false;
    }
    data.erase(id);
    return true;
}


template <class T>
T* IDedMap<T>::getItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return nullptr;
    }
    return &data.at(id);
}

template <class T>
size_t IDedMap<T>::size() const {
    return data.size();
}
