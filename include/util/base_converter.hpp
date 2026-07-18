#include <cstdint>
#include <string>

static const char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static const char digit_alphabetic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static std::string convert(uint32_t value, uint8_t base, const char* using__);

std::string intToBase(uint32_t value, uint8_t base = 36);
std::string intToAlphabetic(uint32_t value, uint8_t base = 26);
