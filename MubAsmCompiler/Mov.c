#include "Mov.h"

uint8_t Movgetopcode(uint8_t* param1) {
	//char used as a boolean
	uint8_t memaddr = 0;
	if (param1[0] == '[') {
		memaddr = 1;
	}

	if (memaddr == 0) {
		for (int i = 0; i < 8; i++) {
			if (strcmp(param1, datareg8bit[i]) == 0) {
				return 0xB0 + i;
			}
		}
	}
}