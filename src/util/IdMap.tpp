#include <cstdint>

#ifndef ID_MAP_HPP
#include "IdMap.hpp" //ignore
#endif

template<class T>
bool IdMap<T>::isEmpty() const {
    return data.empty();
}


template<class T>
uint64_t IdMap<T>::showNexID() const {
    return next_id;
}

template<class T>
void IdMap<T>::setNexID(uint64_t id_) {
    this->next_id = id_;
}

template<class T>
uint64_t IdMap<T>::getNewID() {
    return next_id++;
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IdMap<T>::begin() {
    return data.begin();
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IdMap<T>::end() {
    return data.end();
}


template <class T>
uint64_t IdMap<T>::append(const T& i) {
    uint64_t id = getNewID();
    data.insert({id, i});
    return id;
}


template <class T>
bool IdMap<T>::insert(uint64_t id, const T& i) {
    if(data.find(id) != data.end()) {return false;}

    data.insert({id, i});
    return true;
}


template <class T>
bool IdMap<T>::erase(uint64_t id) {
    if (data.find(id) == data.end()) {
        return false;
    }
    data.erase(id);
    return true;
}


template <class T>
T* IdMap<T>::getItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return nullptr;
    }
    return &data.at(id);
}

template <class T>
size_t IdMap<T>::size() const {
    return data.size();
}

template <class T>
void IdMap<T>::uptadeLastID() {
    if(data.empty()) {return;}

    uint64_t last_id = 1;
    for(auto& id: this->data) {
        if(id.first > last_id) {
            last_id = id.first;
        }
    }
    this->next_id = last_id + 1;
}
