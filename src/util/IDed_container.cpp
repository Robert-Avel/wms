#include "base_converter.hpp"
#include "IDed_container.hpp"
#include "status.hpp"
#include <cstdint>
#include <string>

template<class T>
bool IDedContainer<T>::isEmpty() const {
    return data.empty();
}

template<class T>
IdMode IDedContainer<T>::getMode() const {
    return code_mode;
}


template<class T>
uint64_t IDedContainer<T>::showNexID() const {
    return next_id;
}


template<class T>
uint64_t IDedContainer<T>::getNewID() {
    return next_id++;
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IDedContainer<T>::begin() {
    return data.begin();
}

template<class T>
typename std::unordered_map<uint64_t, T>::iterator IDedContainer<T>::end() {
    return data.end();
}


template <class T>
void IDedContainer<T>::append(const T& i) {
    data.insert({getNewID(), i});
}


template <class T>
Status IDedContainer<T>::insert(uint64_t id, const T& i) {
    if(!data.find(id) == data.end()) {return Status::ALREADY_EXIST;}

    data.insert({id, i});
    return Status::SUCCESS;
}


template <class T>
std::string IDedContainer<T>::codeID(uint64_t id__) const {
    return intToBase(id__, code_mode);
}


template <class T>
uint64_t IDedContainer<T>::trueID(std::string id__) const {
    return BaseToInt(id__, code_mode, ID::hasNum(code_mode));
}


template <class T>
Status IDedContainer<T>::erase(uint64_t id) {
    if (data.find(id) == data.end()) {
        return NOT_FOUND;
    }
    data.erase(id);
    return SUCCESS;
}


template <class T>
Status IDedContainer<T>::erase(std::string& id) {
    return erase(IDedContainer<T>::trueID(id));
}

template <class T>
T* IDedContainer<T>::getItem(uint64_t id) {
    if (data.find(id) == data.end()) {
        return nullptr;
    }
    return &data.at(id);
}

template <class T>
T* IDedContainer<T>::getItem(const std::string& id) {
    return getItem(IDedContainer<T>::trueID(id));
}
