/*
 * testu01_xoshiro256ss_low32.c
 *
 * Execute TestU01 SmallCrush, Crush and BigCrush on xoshiro256ss (lower 32 bits)
 *
 * xoshiro256** pseudorandom number generator - Copyright(C) D.Blackman & S.Vigna (vigna@acm.org)
 *
 * testu01_xoshiro256ss_low32 - Copyright(C) 2026 Matteo Zapparoli (zapparoli.matteo@gmail.com)
 * 
 * SPDX-License-Identifier: Apache-2.0
 *
 * Compile: gcc -std=c99 -Wall -O3 -o testu01_xoshiro256ss_low32 testu01_xoshiro256ss_low32.c -ltestu01 -lm
 *
 * Sintax:
 *  testu01_xoshiro256ss_low32 [(small | crush | big) <seed> <seed> <seed> <seed>]
 *
 * No args prints help
 *
 */
 
#include <stdio.h>
#include <stdint.h> // uint64_t
#include <inttypes.h> // PRIu64
#include <stdlib.h> // strcmp()
#include <string.h> // strtoull()
#include <errno.h> // errno
#include <ctype.h> // isdigit()

#include "TestU01.h"

/*
 * xoshiro256** PRNG state.
 */
typedef struct {
	uint64_t s[4];
} Xoshiro256ssState;

static Xoshiro256ssState state;

unsigned int xoshiro256ssLow32(void) 
{
	uint64_t result = state.s[1] * 5;
	result = (result << 7) | (result >> 57);
	result *= 9;

	uint64_t t = state.s[1] << 17;

	state.s[2] ^= state.s[0];
	state.s[3] ^= state.s[1];
	state.s[1] ^= state.s[2];
	state.s[0] ^= state.s[3];

	state.s[2] ^= t;
	state.s[3] = (state.s[3] << 45) | (state.s[3] >> 19);

	return (unsigned int)result;
}

// Return 1 id str is not a uint64_t, 0 else
int isnt_valid_uint64(const char *str, uint64_t *out_value)
{
	if (str == NULL || *str == '\0') return 1;

	// Controlla che la stringa contenga solo cifre
	for (const char *p = str; *p; p++) {
		if (!isdigit((unsigned char) *p)) return 1;
	}

	errno = 0;
	char *end;
	unsigned long long v = strtoull(str, &end, 10);

	// end non deve spostarsi oltre la fine
	if (*end != '\0') return 1;

	// Overflow rilevato da errno
	if (errno == ERANGE) return 1;

	// Controllo ulteriore: strtoull potrebbe essere > UINT64_MAX su alcune piattaforme
	if (v > UINT64_MAX) return 1;

	if (out_value) *out_value = (uint64_t)v;

	return 0;
}

void usage(void)
{
	printf("testu01_xoshiro256ss_low32 - Run TestU01 SmallCrush, Crush and BigCrush on xoshiro256** (higher 32 bits)\n\n");
	printf("Usage: testu01_xoshiro256ss_low32 [(small | crush | big) <seed> <seed> <seed> <seed>]\n\n");
	printf("The seeds must be non-zero\n");
}

int main(int argc, char *argv[])
{
	char *test_type;

	if(argc == 1) {
		usage();
		return 0;
	}
	
	if(argc != 6) {
		fprintf(stderr, "*** Error: invalid arguments\n");
		return 1;
	}
	
	if (strcmp(argv[1], "small") == 0) test_type = "small";
	else if (strcmp(argv[1], "crush") == 0) test_type = "crush";
	else if (strcmp(argv[1], "big") == 0) test_type = "big";
	else {
		fprintf(stderr, "*** Error: invalid argument %s\n", argv[1]);
		return 1;
	}
	
	if(isnt_valid_uint64(argv[2], &(state.s[0])) 
		|| isnt_valid_uint64(argv[3], &(state.s[1]))
	    || isnt_valid_uint64(argv[4], &(state.s[2]))
		|| isnt_valid_uint64(argv[5], &(state.s[3]))) {
		fprintf(stderr, "*** Error: invalid arguments\n");
		return 1;
	}
	
	for(int i = 0; i < 4; i++) {
		if(state.s[i] == 0) {
			fprintf(stderr, "*** Error: seeds must be non-zero\n");
			return 1; 
		}
	}

	unif01_Gen *gen = unif01_CreateExternGenBits("xoshiro256ssLow32", xoshiro256ssLow32);

	printf("=== TestU01 - Generator: xoshiro256ssLow32 ===\n");
	for(int i = 0; i < 4; i++) {
		printf("Seed %d: %" PRIu64 "\n", i, state.s[i]);
	}

	if (strcmp(test_type, "small") == 0) {
		bbattery_SmallCrush(gen);
	}
	else if (strcmp(test_type, "crush") == 0) {
		bbattery_Crush(gen);
	}
	else if (strcmp(test_type, "big") == 0) {
		bbattery_BigCrush(gen);
	}

	unif01_DeleteExternGenBits(gen);

	return 0;
}
