#include "UniqueCode.hpp"
#include "util.hpp"
#include <cctype>
#include <cstdlib>
#include <string>
#define SEPARATOR '.'


std::pair<GroupID, UniqueID> UniC::strToPair(std::string code) {
    auto final = StrUtil::split(code, SEPARATOR);
    if (final.size() != 2) {return {0, 0};}

    for(auto& str: final) {
        if (!basec::checkDigit(str, basec::NUMERIC, true)) {
            return {0, 0};
        }
    }
    return {atol(final[0].c_str()), atol(final[1].c_str())};
}

UniC::UniqueCode UniC::pairToStr(std::pair<GroupID, UniqueID> code) {
    std::string output;
    output
        .append(std::to_string(code.first))
        .append(".", 1)
        .append(std::to_string(code.second));
    return output;
}
