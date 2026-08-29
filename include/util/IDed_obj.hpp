#include <cstdint>
class IDedObj {
    protected:
        uint64_t id;
        uint32_t group;

    public:
        IDedObj(uint64_t id_ = 0, uint64_t group_ = 0):
        id(id_), group(group_) {}


        void setID(uint64_t _id);
        uint64_t getID();

        void setGroup(uint32_t _id);
        uint32_t getGroup();
};
