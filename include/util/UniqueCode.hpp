#include <cstdint>
#include <string>
#include <utility>
typedef uint64_t UniqueID;
typedef uint64_t GroupID;

namespace UniC {
    typedef std::string UniqueCode;

    std::pair<GroupID, UniqueID> strToPair(UniqueCode code);
    UniqueCode pairToStr(std::pair<GroupID, UniqueID> code);
}
