#include "Mov.h"

uint8_t Movgetopcode(uint8_t* param1) {
	//char used as a boolean
	char memaddr = 0;
	if (param1[0] == '[') {
		memaddr = 1;
	}

	if (memaddr == 0) {
		if ((strcmp(param1, "AL\0") == 0)) {
			return 0xB0;
		}
	}
}