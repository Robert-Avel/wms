#include "group_sys.hpp"


uint64_t GroupSys::newGroup(std::string name) {
    gpm.loadGroupMap();
    if(gpm.group_translation.translateGName(name) != nullptr) {return 0;}
    if(gpm.group_translation.empty()) {
        gpm.group_translation.insert({name, 1});
        return 1;
    }

    uint64_t id = 0;
    for(auto& it: gpm.group_translation) {
        if(id < it.second) {id = it.second;}
    }

    gpm.group_translation.insert({name, ++id});
    gpm.saveGroupMap(id, name);
    return id;
}

uint64_t* GroupSys::getGroupID(std::string name) {
    return gpm.group_translation.translateGName(name);
}

GroupPrefixMap& GroupSys::getGroups() const {
    gpm.loadGroupMap();
    return gpm.group_translation;
}

bool GroupSys::deleteGroup(std::string name) {
    gpm.loadGroupMap();
    if(gpm.group_translation.empty()) {return false;}

    auto target = gpm.group_translation.find(name);
    if(target == gpm.group_translation.end()) {return false;}
    else {
        gpm.group_translation.erase(target);
    }
    return true;
}
