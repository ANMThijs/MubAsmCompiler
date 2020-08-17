#include "Register.h"

const char datareg8bit[8][3] = {
	"AL", "CL", "DL", "BL",
	"AH", "CH", "DH", "BH"
};

const char datareg16bit[4][3] = {
	"AX", "BX", "CX", "DX"
};

const char datareg32bit[4][4] = {
	"EAX", "EBX", "ECX", "EDX"
};

const char pointreg16bit[3][3] = {
	"IP", "SP", "BP"
};

const char pointreg32bit[3][4] = {
	"EIP", "ESP", "EBP"
};

extern const char segreg16[6][3] = {
	"CS", "DS", "ES", "FS", "GS", "SS",
};