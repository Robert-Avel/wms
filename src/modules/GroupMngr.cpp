#include "GroupMngr.hpp"

#include <cstdint>

uint64_t GroupMngr::newGroup(std::string name) {
    uint64_t id = 1;
    if (g_map.empty()) {
        g_map.insert({name, id});
        return id;
    }
    if(g_map.find(name) != g_map.end()) {return 0;}

    for(auto& pair: g_map) {
        if(pair.second > id) {id = pair.second;}
    }
    g_map.insert({name, ++id});
    return id;
}

bool GroupMngr::eraseGroup(std::string name) {
    auto target = g_map.find(name);
    if(target == g_map.end()) {return false;}
    g_map.erase(target);
    return true;
}
