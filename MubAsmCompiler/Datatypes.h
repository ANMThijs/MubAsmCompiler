#pragma once
#include <stdint.h>

//Returns 8/16/32/64
uint8_t GetDataWidth(uint64_t param);
uint8_t GetRegWidth(char* Regname);