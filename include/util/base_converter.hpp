#pragma once

#include <cstdint>
#include <string>



static const char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char digit_alphabetic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool checkDigit(std::string code, uint8_t base, bool has_numbers);

static std::string convert(uint64_t value, uint8_t base, const char* using__);


std::string intToBase(uint64_t value, uint8_t base = 36);
std::string intToAlphabetic(uint32_t value, uint8_t base = 26);
uint64_t BaseToInt(std::string code, uint8_t base, bool has_numbers);
