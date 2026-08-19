#pragma once
#include <cstdint>
#include <string>

enum Status {
    SUCCESS,
    NOT_FOUND,
    ALREADY_EXIST,
    INPUT_ERROR,
    OUT_OF_RANGE,
    FULL,
    NOT_SELECTED
};


typedef uint64_t bruteID;
typedef std::string TextID;
