#pragma once
#pragma warning(disable: 4996)

#include <stdint.h>
#include "Register.h"

#define PARAM_TYPE_COUNT 7

extern uint8_t paramtypes[PARAM_TYPE_COUNT][12];

//Returns 8/16/32/64 if found and -1 if there's an error
char GetDataWidth(uint64_t param);
struct Register GetRegWidth(uint8_t* Regname);
void CleanReg(struct Register* reg);

//Returns position in paramtypes array
int GetParamType(uint8_t* param);