#include "Mov.h"

uint8_t Movgetopcode(uint8_t* param) {
	struct Register reg = GetRegWidth(param);

	uint8_t base;
	if (reg.width == 8) {
		base = 0xB0;
	}
	else {
		base = 0xB8;
	}

	return base + reg.ID;
}