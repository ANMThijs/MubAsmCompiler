#pragma once
#include "CharToInt.h"
#include "Datatypes.h"
#include "Register.h"

#define PARAM_TYPE_COUNT 12

extern uint8_t paramtypes[PARAM_TYPE_COUNT][5];

bool ParamCmp(uint8_t* expected, uint8_t* param);

//Returns position in paramtypes array
int GetParamType(uint8_t* param);