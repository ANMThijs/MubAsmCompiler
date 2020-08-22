#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

extern const uint8_t regcounts[3];

extern const char reg8bit[8][3];
extern const char reg16bit[6][3];
extern const char reg32bit[6][4];

extern uint16_t ContrFlags;

struct Register {
	uint8_t width;
	int ID; //Based on the position in the register array
};

bool isRegister(uint8_t* name);

struct Register FillReg(uint8_t* Regname);