#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mov.h"
#include "Parameters.h"

#define MAXINSTRLENGTH 6
#define MAXPARAMCOUNT 4
#define MAXPARAMLENGTH 11

struct line {
	uint8_t* instr;
	uint8_t** params;
	uint8_t paramcount;
	int* paramtypes;

	uint8_t* opcode;
	int opcodewidth;
	uint8_t* paramsbin;
	size_t* paramswidth;
	uint8_t paramsbincount;
};

struct line lineread(FILE* file);

void ConvToBin(struct line* lin, FILE* outfile);

void freeline(struct line* line);

void GetParams(struct line* line);