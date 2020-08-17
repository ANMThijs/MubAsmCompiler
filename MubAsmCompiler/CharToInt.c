#include "CharToInt.h"

int CharToInt(uint8_t* string) {
	int stringsize = strlen(string);

	int ret = 0;

	for (int i = 2; i < stringsize; i++) {
		int inv = stringsize - i - 1;
		int x = string[i];
		if ((string[i] > 0x2F) && (string[i] < 0x3A)) {
			x -= 0x30;
		}
		//Capital A-F
		else if ((string[i] > 0x40) && (string[i] < 0x47)) {
			x -= 0x37;
		}
		//Lowercase a-f
		else if ((string[i] > 0x60) && (string[i] < 0x67)) {
			x -= 0x57;
		}
		ret += x * pow(16, inv);
	}

	return ret;
}