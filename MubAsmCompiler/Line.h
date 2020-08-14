#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mov.h"
#include "Params.h"

#define MAXINSTRLENGTH 6
#define MAXPARAMCOUNT 4
#define MAXPARAMLENGTH 10

struct line {
	uint8_t* instr;
	uint8_t** params;
	uint8_t paramcount;

	uint8_t opcode[2];
	uint8_t* paramsbin;
};

struct line lineread(FILE* file);

void ConvToBin(struct line* line);

void freeline(struct line* line);