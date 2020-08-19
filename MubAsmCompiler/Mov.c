#include "Mov.h"

uint8_t* Movgetopcode(uint8_t* param, int* opcodewidth) {
	struct Register reg = GetRegWidth(param);

	*opcodewidth = 1;

	uint8_t* opc = malloc(2 * sizeof(uint8_t));
	if (reg.width == 8) {
		opc[0] = 0xB0 + reg.ID;
	}
	else {
		opc[0] = 0xB8 + reg.ID;
		if (reg.width == 32) {
			opc[1] = opc[0];
			opc[0] = 0x66;
			*opcodewidth = 2;
		}
	}

	return opc;
}