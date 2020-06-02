#include "Line.h"

struct line lineread(FILE* file) {
	//Initialize and set memory for the line
	struct line line;

	memset(line.instr, 0, 6);

	memset(line.params, 0, 40);

	//Get a line from the file
	char linebuffer[99] = { 0 };

	fgets(linebuffer, 99, file);

	//used for finding the right buffer for the content
	int location = 0;
	int x = 0;

	int i = 0;
	for (i = 0; i < 99; i++) {
		printf("%c", linebuffer[i]);
		if (linebuffer[i] == '\n') {
			break;
		}
		else if (linebuffer[i] == ' ') {
			location++;
			x = 0;
		}
		else {
			switch (location) {
			case 0:
				line.instr[x] = linebuffer[i];
				break;
			case 1:
				line.params[0][x] = linebuffer[i];
				break;
			case 2:
				line.params[1][x] = linebuffer[i];
				break;
			case 3:
				line.params[2][x] = linebuffer[i];
				break;
			case 4:
				line.params[3][x] = linebuffer[i];
				break;
			}
			x++;
		}
	}
	return line;
}

void freeline(struct line* line) {
	
}