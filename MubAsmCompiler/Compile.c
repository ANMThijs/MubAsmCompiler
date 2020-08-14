#include "Compile.h"

void Compile(const char* Filename) {
	FILE* InFile;
	fopen_s(&InFile, "x.asm", "r");
	if (InFile == NULL) {
		printf("Failed to open file");
		return;
	}

	while (!feof(InFile)) {
		struct line line = lineread(InFile);

		ConvToBin(&line);

		freeline(&line);
	}

	fclose(InFile);
}