#include "IDed_map.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>


template <class T>
class GroupMap {
    IDedMap<IDedMap<T>> groups;

    IDedMap<T>* createGroupIfNotExist(uint64_t group_id);
    public:
        GroupMap<T>() = default;

        IDedMap<T>* getGroup(uint64_t group_id);

        bool newGroup(uint64_t id);
        uint64_t newGroup();

        bool removeGroup(uint64_t group_id);

        uint64_t append(uint64_t group_id, T& i, bool create_group = false);
        bool insert(uint64_t group_id, uint64_t id, T& i,  bool create_group = false);


        size_t size();
};
