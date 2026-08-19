#include <cstdint>
class IDedObj {
    uint64_t* id;
    uint32_t* group;

    public:
        IDedObj(): id(nullptr) {}
        ~IDedObj();


        bool clearID();
        bool setID(uint64_t _id);
        uint64_t* getID();

        bool clearGroup();
        bool setGroup(uint32_t _id);
        uint32_t* getGroup();
};
