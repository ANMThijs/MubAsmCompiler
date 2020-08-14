#include "Params.h"

uint8_t* GetParams(uint8_t* instr, uint8_t** param, uint8_t paramcount) {
	uint8_t paramsbin[1] = { 0 };

	if ((param[1][0] == '0') && (param[1][1] == 'x')) {
		paramsbin[0] = CharToInt(param[1]);
	}

	return paramsbin;
}