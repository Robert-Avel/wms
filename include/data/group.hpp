#include "IDed_map.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>

template <class T>
class GroupMap {
    IDedMap<IDedMap<T>> groups;
    std::unordered_map<std::string, uint64_t> prefixs;

    public:
        GroupMap<T>();

        IDedMap<T>* getGroup(uint64_t group_id);
        IDedMap<T>* getGroup(std::string prefix);

        bool newGroup(std::string prefix);

        bool removeGroup(std::string prefix);
        bool removeGroup(uint64_t group_id);
};
