#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "CharToInt.h"

uint8_t* GetParams(uint8_t* instr, uint8_t** param, uint8_t paramcount);