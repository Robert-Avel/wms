#ifndef ID_GROUP_HPP
#define ID_GROUP_HPP

#include "IdMap.hpp"
#include "IdObj.hpp"
#include <cstdint>


template <typename T>
using Group = IdMap<IdObj<T>>;

template <typename T>
using Mmap = IdMap<Group<T>>;

template <class T>
class IdGroup {
    Mmap<T> groups;

    IdObj<T> newObj(Group<T>& group);
    Group<T>* createGroupIfNotExist(uint64_t group_id);
    public:
        IdGroup() = default;

        Group<T>* getGroup(uint64_t group_id);

        bool newGroup(uint64_t id);
        uint64_t newGroup();

        bool removeGroup(uint64_t group_id);

        uint64_t append(uint64_t group_id, T& i, bool create_group = false);
        bool insert(uint64_t group_id, uint64_t id, T& i,  bool create_group = false);

        IdObj<T>* getItem(uint64_t group_id, uint64_t id);

        auto begin() { return groups.begin(); }
        auto end() { return groups.end(); }

        size_t size();
        bool isEmpty() {return groups.isEmpty();}
        void updateID();
};

#include "src/util/IdGroup.tpp"

#endif
