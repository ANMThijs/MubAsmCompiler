#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	FILE* InFile = fopen("x.asm", "r");

	char linebuffer[100];

	fgets(linebuffer, 100, InFile);

	printf("%s", linebuffer);

	fclose(InFile);

	return 0;
}