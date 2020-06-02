#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
	char instr[6];
	char params[4][10];

	int* opcode;
	int* paramsbin;
};

struct line lineread(FILE* file);

void freeline(struct line* line);