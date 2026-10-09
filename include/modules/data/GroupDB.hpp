#ifndef GROUP_DATA_BASE_HPP
#define GROUP_DATA_BASE_HPP

#include "GroupMngr.hpp"
#include <fstream>
#include <optional>


class GroupDB {
    public:
    bool saveFile(const std::pair<std::string, uint64_t>& obj, std::ofstream& file);
    std::optional<std::pair<std::string, uint64_t>> loadFile(std::ifstream& file);

    StrMap data;

    GroupDB() = default;

    void saveAllFile(std::ofstream& file);
    bool loadAllFile(std::ifstream& file, size_t d_size);
};

#endif
