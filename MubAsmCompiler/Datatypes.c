#include "Datatypes.h"

uint8_t paramtypes[7][12] = {
	"r8",
	"r16_32_64",
	"r_m8",
	"r_m16_32_64",
	"imm8",
	"imm16_32",
	"imm16_32_64",
};

char GetDataWidth(uint64_t param) {

}

struct Register GetRegWidth(uint8_t* Regname) {
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

	ret.name = malloc(len * sizeof(uint8_t));
	strcpy(ret.name, Regname);

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

void CleanReg(struct Register* reg) {
	free(reg->name);
}

int GetParamType(uint8_t* param) {
	for (int i = 0; i < PARAM_TYPE_COUNT; i++) {
		if (strcmp(param, paramtypes[i]) == 0) {
			return i;
		}
	}
}