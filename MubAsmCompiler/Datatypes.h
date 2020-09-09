#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdint.h>

#include "Register.h"
#include "CharToInt.h"

//Sizes in bytes, so 1/2/4/8
void PutData(FILE* file, size_t output, void* data, size_t datasize);

int isImm(uint8_t* param);

bool isNum(uint8_t* param);