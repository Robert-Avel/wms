
#include "IdObj.hpp"
#include <cstdint>

#ifndef ID_GROUP_HPP
#include "IdGroup.hpp"
#endif

template <class T>
Group<T>* IdGroup<T>::createGroupIfNotExist(uint64_t group_id) {
    Group<T>* g = groups.getItem(group_id);
    if(g == nullptr) {
        this->newGroup(group_id);
        g = groups.getItem(group_id);
    }
    return g;
}


template <class T>
Group<T>* IdGroup<T>::getGroup(uint64_t group_id) {
    return groups.getItem(group_id);
}


template <class T>
uint64_t IdGroup<T>::newGroup() {
    Group<T> new_group;
    uint64_t g_id = groups.append(new_group);
    return g_id;
}

template <class T>
bool IdGroup<T>::newGroup(uint64_t id) {
    Group<T> new_group;
    return groups.insert(id, new_group);
}

template <class T>
bool IdGroup<T>::removeGroup(uint64_t group_id) {
    if(groups.getItem(group_id) == nullptr) {return false;}

    return groups.erase(group_id);
}


template <class T>
uint64_t IdGroup<T>::append(uint64_t group_id, T& i, bool create_group) {
    Group<T>* g;
    if(create_group) {
        g = createGroupIfNotExist(group_id);
    } else {
        g = groups.getItem(group_id);
        if(g == nullptr) {return 0;}
    }
    uint64_t obj_id = g->showNexID();
    IdObj<T> n_obj{i, obj_id, group_id};
    return g->append(n_obj);
}

template <class T>
bool IdGroup<T>::insert(uint64_t group_id, uint64_t id, T& i, bool create_group) {
    Group<T>* g;
    if(create_group) {
        g = createGroupIfNotExist(group_id);
    } else {
        g = groups.getItem(group_id);
    }
    if(g == nullptr) {return false;}

    return g->insert(id, IdObj<T>{i, id, group_id});
}


template <class T>
IdObj<T>* IdGroup<T>::getItem(uint64_t group_id, uint64_t id) {
    Group<T>* g = groups.getItem(group_id);
    if(g == nullptr) {return nullptr;}

    return g->getItem(id);
}


template <class T>
size_t IdGroup<T>::size() {
    size_t acc{0};
    for(auto& g: this->groups) {
        acc += g.second.size();
    }
    return acc;
}

template <class T>
void IdGroup<T>::updateID() {
    if(groups.isEmpty()) {return;}
    for(auto& g: this->groups) {
        g.second.uptadeLastID();
    }
}
