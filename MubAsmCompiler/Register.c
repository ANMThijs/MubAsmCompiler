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

extern const char segreg16bit[6][3] = {
	"CS", "DS", "ES", "FS", "GS", "SS",
};

int GetRegister(uint8_t* reg) {
	int len = strlen(reg);
	if (len == 2) {
		if ((reg[1] == 'L') || (reg[1] == 'H')) {
			return 8;
		}
		else if ((reg[1] == 'X') || (reg[1] == 'S')) {
			return 16;
		}
	}
	else if(len == 3) {
		return 32;
	}
	return -1;
}