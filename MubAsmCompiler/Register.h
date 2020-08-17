#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

extern const char datareg8bit[8][3];
extern const char datareg16bit[4][3];
extern const char datareg32bit[4][4];

extern const char pointreg16bit[3][3];
extern const char pointreg32bit[3][4];

extern const char segreg16bit[6][3];

extern uint16_t ContrFlags;

//Returns -1 if it's not a register, otherwise returns 8/16/32 for the bits
int GetRegister(uint8_t* reg);