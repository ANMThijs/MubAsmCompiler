#include "Compile.h"

void Compile(const char* Filename) {
	FILE* InFile;
	fopen_s(&InFile, "x.asm", "r");
	if (InFile == NULL) {
		printf("Failed to open file");
		return;
	}

	DeleteComments(InFile);

	FILE* NoCommFile;
	fopen_s(&NoCommFile, "NoComm.asm", "r");
	if (NoCommFile == NULL) {
		printf("Failed deleting comments");
		return;
	}

	while (!feof(NoCommFile)) {
		struct line line = lineread(NoCommFile);

		ConvToBin(&line);

		freeline(&line);
	}

	fclose(InFile);
	fclose(NoCommFile);
}

void DeleteComments(FILE* file) {
	FILE* outputfile;
	fopen_s(&outputfile, "NoComm.asm", "w");

	char buffer[256];
	while (!feof(file)) {
		fgets(buffer, 256, file);

		int i = 0;
		while (buffer[i] != '\0') {
			if (buffer[i] == ';') {
				buffer[i] = '\n';
				i++;
				break;
			}
			i++;
		}
		fwrite(buffer, 1, i, outputfile);
	}
	fclose(outputfile);
}