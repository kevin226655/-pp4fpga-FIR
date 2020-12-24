#define NUM_TAPS 11

void fir(int input, int *output)
{
	static int delay_line[NUM_TAPS] = {};
	int taps[] = {1, 2, 0, -3, 0, 4, -5, 0, 1, -2, 0, -3, 0, 4, -5, 0};
	int result = 0;
	for (int i = NUM_TAPS - 1; i > 0; i--) {
pragma HLS UNROLL
		delay_line[i] = delay_line[i - 1];
	}
	delay_line[0] = input;

	for (int i = 0; i < NUM_TAPS; i++) {
pragma HLS PIPELINE II=1
		result += delay_line[i] * taps[i];
	}

	*output = result;
}
