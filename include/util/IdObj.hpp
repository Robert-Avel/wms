#ifndef ID_OBJ_HPP
#define ID_OBJ_HPP


#include <cstdint>
#include <functional>

template <class T>
class IdObj {
    protected:
        uint64_t id;
        uint64_t group;
        T inner;

    public:
        IdObj<T>(T obj, uint64_t id_ = 0, uint64_t group_ = 0):
        id(id_), group(group_), inner(obj) {}

        const T& cgetObj() const {return inner;}
        T& getObj() {return inner;}

        void setID(uint64_t _id) {id =_id;}
        const uint64_t& getID() const {return id;}

        void setGroup(uint64_t _id) {group = _id;}
        const uint64_t& getGroup() const {return group;}

        static std::size_t hashID(uint64_t group, uint64_t id) {
            // Combinação bitwise — sem alocação, sem formatação
            std::size_t h1 = std::hash<uint64_t>{}(group);
            std::size_t h2 = std::hash<uint64_t>{}(id);
            // boost::hash_combine idiom
            return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
        }
        std::size_t hashID() {
            return hashID(this->group, this->id);
        }

};

#endif
