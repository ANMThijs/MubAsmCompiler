#include "Line.h"

struct line lineread(FILE* file) {
	//Initialize and set memory for the line
	struct line line;
	line.instr = calloc(MAXINSTRLENGTH, sizeof(uint8_t));
	line.params = calloc(MAXPARAMCOUNT, sizeof(uint8_t*));
	for (int i = 0; i < MAXPARAMCOUNT; i++) {
		line.params[i] = calloc(MAXPARAMLENGTH, sizeof(uint8_t));
	}

	//Get a line from the file
	unsigned char linebuffer[256] = { 0 };
	fgets(linebuffer, 256, file);
	while ((linebuffer[0] == '\0') || (linebuffer[0] == '\n')) {
		if (feof(file)) {
			line.instr = "NOP"; //No-op instruction
			return line;
		}
		fgets(linebuffer, 256, file);
	}

	//used for finding the right buffer for the content
	int location = 0;
	int x = 0;

	printf("input:     ");
	for (int i = 0; i < 99; i++) {
		printf("%c", linebuffer[i]);
		if ((linebuffer[i] == '\n') || (linebuffer[i] == '\0')) {
			break;
		}
		else if (linebuffer[i] == ' ') {
			location++;
			x = 0;
		}
		else if (linebuffer[i] != ',') {
			if (location == 0) {
				line.instr[x] = linebuffer[i];
			}
			else {
				line.params[location - 1][x] = linebuffer[i];
			}
			x++;
		}
	}
	line.paramcount = location;

	printf("processed: %s %s %s\n", line.instr, line.params[0], line.params[1]);

	return line;
}

void ConvToBin(struct line* line) {
	if (strcmp(line->instr, "MOV") == 0) {
		line->opcode[0] = Movgetopcode(line->params[0]);
	}
	else if (strcmp(line->instr, "NOP") == 0) {
		line->opcode[0] = 0x90;
		line->paramcount = 0;
	}

	if (line->paramcount > 0) {
		line->paramsbin = GetParams(line->instr, line->params, line->paramcount);
		printf("output:    %02hhx %02hhx\n", line->opcode[0], line->paramsbin[0]);
	}
	else {
		printf("output:    %02hhx\n", line->opcode[0]);
	}
}

void freeline(struct line* line) {
	for (int i = 0; i < MAXPARAMCOUNT; i++) {
		free(line->params[i]);
	}
	free(line->params);
}