#include "Datatypes.h"

void PutData(FILE* file, size_t output, void* data, size_t datasize) {
	if (output >= datasize) {
		char* ptr = (char*)data;
		unsigned char* out = (unsigned char*)calloc(output, 1);

		if (out) {
			for (int i = 0; i < datasize; i++) {
				out[i] = ptr[i];
			}
			for (int i = 0; i < output; i++) {
				printf("%02hhx ", out[i]);
				putc(out[i], file);
			}
			free(out);
		}
	}
}

int isImm(uint8_t* param) {
	int val = 0;
	bool isImm = false;
	if ((param[0] == '0') && (param[1] == 'x')) {
		val = CharToInt(param, 16);
		isImm = true;
	}
	else if ((param[0] == '0') && (param[1] == 'b')) {
		val = CharToInt(param, 2);
		isImm = true;
	}
	else {
		int len = strlen(param);
		for (int i = 0; i < len; i++) {
			if ((param[i] <= 0x30) || (param[i] >= 0x39)) {
				isImm = false;
			}
		}
		val = CharToInt(param, 10);
	}
	
	if (isImm == true) {
		if (val < pow(2, 8)) {
			return 8;
		}
		else if (val < pow(2, 16)) {
			return 16;
		}
		else if (val < pow(2, 32)) {
			return 32;
		}
		else if (val < pow(2, 64)) {
			return 64;
		}
	}
	return -1;
}

bool isNum(uint8_t* param) {
	if ((param[0] == '0') && (param[1] == 'x')) {
		return true;
	}
	else if ((param[0] == '0') && (param[1] == 'b')) {
		return true;
	}
	else {
		int len = strlen(param);
		for (int i = 0; i < len; i++) {
			if ((param[i] <= 0x30) || (param[i] >= 0x39)) {
				return false;
			}
		}
		return true;
	}
}