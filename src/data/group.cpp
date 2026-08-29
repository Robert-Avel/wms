#include "group.hpp"
#include <cstdint>

template <class T>
IDedMap<T>* GroupMap<T>::getGroup(uint64_t group_id) {
    return groups.getItem(group_id);
}

template <class T>
IDedMap<T>* GroupMap<T>::getGroup(std::string prefix) {
    return groups.getItem(prefixs.at(prefix));
}

template <class T>
bool GroupMap<T>::newGroup(std::string prefix) {
    if(prefixs.find(prefix) != prefixs.end()) {return false;}

    uint64_t g_id = groups.append();
    prefixs.insert({prefix, g_id});
    return true;
}

template <class T>
bool GroupMap<T>::removeGroup(std::string prefix) {
    if(prefixs.find(prefix) == prefixs.end()) {return false;}

    groups.erase(prefixs.at(prefix));
    prefixs.erase(prefix);
    return true;
}

template <class T>
bool GroupMap<T>::removeGroup(uint64_t group_id) {
    if(groups.getItem(group_id) == nullptr) {return false;}

    groups.erase(group_id);
    auto it = prefixs.begin();
    while (it != prefixs.end()) {
        if(it->second == group_id) {
            prefixs.erase(it);
        }
        it++;
    }
    return true;
}
