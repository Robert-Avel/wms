#include "group_sys.hpp"


uint64_t GroupSys::newGroup(std::string name) {
    if(gpm.empty()) {
        gpm.insert({name, 1});
        return 1;
    }

    if(gpm.find(name) != gpm.end()) {return 0;}

    uint64_t id = 0;
    auto it = gpm.begin();
    while (it != gpm.end())
    {
        if(id < it->second) {id = it->second;}
        it++;
    }
    gpm.insert({name, ++id});
    return id;
}

uint64_t* GroupSys::getGroupID(std::string name) {
    return gpm.translateGName(name);
}

GroupPrefixMap& GroupSys::getGroups() const {
    return gpm;
}

bool GroupSys::deleteGroup(std::string name) {
    if(gpm.empty()) {return false;}

    auto target = gpm.find(name);
    if(target == gpm.end()) {return false;}
    else {gpm.erase(target);}
    return true;
}
