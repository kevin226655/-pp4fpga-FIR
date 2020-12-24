
#include "stdio.h"

#define NUM_TAPS 11
void fir(int input, int *output);

const int SIZE = 256;

int main() {
	int out = 0;
	for (int i = 0; i < SIZE; i++) {
		fir(i, &out);
	}
	printf("result = %d\n", out);
	if (out == -483) {
		return 0;
	} else {
		return 1;
	}
}
