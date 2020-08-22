#include "Line.h"

struct line lineread(FILE* file) {
	//Initialize and set memory for the line
	struct line line;
	line.instr = calloc(MAXINSTRLENGTH, sizeof(uint8_t));
	line.params = calloc(MAXPARAMCOUNT, sizeof(uint8_t*));
	line.paramtypes = calloc(MAXPARAMCOUNT, sizeof(int));
	line.paramswidth = malloc(MAXPARAMCOUNT * sizeof(size_t));
	for (int i = 0; i < MAXPARAMCOUNT; i++) {
		line.params[i] = calloc(MAXPARAMLENGTH, sizeof(uint8_t));
	}

	line.opcode = malloc(2 * sizeof(uint8_t));
	line.opcodewidth = 1;

	//Get a line from the file
	uint8_t linebuffer[256] = { 0 };
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
	for (int i = 0; i < 256; i++) {
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

int ConvToBin(struct line* line, FILE* outfile) {
	FILE* ocfile;
	fopen_s(&ocfile, "OpcodesOneByte.txt", "r");
	if (ocfile == NULL) {
		printf("Failed to find opcodes\n");
		return;
	}

	while (!feof(ocfile)) {
		//Get the instruction from the file
		uint8_t readparamcount = 0;
		uint8_t buff[7], linebuff[64], params[4][12] = { 0 };
		for (int i = 0; i < 7; i++) {
			uint8_t c = fgetc(ocfile);
			buff[i] = c == ' ' ? '\0' : c; //0x20 is ascii code of space
		}
		
		if (strcmp(line->instr, buff) == 0) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 12; j++) {
					unsigned char c = fgetc(ocfile);
					if (c == ' ') {
						if (j > 0) {
							readparamcount++;
						}
						int pos = ftell(ocfile);
						pos += 11 - j;
						fseek(ocfile, pos, 0L);
						break;
					}
					else {
						params[i][j] = c;
					}
				}
				line->paramtypes[i] = GetParamType(params[i]);
			}
			line->paramcount = readparamcount;
			
			if (!ParamCmp(params[0], line->params[0])) {
				return -1;
			}

			uint8_t opc[5];
			for (int i = 0; i < 4; i++) {
				opc[i] = fgetc(ocfile);
			}
			opc[4] = '\0';
			line->opcode[0] = CharToInt(opc);
			GetParams(line);

			printf("Output: ");
			for (int i = 0; i < line->opcodewidth; i++) {
				PutData(outfile, sizeof(uint8_t), &line->opcode[i], sizeof(uint8_t));
			}
			for (int i = 0; i < line->paramsbincount; i++) {
				PutData(outfile, line->paramswidth[i], &line->paramsbin[i], sizeof(uint8_t));
			}
			printf("\n");
		}
		else {
			fgets(linebuff, 64, ocfile);
		}
	}
	fclose(ocfile);

	return 0;
}

void GetParams(struct line* line) {
	uint8_t getparamcount = 0;
	line->paramsbin = calloc(line->paramcount, sizeof(uint8_t)); //Wastes some memory

	for (int i = 0; i < line->paramcount; i++) {
		if (line->paramtypes[i] < 4) {
			if (strcmp(line->instr, "MOV") == 0) {
				line->opcode = Movgetopcode(line->params[i], &line->paramswidth[i], &line->opcodewidth);
			}
		}
		if ((line->params[i][0] == '0') && (line->params[i][1] == 'x')) {
			line->paramsbin[getparamcount] = CharToInt(line->params[i]);
			line->paramswidth[i] = 1;
			getparamcount++;
		}
	}

	line->paramsbincount = getparamcount;
}

void freeline(struct line* line) {
	for (int i = 0; i < MAXPARAMCOUNT; i++) {
		free(line->params[i]);
	}
	free(line->params);
	free(line->paramtypes);
	free(line->paramswidth);
	free(line->opcode);
}