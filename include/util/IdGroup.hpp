#ifndef ID_GROUP_HPP
#define ID_GROUP_HPP

#include "IdMap.hpp"
#include "IdObj.hpp"
#include <cstdint>


template <typename T>
using _Group = IdMap<IdObj<T>>;

template <typename T>
using _Mmap = IdMap<_Group<T>>;

template <class T>
class IdGroup {
    _Mmap<T> groups;

    IdObj<T> newObj(_Group<T>& group);
    _Group<T>* createGroupIfNotExist(uint64_t group_id);
    public:
        IdGroup() = default;

        _Group<T>* getGroup(uint64_t group_id);

        bool newGroup(uint64_t id);
        uint64_t newGroup();

        bool removeGroup(uint64_t group_id);

        uint64_t append(uint64_t group_id, T& i, bool create_group = true);
        bool insert(uint64_t group_id, uint64_t id, T& i,  bool create_group = true);

        IdObj<T>* getItem(uint64_t group_id, uint64_t id);

        auto begin() { return groups.begin(); }
        auto end() { return groups.end(); }

        size_t size();
        size_t sizeMap() {return groups.size();}
        bool isEmpty() {return groups.isEmpty();}
        void updateID();
};

#include "src/util/IdGroup.tpp"

#endif
