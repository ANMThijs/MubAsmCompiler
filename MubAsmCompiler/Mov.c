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
		else if ((strcmp(param1, "CL\0") == 0)) {
			return 0xB1;
		}
		else if ((strcmp(param1, "DL\0") == 0)) {
			return 0xB2;
		}
		else if ((strcmp(param1, "BL\0") == 0)) {
			return 0xB3;
		}
		else if ((strcmp(param1, "AH\0") == 0)) {
			return 0xB4;
		}
		else if ((strcmp(param1, "CH\0") == 0)) {
			return 0xB5;
		}
		else if ((strcmp(param1, "DH\0") == 0)) {
			return 0xB6;
		}
		else if ((strcmp(param1, "BH\0") == 0)) {
			return 0xB7;
		}
	}
}