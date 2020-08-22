#pragma once
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "Register.h"
#include "Datatypes.h"

uint8_t* Movgetopcode(uint8_t* param, size_t* paramwidth, int* opcodewidth);