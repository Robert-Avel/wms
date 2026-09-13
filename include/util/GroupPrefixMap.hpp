#include <unordered_map>
#include <string>
#include <cstdint>

class GroupPrefixMap: public std::unordered_map<std::string, uint64_t> {
    public:
    uint64_t* translateGName(std::string name);
};