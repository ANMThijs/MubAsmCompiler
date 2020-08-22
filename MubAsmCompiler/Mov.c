#include "Mov.h"

uint8_t* Movgetopcode(uint8_t* param, size_t* paramwidth, int* opcodewidth) {
	struct Register reg = FillReg(param);

	*opcodewidth = 1;

	uint8_t* opc = malloc(2 * sizeof(uint8_t));
	if (reg.width == 8) {
		opc[0] = 0xB0 + reg.ID;
		*paramwidth = 1;
	}
	else {
		opc[0] = 0xB8 + reg.ID;
		*paramwidth = 2;
		if (reg.width == 32) {
			opc[1] = opc[0];
			opc[0] = 0x66;
			*opcodewidth = 2;
			*paramwidth = 4;
		}
	}

	return opc;
}