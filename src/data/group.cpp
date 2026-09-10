#include "group.hpp"
#include <cstdint>

template <class T>
IDedMap<T>* GroupMap<T>::createGroupIfNotExist(uint64_t group_id) {
    IDedMap<T>* g = groups.getItem(group_id);
    if(g == nullptr) {
        this->newGroup(group_id);
        g = groups.getItem(group_id);
    }
    return g;
}


template <class T>
IDedMap<T>* GroupMap<T>::getGroup(uint64_t group_id) {
    return groups.getItem(group_id);
}


template <class T>
uint64_t GroupMap<T>::newGroup() {
    IDedMap<T> new_group{};
    uint64_t g_id = groups.append(new_group);
    return g_id;
}

template <class T>
bool GroupMap<T>::newGroup(uint64_t id) {
    IDedMap<T> new_group{};
    return groups.insert(id, new_group);
}

template <class T>
bool GroupMap<T>::removeGroup(uint64_t group_id) {
    if(groups.getItem(group_id) == nullptr) {return false;}

    return groups.erase(group_id);
}


template <class T>
uint64_t GroupMap<T>::append(uint64_t group_id, T& i, bool create_group) {
    IDedMap<T>* g;
    if(create_group) {
        g = createGroupIfNotExist(group_id);
    } else {
        g = groups.getItem(group_id);
    }

    return g->append(i);
}

template <class T>
bool GroupMap<T>::insert(uint64_t group_id, uint64_t id, T& i, bool create_group) {
    IDedMap<T>* g;
    if(create_group) {
        g = createGroupIfNotExist(group_id);
    } else {
        g = groups.getItem(group_id);
    }

    return g->insert(id, i);
}

template <class T>
size_t GroupMap<T>::size() {
    return this->groups.size();
}