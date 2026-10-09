#ifndef GROUP_MNGR_HPP
#define GROUP_MNGR_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include "IdGroup.hpp"
using StrMap = std::unordered_map<std::string, uint64_t>;

class GroupMngr {

    StrMap& g_map;

    public:
        GroupMngr(StrMap& data): g_map(data) {}

        auto& getMap() const {return  g_map;}

        uint64_t newGroup(std::string name);
        bool eraseGroup(std::string name);

        template<class T>
        void syncGroup(IdGroup<T>& group) {
            for(auto& pair: g_map) {
                group.newGroup(pair.second);
            }
        }
};

#endif
