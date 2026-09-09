#include "group.hpp"
#include <cstdint>

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
