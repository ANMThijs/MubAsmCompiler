#pragma warning(disable:4996)

#include "RandomInt.h"
#include "Compile.h"

int main(int argc, char** argv) {
	Compile("x.asm");

	int x = GenRandInt(0, 10000);
	if (x == 321) {
		printf("\n\nYou're doing a great job, keep going!\n");
	}

	return 0;
}