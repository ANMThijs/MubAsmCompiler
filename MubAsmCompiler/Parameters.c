#include "Parameters.h"

uint8_t paramtypes[PARAM_TYPE_COUNT][5] = {
	"r8",
	"r16",
	"r32",
	"r64"
	"m8",
	"m16",
	"m32",
	"m64",
	"imm8",
	"imm16",
	"imm32",
	"imm64",
};

bool ParamCmp(uint8_t* expected, uint8_t* param) {
	char* pEnd;
	if (expected[0] == 'r') {
		if (!isRegister(param)) {
			printf("Expected register, did not recieve register\n");
			return false;
		}
	}
	else if (expected[0] == 'i') {
		int width = isImm(param);
		int exp = CharToInt(&expected[3], 16);
		if (exp != width) {
			printf("Inconsistent data width, expected: %i, recieved: %i", exp, width);
			return false;
		}
	}
	else if (isNum(expected)) {
		int val1 = CharToInt(expected, 16);
		int val2 = CharToInt(param, 16);
		if (val1 != val2) {
			return false;
		}
	}
	return true;
}

int GetParamType(uint8_t* param) {
	for (int i = 0; i < PARAM_TYPE_COUNT; i++) {
		if (strcmp(param, paramtypes[i]) == 0) {
			return i;
		}
	}
	if (isRegister(param) == 1) {
		struct Register reg = FillReg(param);
		switch (reg.width) {
		case 8: return 0;
		case 16: return 1;
		case 32: return 2;
		}
	}
	else if (isImm(param)) {
		int s = CharToInt(param, 16);
		if (s < pow(2, 8)) {
			return 8;
		}
		else if (s < pow(2, 16)) {
			return 16;
		}
		else if (s < pow(2, 32)) {
			return 32;
		}
		else if (s < pow(2, 64)) {
			return 64;
		}
	}
	return -1;
}