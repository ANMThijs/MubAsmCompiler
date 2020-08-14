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
	uint8_t linebuffer[99] = { 0 };
	fgets(linebuffer, 99, file);

	//used for finding the right buffer for the content
	int location = 0;
	int x = 0;

	printf("input:     ");
	for (int i = 0; i < 99; i++) {
		printf("%c", linebuffer[i]);
		if (linebuffer[i] == '\n') {
			break;
		}
		else if (linebuffer[i] == ' ') {
			location++;
			x = 0;
		}
		else if (linebuffer[i] == ',') {
			//skip this character
		}
		else {
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
	line->opcode[0] = Movgetopcode(line->params[0]);
	line->paramsbin = GetParams(line->instr, line->params, line->paramcount);

	printf("output:    %02hhx %02hhx", line->opcode[0], line->paramsbin[0]);
}

void freeline(struct line* line) {
	for (int i = 0; i < MAXPARAMCOUNT; i++) {
		free(line->params[i]);
	}
	free(line->params);
}