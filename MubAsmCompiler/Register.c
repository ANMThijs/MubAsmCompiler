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

bool isRegister(uint8_t* name) {
	for (int i = 0; i < 8; i++) {
		if (strcmp(name, reg8bit[i]) == 0) {
			return true;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (strcmp(name, reg16bit[i]) == 0) {
			return true;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (strcmp(name, reg32bit[i]) == 0) {
			return true;
		}
	}

	return false;
}

struct Register FillReg(uint8_t* Regname) {
	struct Register ret;
	int len = strlen(Regname);

	int index = 0;
	if (len == 2) {
		if ((Regname[1] == 'L') || (Regname[1] == 'H')) {
			ret.width = 8;
		}
		else if ((Regname[1] == 'X') || (Regname[1] == 'S')) {
			ret.width = 16;
			index = 1;
		}
	}
	else if (len == 3) {
		ret.width = 32;
		index = 2;
	}

	for (int i = 0; i < regcounts[index]; i++) {
		if (index == 0) {
			if (strcmp(reg8bit[i], Regname) == 0) {
				ret.ID = i;
			}
		}
		else if (index == 1) {
			if (strcmp(reg16bit[i], Regname) == 0) {
				ret.ID = i;
			}
		}
		else if (index == 2) {
			if (strcmp(reg32bit[i], Regname) == 0) {
				ret.ID = i;
			}
		}
	}
	return ret;
}