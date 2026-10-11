#include <cstdint>
#include <string>
#include <utility>
typedef uint64_t UniqueID;
typedef uint64_t GroupID;


namespace UniqueCode {
    std::pair<GroupID, UniqueID> strToPair(std::string code);
}
