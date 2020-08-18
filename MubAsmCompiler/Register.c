#include "Register.h"

extern const uint8_t regcounts[3] = {
	8, 6, 6
};

const char reg8bit[8][3] = {
	"AL", "CL", "DL", "BL",
	"AH", "CH", "DH", "BH"
};

const char reg16bit[6][3] = {
	"AX", "BX", "CX", "DX", "SP", "BP"
};

const char reg32bit[6][4] = {
	"EAX", "EBX", "ECX", "EDX", "ESP", "EBP"
};