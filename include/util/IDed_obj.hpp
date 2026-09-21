#pragma once
#include <cstdint>
#include <functional>
#include <string>
#include <sstream>

class IDedObj {
    protected:
        uint64_t id;
        uint32_t group;

    public:
        IDedObj(uint64_t id_ = 0, uint64_t group_ = 0):
        id(id_), group(group_) {}


        void setID(uint64_t _id);
        uint64_t getID() const;

        void setGroup(uint32_t _id);
        uint32_t getGroup() const;

        static std::size_t hashID(uint64_t group, uint64_t id);
        std::size_t hashID(); 

};
