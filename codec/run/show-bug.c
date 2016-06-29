#include <stdio.h>
#include "codec.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	struct codec codec;
	struct for_delta_args args;
	uint32_t res;
	uint32_t input_arr[2];
	uint32_t enc_arr[2];
	uint32_t check_arr[2];

	input_arr[0] = 0;
	input_arr[1] = 0x80000000;

	memset(enc_arr, 0, sizeof(int) * 2);
	memset(check_arr, 0, sizeof(int) * 2);
	codec.method = CODEC_FOR_DELTA;
	codec.args = &args;

	res = codec_compress(&codec, input_arr, 2, (int*)enc_arr);
	printf("compressing 2 integers into %u bytes...\n", res);

	codec_decompress(&codec, (int*)enc_arr, check_arr, 2);

	printf("input_arr: %x %x\n", input_arr[0], input_arr[1]);
	printf("check_arr: %x %x\n", check_arr[0], check_arr[1]);

	return 0;
}
