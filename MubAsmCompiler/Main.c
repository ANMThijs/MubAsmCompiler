#pragma warning(disable:4996)

#include "Line.h"

int main(int argc, char** argv) {
	FILE* InFile = fopen("x.asm", "r");

	struct line line = lineread(InFile);

	printf("%s %s %s", line.instr, line.params[0], line.params[1]);

	freeline(&line);

	fclose(InFile);

	return 0;
}