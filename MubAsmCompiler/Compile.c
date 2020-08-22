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

	FILE* outfile =	fopen("x.bin", "wb");
	if (outfile == NULL) {
		printf("Failed to open outputfile");
		return;
	}

	while (!feof(NoCommFile)) {
		struct line line = lineread(NoCommFile);

		int res = ConvToBin(&line, outfile);

		freeline(&line);

		if (res == -1) {
			printf("Failed compilation\n");
			break;
		}
	}

	fclose(InFile);
	fclose(NoCommFile);
	fclose(outfile);
}

//Find all the comments in the input file and output a file without comments
void DeleteComments(FILE* file) {
	FILE* outputfile;
	fopen_s(&outputfile, "NoComm.asm", "w");

	char buffer[256];
	while (1) {
		fgets(buffer, 256, file);
		int pos = 0;
		while (buffer[pos] != '\0') {
			if (buffer[pos] == ';') {//found comment start, revert through line to find last character and put \n behind it
				for (; pos > 0; pos--) {
					if (buffer[pos - 1] != ' ') {
						buffer[pos] = '\n';
						pos++;
						break;
					}
				}
				break;
			}
			pos++;
		}
		fwrite(buffer, 1, pos, outputfile);
		if (feof(file)) {
			fputc('\n', outputfile);
			break;
		}
	}
	fclose(outputfile);
}