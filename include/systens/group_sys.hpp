#pragma once
#include "group.hpp"
#include "GroupPrefixMap.hpp"
#include "WMSData.hpp"

class GroupSys {
    WMSData& gpm;

    public:
    GroupSys(WMSData& gpm_): gpm(gpm_) {}

    uint64_t newGroup(std::string name);
    uint64_t* getGroupID(std::string name);
    GroupPrefixMap& getGroups() const;
    bool deleteGroup(std::string name);
};
